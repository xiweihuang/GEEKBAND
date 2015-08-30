#ifndef FILE_SPLIT_3_H
#define FILE_SPLIT_3_H

#include <string>
#include <stdio.h>
#include "TextBox.h"
// #include <list>
#include <functional>
#include <unordered_set>

class FileSplitter
{
public:
	// typedef std::function<void(double)> FunCallback;
	typedef void(*FunCallback)(double);

	FileSplitter(const std::string& filePath, int fileNumber)
	: _filePath(filePath)
	, _fileNumber(fileNumber)
	{

	}

	// 增加观察者
	void addObserver(FunCallback func)
	{
		observerCbSet_.insert(func);
	}
	// 移除观察者
	void removeObserver(FunCallback func)
	{
		if (observerCbSet_.find(func) != observerCbSet_.end())
		{
			observerCbSet_.erase(func);
		}
	}

	void split()
	{
		// 1.读取大文件

		// 2.分批次向小文件中写入
		for (int i = 0; i < _fileNumber; ++i)
		{
			onProgress((i+1.0)/_fileNumber);
		}
	}

protected:
	void onProgress(double value)
	{
		// 遍历所有的观察者
		for (auto &v : observerCbSet_)
		{
			v(value);
		}
	}

private:
	std::string _filePath;
	int _fileNumber;

	std::unordered_set<FunCallback> observerCbSet_;
};


#endif