#include "strategy2.h"

int main() {

	SalesOrder so1(new CNTax);
	SalesOrder so2(new USTax);
	SalesOrder so3(new DETax);
	SalesOrder so4(new FRTax);

	so1.CalculateTax();
	so2.CalculateTax();
	so3.CalculateTax();
	so4.CalculateTax();

	return 0;
}