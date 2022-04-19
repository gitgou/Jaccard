#include "io.h"
#include "algorithm.h"
using namespace std;

//生成数据并写入文件
ULL pBuffle[ARRAY_SIZE];
	
unsigned int uNum = 0, uMaxNum = DATA_SIZE / (sizeof(ULL) * 8);

void WriteVector()
{
	//uNum 记录生成总的数据 unsigned long long 个数, uMaxNum 为 10亿 / (unsigned long long 所占位数) 
	//首先生成非对称数据, vector1
	DataGenerator oDataGen = DataGenerator(2);
	IO oIO = IO("./my_data/non_uniform_vector1");
	
	while(uNum < uMaxNum){
		unsigned int uWriteNum = (uMaxNum - uNum < ARRAY_SIZE) ? (uMaxNum - uNum) : ARRAY_SIZE;
		oDataGen.GenerateData(pBuffle, uWriteNum);
		uNum += uWriteNum;
		oIO.Write(pBuffle, uWriteNum);
	}	
	oDataGen.Print();
	//非对称vector2
	uNum = 0;
	oIO.Reset("./my_data/non_uniform_vector2");
	while(uNum < uMaxNum){
		unsigned int uWriteNum = (uMaxNum - uNum < ARRAY_SIZE) ? (uMaxNum - uNum) : ARRAY_SIZE;
		oDataGen.GenerateData(pBuffle, uWriteNum);
		uNum += uWriteNum;
		oIO.Write(pBuffle, uWriteNum);
	}	
	oDataGen.Print();
	
	//对称vector1
	uNum = 0;
	oDataGen.Reset(5);
	oIO.Reset("./my_data/uniform_vector1");
	while(uNum < uMaxNum){
		unsigned int uWriteNum = (uMaxNum - uNum < ARRAY_SIZE) ? (uMaxNum - uNum) : ARRAY_SIZE;
		oDataGen.GenerateData(pBuffle, uWriteNum);
		uNum += uWriteNum;
		oIO.Write(pBuffle, uWriteNum);
	}	
	oDataGen.Print();
	
	//对称vector2
	uNum = 0;
	oIO.Reset("./my_data/uniform_vector2");
	while(uNum < uMaxNum){
		unsigned int uWriteNum = (uMaxNum - uNum < ARRAY_SIZE) ? (uMaxNum - uNum) : ARRAY_SIZE;
		oDataGen.GenerateData(pBuffle, uWriteNum);
		uNum += uWriteNum;
		oIO.Write(pBuffle, uWriteNum);
	}	
	oDataGen.Print();

}

int main()
{
	//WriteVector();
	
	Algorithm oAth;
	//先计算提供的数据: 非对称向量
	cout << "official data non_uniform: " << endl;
	IO oIO1 = IO("./data/non_uniform_vector1");
	IO oIO2 = IO("./data/non_uniform_vector2");
	ULL pBuffle1[ARRAY_SIZE] = {0}, pBuffle2[ARRAY_SIZE] = {0};	
	unsigned int uNum = 0;
	while(uNum < uMaxNum){
		unsigned int uReadNum = (uMaxNum - uNum < ARRAY_SIZE) ? (uMaxNum - uNum) : ARRAY_SIZE;
		uNum += uReadNum;
		oIO1.Read(pBuffle1, uReadNum);
		oIO2.Read(pBuffle2, uReadNum);
		for(int i = 0; i < uReadNum; ++i)
		{
			oAth.Calcurate(pBuffle1[i], pBuffle2[i]);
		}
	}
	oAth.PrintResult();
	cout << endl << endl ;	
	
	//先计算提供的数据: 对称向量
	cout << "official data uniform: " << endl;
	uNum = 0;
	oIO1.Reset("./data/uniform_vector1");
	oIO2.Reset("./data/uniform_vector2");
	while(uNum < uMaxNum){
		unsigned int uReadNum = (uMaxNum - uNum < ARRAY_SIZE) ? (uMaxNum - uNum) : ARRAY_SIZE;
		uNum += uReadNum;
		oIO1.Read(pBuffle1, uReadNum);
		oIO2.Read(pBuffle2, uReadNum);
		for(int i = 0; i < uReadNum; ++i)
		{
			oAth.Calcurate(pBuffle1[i], pBuffle2[i]);
		}
	}
	oAth.PrintResult();
	cout << endl << endl ;	

	//计算生成的数据: 非对称向量
	cout << "generate data non_uniform: " << endl;
	uNum = 0;
	oIO1.Reset("./my_data/non_uniform_vector1");
	oIO2.Reset("./my_data/non_uniform_vector2");
	while(uNum < uMaxNum){
		unsigned int uReadNum = (uMaxNum - uNum < ARRAY_SIZE) ? (uMaxNum - uNum) : ARRAY_SIZE;
		uNum += uReadNum;
		oIO1.Read(pBuffle1, uReadNum);
		oIO2.Read(pBuffle2, uReadNum);
		for(int i = 0; i < uReadNum; ++i)
		{
			oAth.Calcurate(pBuffle1[i], pBuffle2[i]);
		}
	}
	oAth.PrintResult();
	cout << endl << endl ;	
	
	//计算生成的数据: 对称向量
	cout << "generate data uniform: " << endl;
	uNum = 0;
	oIO1.Reset("./my_data/uniform_vector1");
	oIO2.Reset("./my_data/uniform_vector2");
	while(uNum < uMaxNum){
		unsigned int uReadNum = (uMaxNum - uNum < ARRAY_SIZE) ? (uMaxNum - uNum) : ARRAY_SIZE;
		uNum += uReadNum;
		oIO1.Read(pBuffle1, uReadNum);
		oIO2.Read(pBuffle2, uReadNum);
		for(int i = 0; i < uReadNum; ++i)
		{
			oAth.Calcurate(pBuffle1[i], pBuffle2[i]);
		}
	}
	oAth.PrintResult();
	return 0;
}
