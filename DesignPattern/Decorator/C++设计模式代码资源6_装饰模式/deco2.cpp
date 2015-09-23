#include <stdio.h>
#include "deco1.h"

class Crypto
{
public:
	Crypto(Stream *stream) : stream_(stream) {}

	void read()
	{
		printf("解密...\n");
		stream_->read();
		printf("加密...\n");
	}

	void seek()
	{
		printf("解密...\n");
		stream_->seek();
		printf("加密...\n");
	}

	void write()
	{
		printf("解密...\n");
		stream_->write();
		printf("加密...\n");
	}
private:
	Stream *stream_;
};


class Buffered
{
public:
	Buffered(Stream *stream) : stream_(stream) {}

	void read()
	{
		printf("字节1...\n");
		stream_->read();
		printf("字节...\n");
	}

	void seek()
	{
		printf("字节1...\n");
		stream_->seek();
		printf("字节...\n");
	}

	void write()
	{
		printf("字节1...\n");
		stream_->write();
		printf("字节...\n");
	}
private:
	Stream *stream_;
};


// class CryptoBuffered
// {
// public:
// 	void read()
// 	{
		
// 	}
// private:
// 	Stream *stream_;
// };

int main()
{
	FileStream s1;
	NetworkStream s2;
	MemoryStream s3;

	Crypto c1(&s1);
	Crypto c2(&s2);
	Crypto c3(&s3);

	c1.read();
	c2.seek();
	c3.write();

	return 0;
}
