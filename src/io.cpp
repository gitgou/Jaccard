#include<stdio.h>

#include "io.h"

//外部调用接口 每次生成的数据存入 pBuffle, size = iBuffleSize
void DataGenerator::GenerateData(ULL pBuffle[], int iBuffleSize)
{
	for(int i = 0; i < iBuffleSize; ++i)
	{
		bitset<64> bt;
		GetRandomNumber(bt);
		pBuffle[i] = bt.to_ullong();
	}
}

//每次生成 64 bit，即 unsigned long long 8B;
void DataGenerator::GetRandomNumber(bitset<64>& bt)
{
	//每次生成 64 bit 数据，因为要转为 unsigned long long 类型, bitset 不能转化为字符串类型，否则每 bit 将会变为一个字符，占1字节内存
	bt.reset(); //将所有 bit 都置为 0;
	for(int i = 0; i < 64; ++i)
	{
		int num = rand() % MAX_RATE;
		if(num < _rate){
			bt[i] = 1;
		}
	}

	//cout << "bt " << bt << endl;
	_count += bt.count();

}


/*
	desp: write data from file
	param: 
		pBuffle 存放写入的数据的 buffer
		size  pBuffle数组的大小
*/
void IO::Write(ULL pBuffle[], int size)
{
	if(!_fp){
		cout << "Write _fp is null, _path: " << _path << endl;
		return;
	}

	fwrite(pBuffle, sizeof(ULL), size, _fp);

}


void IO::Read(ULL pBuffle[], int size)
{
	if(!_fp){
		cout << "Read _fp is null, _path: " << _path << endl;
		return;
	}
	
	//如果文件描述符已经到了文件末尾
	if(feof(_fp)){
		cout << "Read from " << _path << ",_fp is already in eof." << endl;
		return ;
	}

	fread(pBuffle, sizeof(ULL), size, _fp);
}
