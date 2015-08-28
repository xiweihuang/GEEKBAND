// 考虑一个文件分割器的设计。MainForm 为界面类,收集用户输入的文件路径, 和分割数量。 
// FileSplitter 为实现文件分割的类型,其中 Split()实现文件分割 算法。
// 1. 要求为 Split()支持多种文件分割算法(至少 3 种),在 MainForm 中灵活切换多种算法。
// 2.在 Split()分割过程中,实现对进度条的实时通知, 即对 progressBar 的赋值。 
// 3.使用松耦合面向对象设计方法和思想,无需编写 具体算法实现,可使用伪码表示设计。

#include <stdio.h>
#include <string>
#include <stdlib.h>

class Form
{
public:
	virtual ~Form() {};
};


class TextBox
{
public:
	TextBox(std::string s = "") : _s(s) {}
	std::string getStr() const
	{
		return _s;
	}
private:
	std::string _s;
};


class ProgressBar
{
public:
	ProgressBar(int v = 0) : _value(v) {}

	int getValue() const
	{
		return _value;
	}

	void setValue(int v)
	{
		_value = v;
	}

private:
	int _value;
};


class Strategy
{
public:
	virtual void splitMethod() = 0;
};

class SplitMethod1 : public Strategy
{
public:
	void splitMethod()
	{
		printf("切割方法1\n");
	}
};

class FileSplitter : public Strategy
{
public:
	FileSplitter(ProgressBar *proBar, std::string path, int number, Strategy *strategy)
	: progressBar(proBar)
	, filePath(path)
	, fileNumber(number)
	, _strategy(strategy)
	{

	}

	// void Split(int splitType)
	// {
	// 	if (splitType == 1) {
	// 		printf("切割方法1\n");
	// 		progressBar->setValue(1);
	// 	}
	// 	else if (splitType == 2) {
	// 		printf("切割方法2\n");
	// 		progressBar->setValue(2);
	// 	}
	// 	else if (splitType == 3) {
	// 		printf("切割方法3\n");
	// 		progressBar->setValue(3);
	// 	}
	// }
	void Split()
	{
		_strategy->splitMethod();
	}

private:
	ProgressBar *progressBar;
	std::string filePath;
	int fileNumber;
	Strategy *_strategy;
};


class MainForm : public Form
{
public:
	// MainForm(TextBox *txt1, TextBox *txt2, ProgressBar *proBar)
	// : txtFilePath(txt1)
	// , txtFileNumber(txt2)
	// , progressBar(proBar)
	// {

	// }
	MainForm()
	{
		txtFilePath   = new TextBox("test1");
		txtFileNumber = new TextBox("123456");
		progressBar   = new ProgressBar(10);
	}

	// MainForm(const MainForm &mf)
	// {
	// 	txtFilePath   = new TextBox();
	// 	txtFileNumber = new TextBox();
	// 	progressBar   = new ProgressBar();
	// }

	// MainForm &operator = (const MainForm &mf)
	// {
	// 	txtFilePath   = new TextBox();
	// 	txtFileNumber = new TextBox();
	// 	progressBar   = new ProgressBar();
	// }

	~MainForm()
	{
		delete txtFilePath;
		delete txtFileNumber;
		delete progressBar;
	}

	void Button1_Click(int type)
	{
		// 先判断 txtFilePath、 txtFileNumber、 progressBar 是否为空
		FileSplitter fsplit(progressBar, (txtFilePath->getStr()), (atoi(txtFileNumber->getStr().c_str())));
		fsplit.Split(type);
	}

private:
	TextBox *txtFilePath;
	TextBox *txtFileNumber;
	ProgressBar *progressBar;
};





