#include "homework.h"

int main()
{
	TextBox tb1;
	TextBox tb2;
	ProgressBar proBar;
	SplitMethod1 method;

	MainForm mf(&tb1, &tb2, &proBar, &method);
	mf.Button1_Click();
	mf.Button1_Click();
	return 0;
}