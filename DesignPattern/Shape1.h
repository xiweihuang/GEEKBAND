#ifndef SHAPE_1_H
#define SHAPE_1_H

class Point {
public:
	Point(int xx = 0, int yy = 0) : x(xx), y(yy) {}
	int getx() const { return x; }
	int gety() const { return y; }
private:
	int x;
	int y;
};

class Line {
public:
	Line(const Point &pa, const Point &pb) : p1(pa), p2(pb) {}
private:
	Point p1;
	Point p2;
};

class Rectangle {
public:
	Rectangle(const Point &p, int w, int h) : leftUp(p), width(w), height(h) {}
private:
	Point leftUp;
	int width;
	int height;
};

#endif