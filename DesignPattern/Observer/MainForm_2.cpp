#include "FileSplit_2.h"
#include "TextBox.h"
#include <string>
#include <stdlib.h>
#include <stdio.h>

class MainForm : public Form, public IProgress
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
		splitter.add_observer(this);

		splitter.split();
	}

	virtual void DoProgress(double value)
	{
		progressBar_->setValue(value);
	}

private:
	TextBox *txtFilePath_;
	TextBox *txtFileNumber_;

	// 进度条
	ProgressBar *progressBar_;
};

// for test
class OtherForm : public IProgress
{
public:
	virtual void DoProgress(double value)
	{
		printf("haha, otherForm...\n");
	}
	void Button1_Click()
	{
		FileSplitter splitter("~/document", 10.0);
		splitter.add_observer(this);
		splitter.split();
	}
};

int main()
{
	TextBox tb1("c:/document/file.out");
	TextBox tb2("10");
	ProgressBar pbar;
	MainForm mf(&tb1, &tb2, &pbar);
	mf.Button1_Click();

	OtherForm of;
	of.Button1_Click();
	
	return 0;
}
