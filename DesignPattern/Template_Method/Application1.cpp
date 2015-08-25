#include "Library1.h"
#include <stdio.h>

// using namespace std;

class MyLayer {
public:
	void initSprite() {
		printf("我的场景在初始化精灵\n");
	}

	void updateTimer() {
		printf("我的场景正在跑一个定时器\n");
	}
};

class YourLayer {
public:
	void initSprite() {
		printf("你的场景在初始化精灵\n");
	}
	void updateTimer() {
		printf("你的场景啊哈哈定时器\n");
	}
};

int main() {
	Layer layer;
	MyLayer mLayer;

	// 代码段1
	layer.create();
	mLayer.initSprite();
	layer.startTimer();
	mLayer.updateTimer();

	Layer layer1;
	YourLayer yLayer;

	// 代码段2
	layer1.create();
	yLayer.initSprite();
	layer.startTimer();
	yLayer.updateTimer();

	// 代码段1 和 代码段2，都是一个稳定的算法框架，所以可以考虑隔离开变化的部分，使用模板方法

	return 0;
}