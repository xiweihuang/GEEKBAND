#include "FileSplit_1.h"
#include "TextBox.h"
#include <string>
#include <stdlib.h>

// using namespace std;

// 多继承，虽然支持，但是不推荐。推荐一个父类，外加零个或多个接口
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

		// FileSplitter splitter(filePath, number, progressBar_);
		FileSplitter splitter(filePath, number, this);

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

int main()
{
	TextBox tb1("c:/document/file.out");
	TextBox tb2("10");
	ProgressBar pbar;
	MainForm mf(&tb1, &tb2, &pbar);
	mf.Button1_Click();
	return 0;
}
