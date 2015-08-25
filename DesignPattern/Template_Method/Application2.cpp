#include "Library2.h"
#include <iostream>

using namespace std;

class MyLayer : public Layer {
protected:
	void initSprite() {
		cout << "我正在创建精灵。。。" << endl;
	}
	void updateTimer() {
		cout << "我一秒一秒地跳舞" << endl;
	}
};

class YourLayer : public Layer {
protected:
	void initSprite() {
		cout << "你啊，在创建精灵吗？？？" << endl;
	}
	void updateTimer() {
		cout << "你在等时间一秒一秒地过去吗" << endl;
	}
};


int main() {
	Layer *layer1 = new MyLayer();
	Layer *layer2 = new YourLayer();

	layer1->drawLayer();
	layer2->drawLayer();

	delete layer1;
	delete layer2;
 
	return 0;
}