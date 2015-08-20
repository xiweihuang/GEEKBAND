// 为下面的 Rectangle 和 Circle 类重写 getArea 虚函数。然后创建一个数组。 
// 使用一个循环,生成 10 个 Rectangle、10 个 Circle,根据循环遍历顺序为它 们设置 no 编号,位置、长、宽、半径等其他信息取随机 1~10 之间的整数值, 然后将它们加入到创建好的数组中。
// 最后,将这个长度为 20 的数组中所有面 积小于 50 的形状删除。将剩下的形状组成一个新的数组返回。
// 注意: 1. 补齐任务所需的其他函数。2. 考虑正确的内存管理。3. 使用原生数 组,不使用 vector 等容器。

#include <iostream>
#include <ctime>

using namespace std;

class Shape
{
public:
	Shape(int num = 0) : no(num) {}
	virtual ~Shape() {}
	virtual int getArea()=0;
private:
	int no;
};

class Point 
{
public:
	Point(int xx = 0, int yy = 0) : x(xx), y(yy) {}
private:
	int x;
	int y; 
};

class Rectangle : public Shape
{
public:
	Rectangle() {}
	Rectangle(int n, int w, int h, const Point& p) : Shape(n), width(w), height(h), leftUp(p) {}

	int getArea() {
		return width*height;
	}

private:
	int width;
	int height;
	Point leftUp; 
};

class Circle : public Shape
{
public:
	Circle() {}
	Circle(int n, int r, const Point& p) : Shape(n), radius(r), center(p) {}

	int getArea() {
		return static_cast<int>(3.14*radius*radius);
	}

private:
	Point center; 
	int radius;
};


int main()
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
	int fit_size = arrSize;
	for (int i = 0; i < arrSize; ++i) {
		if (shapeArr[i]->getArea() < 50) {
			delete shapeArr[i];
			shapeArr[i] = NULL;
			--fit_size;
		}
	}

	// 新数组
	Shape* newShapeArr[fit_size];
	int cnt = 0;
	for (int i = 0; i < arrSize; ++i) {
		if (shapeArr[i]) {
			newShapeArr[cnt++] = shapeArr[i];
		}
	}

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

	return 0;
}