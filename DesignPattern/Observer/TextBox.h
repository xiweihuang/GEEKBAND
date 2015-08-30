#ifndef TEXT_BOX_H
#define TEXT_BOX_H

#include <string>
#include <stdio.h>


// for test
class Form
{
// public:
};

class TextBox
{
public:
	TextBox(std::string str = "NULL") : str_(str) {}
	std::string getText()
	{
		return str_;
	}
	void setText(std::string str)
	{
		str_ = str;
	}
private:
	std::string str_;
};


class ProgressBar
{
public:
	ProgressBar(double radius = 0) : radius_(radius) {}

	void setValue(double radius)
	{
		radius_ = radius;

		// 更新进度条的显示
		printf("进度%.2lf\n", radius_);
	}
private:
	double radius_;
};


#endif