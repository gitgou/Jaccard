#ifndef __IO_H__
#define __IO_H__

#include<iostream>

#include "define.h"

using namespace std;
//数据产生类:用来生成 0/1数据
class DataGenerator
{
public:
	DataGenerator(int rate)
	:_rate(rate)
	{
	}
	
	void Reset(int rate)
	{
		_rate = rate;
	}

	//每次生成 64 bit，即 unsigned long long 8B;
	void GetRandomNumber(bitset<64>& bt);

	//外部调用接口 每次生成的数据存入 pBuffle, size = iBuffleSize
	void GenerateData(ULL pBuffle[], int iBuffleSize);

	
	void Print()
	{
		cout << "rate: " << _rate << ", count: " << _count << endl;
		_count = 0;
	}
private:
	//生成1的概率, 范围: 1 - 10
	int _rate;
	unsigned int _count = 0; //记录 生成数据中 1 的个数
};

class IO
{
public:
	
	//文件路径
	IO(const string& path)
	:_path(path)
	{
		cout << "path: " << _path << endl;
		if(NULL == (_fp = fopen(_path.c_str(), "ab+"))){
			cout << "get file descriptor fail. path: " << _path << endl;
		}
	}
	
	/*
	   重置文件路径销毁前文件描述符
	*/
	bool Reset(const string & path)
	{
		if(_fp)
			fclose(_fp);

		_path = path;
		if(NULL == (_fp = fopen(_path.c_str(), "ab+"))){
			cout << "get file descriptor fail. path: " << _path << endl;
			return false;
		}

		return true;
	}
	
	
	/*
		desp: read data from file  
		param: 
			pBuffle 存放读取的数据的 buffer
			size  pBuffle数组的大小
	*/
	void Read(ULL pBuffle[], int size);

	/*
		desp: write data from file
		param: 
			pBuffle 存放写入的数据的 buffer
			size  pBuffle数组的大小
	*/
	void Write(ULL pBuffle[], int size);
	
	~IO(){
		if(_fp)
			fclose(_fp);
	}
private:
	//文件路径
	string _path;
	//文件描述符
	FILE* _fp;
};

#endif
