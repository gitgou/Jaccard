#ifndef _DEFINE_H_
#define _DEFINE_H_

#include<bitset>
//定义每次读取数据的数组大小
#define ARRAY_SIZE 1024
//定义生成 1 的概率界定
#define MAX_RATE  10
//生成数据大小 10 亿
#define DATA_SIZE  1000000000 

using ULL = unsigned long long;

#define WRITE() \
	uNum = 0; \
	while(uNum < uMaxNum){ \
		unsigned int uWriteNum = (uMaxNum - uNum < ARRAY_SIZE) ? (uMaxNum - uNum) : ARRAY_SIZE; \
		oDataGen.GenerateData(pBuffle, uWriteNum); \
		uNum += uWriteNum; \
		oIO.Write(pBuffle, uWriteNum); \
	}	\
	oDataGen.Print(); 

#define READ_CALCURATE() \
	uNum = 0; \
	while(uNum < uMaxNum){ \
		unsigned int uReadNum = (uMaxNum - uNum < ARRAY_SIZE) ? (uMaxNum - uNum) : ARRAY_SIZE; \
		uNum += uReadNum; \
		oIO1.Read(pBuffle1, uReadNum); \
		oIO2.Read(pBuffle2, uReadNum); \
		for(int i = 0; i < uReadNum; ++i) \
		{ \
			oAth.Calcurate(pBuffle1[i], pBuffle2[i]); \
		} \
	} \
	oAth.PrintResult(); \
	cout << endl << endl; 	

#endif
