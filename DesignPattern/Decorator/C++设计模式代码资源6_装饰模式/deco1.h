#ifndef DECO1_H
#define DECO1_H

#include <stdio.h>

class Stream
{
public:
	virtual void read() = 0;
	virtual void seek() = 0;
	virtual void write() = 0;
};

class FileStream : public Stream
{
public:
	virtual void read()
	{
		printf("读文件流\n");
	}
	virtual void seek()
	{
		printf("定位文件流\n");
	}
	virtual void write()
	{
		printf("写文件流\n");
	}
};


class NetworkStream : public Stream
{
public:
	virtual void read()
	{
		printf("读网络流\n");
	}
	virtual void seek()
	{
		printf("定位网络流\n");
	}
	virtual void write()
	{
		printf("写网络流\n");
	}
};


class MemoryStream : public Stream
{
public:
	virtual void read()
	{
		printf("读内存流\n");
	}
	virtual void seek()
	{
		printf("定位内存流\n");
	}
	virtual void write()
	{
		printf("写内存流\n");
	}
};

#endif
