#ifndef STRATEGY_2_H
#define STRATEGY_2_H

#include <stdio.h>

class Strategy {
public:
	virtual void Calculate() = 0;
	virtual ~Strategy() {};
};

// CN
class CNTax : public Strategy {
public:
	void Calculate() {
		printf("计算中国的税\n");
	}
};

class USTax : public Strategy {
public:
	void Calculate() {
		printf("计算美国的税\n");
	}
};

class DETax : public Strategy {
	void Calculate() {
		printf("计算德国的税\n");
	}
};

class FRTax : public Strategy {
	void Calculate() {
		printf("计算法国的税\n");
	}
};

class SalesOrder {
public:
	SalesOrder(Strategy *strategy) : _strategy(strategy) {}

	void CalculateTax() {
		printf("计算各国税之前的一些准备工作\n");

		// 一个会经常发生变化的算法
		_strategy->Calculate();

		printf("计算完了税\n");
	}

	~SalesOrder() {
		delete _strategy;
	}

private:
	Strategy *_strategy;
};


#endif