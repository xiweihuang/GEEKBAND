// 考虑一个文件分割器的设计。MainForm 为界面类,收集用户输入的文件路径, 和分割数量。 
// FileSplitter 为实现文件分割的类型,其中 Split()实现文件分割 算法。
// 1. 要求为 Split()支持多种文件分割算法(至少 3 种),在 MainForm 中灵活切换多种算法。
// 2.在 Split()分割过程中,实现对进度条的实时通知, 即对 progressBar 的赋值。 
// 3.使用松耦合面向对象设计方法和思想,无需编写 具体算法实现,可使用伪码表示设计。

#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <list>

// for test
////////////////////////////////////////////
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
		printf("value = %d\n", v);
	}

private:
	int _value;
};
////////////////////////////////////////////

// ======== 策略 =======================
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

// ======== 接口 IProgress ==============
class IProgress
{
public:
	virtual void DoProgress(double value) = 0;
	virtual ~IProgress() {}
};


class FileSplitter
{
public:
	FileSplitter(std::string path, int number, Strategy* strategy)
	: filePath_(path)
	, fileNumber_(number)
	, strategy_(strategy)
	{ }

	void addObserver(IProgress* pro)
	{
		progressList_.push_back(pro);
	}


	void Split()
	{
		strategy_->splitMethod();
		onProgress(10.0);
	}

protected:
	void onProgress(double value)
	{
		for (auto &proBar : progressList_)
		{
			proBar->DoProgress(value);
		}
	}

private:
	std::string filePath_;
	int fileNumber_;
	Strategy* strategy_;

	std::list<IProgress*> progressList_;
};


class MainForm : public Form, public IProgress
{
public:
	MainForm(TextBox* txt1, TextBox* txt2, ProgressBar* proBar, Strategy* strategy)
	: txtFilePath_(txt1)
	, txtFileNumber_(txt2)
	, progressBar_(proBar)
	, strategy_(strategy)
	{ }

	virtual void DoProgress(double value)
	{
		if (progressBar_)
			progressBar_->setValue(value);
	}


	void Button1_Click()
	{
		// 先判断 txtFilePath、 txtFileNumber、 progressBar 是否为空
		FileSplitter fsplit(txtFilePath_->getStr(), atoi(txtFileNumber_->getStr().c_str()), strategy_);
		fsplit.addObserver(this);
		fsplit.Split(); 
	}

private:
	TextBox* txtFilePath_;
	TextBox* txtFileNumber_;
	ProgressBar* progressBar_;
	Strategy* strategy_;
};





