#ifndef __ALGORITHM_H__
#define __ALGORITHM_H__

#include<iostream>
#include<bitset>

#include "define.h"

//用于计算 Jaccard 相似度 和 Hamming Distance
class Algorithm 
{
public:
	Algorithm()
	{}

	
	void Calcurate(ULL lsh, ULL rsh);

	void PrintResult();

private:
	void clear();

private:
	int _iInterset = 0; //两个向量数据 1 交集
	int _iAndSet = 0;   //两个向量数据 1 并集 
	int _iHammingDistance = 0;// 记录 Hamming Distance 
};
#endif
