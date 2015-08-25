#ifndef LIBRARY_1_H
#define LIBRARY_1_H

#include <stdio.h>

class Layer {
public:

	// 稳定的
	void create() {
		printf("创建一个场景\n");
	}

	// 变化的
	// void initSprite() {
	// 	printf("初始化精灵\n");
	// }

	// 稳定的
	void startTimer() {
		printf("开启定时器\n");
	}

	// 变化的
	// void updateTimer() {
	// 	printf("更新定时器的动作\n");
	// }


};

#endif