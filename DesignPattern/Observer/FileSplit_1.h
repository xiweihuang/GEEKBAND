#ifndef FILE_SPLIT_1_H
#define FILE_SPLIT_1_H

#include <string>
#include <stdio.h>
#include "TextBox.h"


// 接口、抽象基类
class IProgress
{
public:
	virtual void DoProgress(double value) = 0;
	virtual ~IProgress() {}
};


class FileSplitter
{
public:
	FileSplitter(const std::string &filePath, int fileNumber, IProgress* iprogress /*ProgressBar* pBar*/)
	: filePath_(filePath)
	, fileNumber_(fileNumber)
	, iprogress_(iprogress)
	// , progressBar_(pBar)
	{

	}

	void split()
	{
		// 1.读取大文件

		// 2.分批次向小文件中写入
		for (int i = 0; i < fileNumber_; ++i)
		{
			// ...
			// printf("切割第%d部分\n", i+1);

			// if (progressBar_)
			// 	progressBar_->setValue((i+1.0)/fileNumber_);
			
			onProgress((i+1.0)/fileNumber_);

		}
	}

protected:
	void onProgress(double value)
	{
		if (iprogress_)
			iprogress_->DoProgress(value);
	}

private:
	std::string filePath_;
	int fileNumber_;

	// 进度条
	// 违反了 "依赖倒置原则"，稳定不应该依赖于 实现细节（变化），因为实现细节是非常容易发生变化的

	// ProgressBar* progressBar_;  // 具体通知控件
	IProgress* iprogress_;  // 抽象通知机制

};


#endif