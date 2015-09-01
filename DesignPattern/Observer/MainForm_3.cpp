#include "FileSplit_3.h"
#include "TextBox.h"
#include <string>
#include <stdlib.h>
#include <stdio.h>

using namespace std;


class MainForm : public Form
{
public:
	MainForm(TextBox* tb1, TextBox* tb2, ProgressBar* pbar) 
	: txtFilePath_(tb1)
	, txtFileNumber_(tb2)
	, progressBar_(pbar)
	{

	}

	void test(double value)
	{
		progressBar_->setValue(value);
	}

	void Button1_Click()
	{
		std::string filePath = txtFilePath_->getText();
		int number = atoi(txtFileNumber_->getText().c_str());

		FileSplitter splitter(filePath, number);
		splitter.addObserver(bind(&MainForm::test, this, placeholders::_1));

		splitter.split();
	}


private:
	TextBox *txtFilePath_;
	TextBox *txtFileNumber_;

	// 进度条
	ProgressBar *progressBar_;
};


int main()
{
	TextBox tb1("c://document/file.out");
	TextBox tb2("10");
	ProgressBar pbar;
	MainForm mf(&tb1, &tb2, &pbar);
	mf.Button1_Click();
	
	return 0;
}
