#ifndef LIBRARY_2_H
#define LIBRARY_2_H

#include <stdio.h>

class Layer {
protected:
	// 稳定的
	void create() {
		printf("\n创建场景\n");
	}

	// 变化的，一般用虚函数或纯虚函数
	virtual void initSprite() = 0;

	// 稳定的
	void startTimer() {
		printf("开启定时器\n");
	}

	// 变化的
	virtual void updateTimer() = 0;

public:

	// 这个就是一个稳定的算法框架，注意，Template Method 的前提是要有一个稳定的算法框架
	void drawLayer() {
		create();
		initSprite();  // 变化的部分，晚的部分交给子类。就是所谓的晚绑定。 或者说 “不要调用我，让我调用你”，框架不让应用调用，应该是框架调用应用。
		startTimer();
		updateTimer();
	}

	virtual ~Layer() {}
};

#endif