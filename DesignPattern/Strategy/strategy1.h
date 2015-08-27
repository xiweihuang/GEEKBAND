#ifndef STRATEGY_1_H
#define STRATEGY_1_H

#include <stdio.h>

// 增加一个需求，计算法国的税

enum TaxBase {
	CN_Tax,
	US_Tax,
	DE_Tax,
	FR_Tax  // 改变
};

class SalesOrder {
public:
	SalesOrder(TaxBase taxBase) : tax(taxBase) {}

	void CalculateTax() {

		printf("计算各国税之前的一些准备工作\n");


		// 一个经常发生变化的算法（那就需要隔离变化）
		if (tax == CN_Tax) {
			printf("计算中国的税\n");
		}
		else if (tax == US_Tax) {
			printf("计算美国的税\n");
		}
		else if (tax == DE_Tax) {
			printf("计算德国的税\n");
		}
		else if (tax == FR_Tax) {
			printf("计算法国的税\n");  // 改变
		}


		printf("计算完了税\n");
	}

private:
	TaxBase tax;
};


#endif