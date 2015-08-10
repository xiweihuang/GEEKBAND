#include <iostream>

using namespace std;

class Shape 
{
public:
	explicit Shape(int no = 0) : no_(no) {}
	virtual ~Shape() {}
private:
	int no_;
};

class Point
{
public:
	Point(int x = 0, int y = 0) : x_(x), y_(y) {}
	int getX() const {
		return x_;
	}
	int getY() const {
		return y_;
	}
private:
	int x_;
	int y_;
};

class Rectangle : public Shape
{
public:
	Rectangle(int width, int height, int x, int y)
	: width_(width)
	, height_(height)
	, leftUp_(new Point(x, y)) 
	{
		cout << "普通构造..." << endl;
	}

	Rectangle(const Rectangle &other)
	: width_(other.width_)
	, height_(other.height_)
	, leftUp_(new Point(*other.leftUp_)) 
	{
		cout << "拷贝构造..." << endl;
	}

	Rectangle& operator = (const Rectangle &other) 
	{
		cout << "拷贝赋值..." << endl;
		if (this == &other) {
			return *this;
		}
		if (leftUp_) {
			delete leftUp_;
		}
		leftUp_ = new Point(*other.leftUp_);
		width_  = other.width_;
		height_ = other.height_;
		return *this;
	}

	~Rectangle() 
	{
		cout << "dealloc..." << endl;
		delete leftUp_;
	}

	// void setData(int width, int height, int x, int y) {
	// 	_width = width;
	// 	_height = height;
	// 	_leftUp->x = x;
	// 	_leftUp->y = y;
	// }
	void printData() 
	{
		printf("data: %d, %d, %d, %d\n", width_, height_, leftUp_->getX(), leftUp_->getY());
	}

private:
	int width_;
	int height_;
	Point* leftUp_;
};

int main()
{
	Rectangle p1(10, 20, 30, 40);
	Rectangle p2(p1);
	Rectangle p3 = p2;  // 这也是拷贝构造
	p3 = p1; 

	// p2.setData(100, 100, 200, 200);
	// p3.setData(5, 5, 5, 5);

	// p1.printData();
	// p2.printData();
	// p3.printData();

	// Shape *p4 = new Rectangle(10, 10, 10, 10);
	// delete p4;


	return 0;
}