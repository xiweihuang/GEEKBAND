#include "Shape1.h"
#include <iostream>
#include <vector>

using namespace std;

class MainForm1 {
public:
	// MainForm1()
	void draw(int type);
	void refresh();
private:
	vector<Line> lineVec;
	vector<Rectangle> rectVec;
};

void MainForm1::draw(int type) {
	if (type == 1) {
		Line line1(Point(1, 2), Point(3, 4));
		lineVec.push_back(line1);
	}
	else if (type == 2) {
		Rectangle rect(Point(5, 6), 7, 8);
		rectVec.push_back(rect);
	}
}

void MainForm1::refresh() {
	for (int i = 0; i < lineVec.size(); ++i) {
		cout << "画线段..." << endl;
	}
	for (int i = 0; i < rectVec.size(); ++i) {
		cout << "画矩形..." << endl;
	}
}

int main() {
	MainForm1 mf;
	mf.draw(1);
	mf.draw(1);
	mf.draw(2);
	mf.draw(2);
	mf.draw(1);
	mf.refresh();
}