#ifndef FILE_SPLIT_2_H
#define FILE_SPLIT_2_H

#include <string>
#include <stdio.h>
#include "TextBox.h"
#include <list>

// using namespace std;

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
	FileSplitter(const std::string &filePath, int fileNumber)
	: filePath_(filePath)
	, fileNumber_(fileNumber)
	{

	}

	// 增加观察者
	void add_observer(IProgress* ipro)
	{
		_proList.push_back(ipro);
	}
	// 移除观察者
	void remove_observer(IProgress* ipro)
	{
		// _proList.erase(ipro);
	}

	void split()
	{
		// 1.读取大文件

		// 2.分批次向小文件中写入
		for (int i = 0; i < fileNumber_; ++i)
		{
			onProgress((i+1.0)/fileNumber_);
		}
	}

protected:
	void onProgress(double value)
	{
		// 遍历所有的观察者
		for (auto &v : _proList)
		{
			v->DoProgress(value);
		}
	}

private:
	std::string filePath_;
	int fileNumber_;

	// IProgress* iprogress_;  // 抽象通知机制
	std::list<IProgress*> _proList;

};


#endif