#include <iostream>
#include "Shape.h"
#include <time.h>

using namespace std;

// 
Shape** return_arr(int& fit_size)
{
	// 初始化随机种子
	srand(time(0));

	const int arrSize = 20;
	Shape* shapeArr[arrSize];
	for (int i = 0; i < 10; ++i) {
		// 生成随机数组
		int randNum[9];
		for (int j = 0; j < 9; ++j) {
			randNum[j] = rand()%10+1;
		}

		// Rectangle
		Rectangle* rec = new Rectangle(randNum[0], randNum[1], randNum[2], Point(randNum[3], randNum[4]));
		shapeArr[i*2] = rec;

		// Circle
		Circle* cir = new Circle(randNum[5], randNum[6], Point(randNum[7], randNum[8]));
		shapeArr[i*2+1] = cir;
	}

	// 删除 area 小于50的
	fit_size = arrSize;
	for (int i = 0; i < arrSize; ++i) {
		if (shapeArr[i]->getArea() < 50) {
			delete shapeArr[i];
			shapeArr[i] = NULL;
			--fit_size;
		}
	}

	// 新数组
	// Shape* newShapeArr[fit_size];
	Shape** newShapeArr = new Shape*[fit_size];
	int cnt = 0;
	for (int i = 0; i < arrSize; ++i) {
		if (shapeArr[i]) {
			newShapeArr[cnt++] = shapeArr[i];
		}
	}

	return newShapeArr;

}

int main()
{
	auto time1 = clock();

	int fit_size = 0;
	Shape** newShapeArr = return_arr(fit_size);

	for (int i = 0; i < fit_size; ++i) {
		cout << newShapeArr[i]->getArea() << endl;
	}


	// delete newShapeArr;
	for (int i = 0; i < fit_size; ++i) {
		if (newShapeArr[i]) {
			delete newShapeArr[i];
			newShapeArr[i] = NULL;
		}
	}
	delete[] newShapeArr;

	auto time2 = clock();

	cout << "time = " << time2 - time1 << endl;

	return 0;
}