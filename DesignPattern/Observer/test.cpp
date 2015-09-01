#include <functional>
#include <stdio.h>

using namespace std;

// typedef function<void(int)> ClickHandler;
class MyButton
{
public:
	function<int(int)> onClick_;

	MyButton(int n) : num_(n) {}
	
	void click()
	{
		// ...

		int ret = onClick_(num_);
		printf("ret = %d\n", ret);
	}
private:
	int num_;
};


class Program
{
public:
	int btn_onClick(int value)
	{
		printf("点击按钮, value = %d\n", value);
		return value+1;
	}

};

int main()
{
	MyButton btn(20);
	Program p;

	btn.onClick_ = bind(&Program::btn_onClick, &p, placeholders::_1);
	btn.click();

	return 0;
}
