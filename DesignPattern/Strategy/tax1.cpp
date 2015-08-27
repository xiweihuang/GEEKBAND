#include "strategy1.h"

int main() {

	SalesOrder so1(CN_Tax);
	SalesOrder so2(US_Tax);
	SalesOrder so3(DE_Tax);
	SalesOrder so4(FR_Tax);

	so1.CalculateTax();
	so2.CalculateTax();
	so3.CalculateTax();
	so4.CalculateTax();

	return 0;
}