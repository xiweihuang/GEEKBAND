#include <stdio.h>
#include "deco1.h"

// 加密的文件流
class CryptoFileStream : public FileStream
{
public:
	void read()
	{
		printf("解密...\n");
		FileStream::read();
		printf("加密...\n");
	}
	void seek()
	{
		printf("解密...\n");
		FileStream::seek();
		printf("加密...\n");
	}
	void write()
	{
		printf("解密...\n");
		FileStream::write();
		printf("加密...\n");
	}
};


// 加密的网络流
class CryptoNetworkStream : public NetworkStream
{
public:
	void read()
	{
		printf("解密...\n");
		NetworkStream::read();
		printf("加密...\n");
	}
	void seek()
	{
		printf("解密...\n");
		NetworkStream::seek();
		printf("加密...\n");
	}
	void write()
	{
		printf("解密...\n");
		NetworkStream::write();
		printf("加密...\n");
	}
};


// 加密的内存流
class CryptoMemoryStream : public MemoryStream
{
public:
	void read()
	{
		printf("解密...\n");
		MemoryStream::read();
		printf("加密...\n");
	}
	void seek()
	{
		printf("解密...\n");
		MemoryStream::seek();
		printf("加密...\n");
	}
	void write()
	{
		printf("解密...\n");
		MemoryStream::write();
		printf("加密...\n");
	}
};

int main()
{
	CryptoFileStream f1;
	CryptoNetworkStream n1;
	CryptoMemoryStream m1;

	f1.read();
	f1.seek();
	f1.write();

	return 0;
}