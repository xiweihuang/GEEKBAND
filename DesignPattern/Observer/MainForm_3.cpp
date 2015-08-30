#include "FileSplit_3.h"
#include "TextBox.h"
#include <string>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

void test1(double value)
{
	// printf("hello.....\n");
	printf("test1 %lf\n", value);
}

void test2(double value)
{
	// printf("hello.....\n");
	printf("test2 %lf\n", value);
}

void test3(double value)
{
	// printf("hello.....\n");
	printf("test3 %lf\n", value);
}


class MainForm : public Form
{
public:
	MainForm(TextBox* tb1, TextBox* tb2, ProgressBar* pbar) 
	: txtFilePath_(tb1)
	, txtFileNumber_(tb2)
	, progressBar_(pbar)
	{

	}

	

	void Button1_Click()
	{
		std::string filePath = txtFilePath_->getText();
		int number = atoi(txtFileNumber_->getText().c_str());

		FileSplitter splitter(filePath, number);
		splitter.addObserver(&test1);
		splitter.addObserver(&test2);
		splitter.addObserver(&test3);
		splitter.removeObserver(&test1);

		splitter.split();
	}


private:
	TextBox *txtFilePath_;
	TextBox *txtFileNumber_;

	// 进度条
	ProgressBar *progressBar_;
};

// for test
// class OtherForm : public IProgress
// {
// public:
// 	virtual void DoProgress(double value)
// 	{
// 		printf("haha, otherForm...\n");
// 	}
// 	void Button1_Click()
// 	{
// 		FileSplitter splitter("~/document", 10.0);
// 		splitter.add_observer(this);
// 		splitter.split();
// 	}
// };

int main()
{
	TextBox tb1("c:/document/file.out");
	TextBox tb2("10");
	ProgressBar pbar;
	MainForm mf(&tb1, &tb2, &pbar);
	mf.Button1_Click();

	// OtherForm of;
	// of.Button1_Click();
	
	return 0;
}
