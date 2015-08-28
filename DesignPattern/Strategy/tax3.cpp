#include "strategy3.h"
#include <functional>

using namespace std;

int main() 
{

	// CNTax cnTax;

	// SalesOrder so1(bind(&CNTax::Calculate, cnTax));

	SalesOrder so1(bind(Calculate_CN));

	so1.CalculateTax();

	return 0;
}