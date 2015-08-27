#include "Shape2.h"
#include <iostream>
#include <vector>

using namespace std;

class MainForm2 {
public:
	void draw(int type);
	void refresh();
	void clear();
	~MainForm2();
private:
	vector<Shape*> shapeVec;
};

void MainForm2::draw(int type) {
	if (type == 1) {
		shapeVec.push_back(new Line(Point(1, 2), Point(3, 4)));
	}
	else if (type == 2) {
		shapeVec.push_back(new Rectangle(Point(5, 6), 7, 8));
	}
	else if (type == 3) {
		shapeVec.push_back(new Circle());
	}
}

void MainForm2::refresh() {
	for (const auto &v : shapeVec) {
		v->doDraw();
	}
}

MainForm2::~MainForm2() {
	for (auto &v : shapeVec) {
		delete v;
	}
}

int main() {
	MainForm2 mf;
	mf.draw(1);
	mf.draw(1);
	mf.draw(2);
	mf.draw(2);
	mf.draw(1);
	mf.draw(3);
	mf.draw(3);
	mf.refresh();
}