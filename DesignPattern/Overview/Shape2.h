#ifndef SHAPE_2_H
#define SHAPE_2_H

#include <iostream>

class Point {
public:
	Point(int xx = 0, int yy = 0) : x(xx), y(yy) {}
	int getx() const { return x; }
	int gety() const { return y; }
private:
	int x;
	int y;
};

class Shape {
public:
	virtual void doDraw() = 0;
	virtual ~Shape() {}
};

class Line : public Shape {
public:
	Line(const Point &pa, const Point &pb) : p1(pa), p2(pb) {}
	void doDraw() {
		std::cout << "画线段..." << std::endl;
	}
	~Line() {
		// std::cout << "delete line..." << std::endl;
	}
private:
	Point p1;
	Point p2;
};

class Rectangle : public Shape {
public:
	Rectangle(const Point &p, int w, int h) : leftUp(p), width(w), height(h) {}
	void doDraw() {
		std::cout << "画矩形..." << std::endl;
	}
	~Rectangle() {
		// std::cout << "delete rectangle..." << std::endl;
	}
private:
	Point leftUp;
	int width;
	int height;
};

class Circle : public Shape {
public:
	void doDraw() {
		std::cout << "画圆形..." << std::endl;
	}
	~Circle() {
		// std::cout << "delete circle..." << std::endl;
	}
};

#endif