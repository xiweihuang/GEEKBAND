#include <iostream>
#include "Shape.h"
#include <memory>
#include <vector>
#include <time.h>

using namespace std;

// vector<Shape*>& getShapeAreaArr()
// {
// 	srand(time(0));

// 	vector<Shape*> shapeArr;
// 	for (int i = 0; i < 10; ++i) {
// 		int randNum[9];
// 		for (int j = 0; j < 9; ++j) {
// 			randNum[j] = rand()%10+1;
// 		}
// 		// shapeArr.push_back(Rectangle(randNum[0], randNum[1], randNum[2], Point(randNum[3], randNum[4])));
// 		// shapeArr.push_back(Circle(randNum[5], randNum[6], Point(randNum[7], randNum[8])));
// 		Rectangle* rec = new Rectangle(randNum[0], randNum[1], randNum[2], Point(randNum[3], randNum[4]));
// 		shapeArr.push_back(rec);

// 		Circle* cir = new Circle(randNum[5], randNum[6], Point(randNum[7], randNum[8]));
// 		shapeArr.push_back(cir);
// 	}

// 	auto vs = make_shared<vector<Shape*>>();
// 	for (int i = 0; i < shapeArr.size(); ++i) {
// 		if (shapeArr[i]->getArea() >= 50) {
// 			vs->push_back(shapeArr[i]);
// 		}
// 	}

// 	return *vs;

// }

// 
// shared_ptr<vector<shared_ptr<Shape>>>
vector<shared_ptr<Shape>>& getShapeAreaArr()
{
	// 初始化随机种子
	srand(time(0));

	const int arrSize = 20;
	// Shape* shapeArr[arrSize];
	shared_ptr<Shape> shapeArr[arrSize];
	for (int i = 0; i < 10; ++i) {
		// 生成随机数组
		int randNum[9];
		for (int j = 0; j < 9; ++j) {
			randNum[j] = rand()%10+1;
		}

		// Rectangle
		// Rectangle* rec = new Rectangle(randNum[0], randNum[1], randNum[2], Point(randNum[3], randNum[4]));
		auto rec = make_shared<Rectangle>(randNum[0], randNum[1], randNum[2], Point(randNum[3], randNum[4]));
		shapeArr[i*2] = rec;

		// Circle
		// Circle* cir = new Circle(randNum[5], randNum[6], Point(randNum[7], randNum[8]));
		auto cir = make_shared<Circle>(randNum[5], randNum[6], Point(randNum[7], randNum[8]));
		shapeArr[i*2+1] = cir;
	}

	// 删除 area 小于50的
	// fit_size = arrSize;
	// for (int i = 0; i < arrSize; ++i) {
	// 	if (shapeArr[i]->getArea() < 50) {
	// 		// delete shapeArr[i];
	// 		shapeArr[i] = NULL;
	// 		--fit_size;
	// 	}
	// }

	// 新数组
	auto vs = make_shared<vector<shared_ptr<Shape>>>();
	// int cnt = 0;
	for (int i = 0; i < arrSize; ++i) {
		if (shapeArr[i]->getArea() >= 50) {
			// newShapeArr[cnt++] = shapeArr[i];
			// cout << "wa" << endl;
			vs->push_back(shapeArr[i]);
		}
	}

	// return newShapeArr;
	return (*vs);

}

int main()
{
	auto time1 = clock();

	auto newShapeArr = getShapeAreaArr();

	// cout << newShapeArr.size() << endl;
	for (auto &v : (newShapeArr)) {
		cout << v->getArea() << endl;
	}

	auto time2 = clock();

	cout << "time = " << time2 - time1 << endl;

	return 0;
}