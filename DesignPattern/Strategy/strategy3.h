#ifndef STRATEGY_3_H
#define STRATEGY_3_H

#include <stdio.h>
#include <functional>

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

void Calculate_CN()
{
	printf("计算中国的税，好！\n");
}

// class USTax {
// public:
// 	void Calculate() {
// 		printf("计算美国的税\n");
// 	}
// };

// class DETax {
// 	void Calculate() {
// 		printf("计算德国的税\n");
// 	}
// };

// class FRTax {
// 	void Calculate() {
// 		printf("计算法国的税\n");
// 	}
// };



typedef std::function<void()> CalculateCallback;

class SalesOrder {
public:
	// SalesOrder(Strategy *strategy) : _strategy(strategy) {}
	SalesOrder(CalculateCallback cb) : calculateCb_(cb) {}

	void CalculateTax() {
		printf("计算各国税之前的一些准备工作\n");

		// 一个会经常发生变化的算法
		// _strategy->Calculate();
		calculateCb_();

		printf("计算完了税\n");
	}

private:
	CalculateCallback calculateCb_;
};


#endif