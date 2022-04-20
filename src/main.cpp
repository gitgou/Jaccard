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

	WRITE()

	//非对称vector2
	oIO.Reset("./my_data/non_uniform_vector2");
	WRITE()

	//对称vector1
	oDataGen.Reset(5);
	oIO.Reset("./my_data/uniform_vector1");
	WRITE()

	//对称vector2
	oIO.Reset("./my_data/uniform_vector2");
	WRITE()
}

int main()
{
	WriteVector();
	
	Algorithm oAth;
	//先计算提供的数据: 非对称向量
	IO oIO1 = IO("./data/non_uniform_vector1");
	IO oIO2 = IO("./data/non_uniform_vector2");
	ULL pBuffle1[ARRAY_SIZE] = {0}, pBuffle2[ARRAY_SIZE] = {0};	
	cout << "official data non_uniform: " << endl;
	unsigned int uNum = 0;
	READ_CALCURATE()

	//先计算提供的数据: 对称向量
	cout << "cal official data uniform: " << endl;
	oIO1.Reset("./data/uniform_vector1");
	oIO2.Reset("./data/uniform_vector2");
	READ_CALCURATE()

	//计算生成的数据: 非对称向量
	cout << "cal generated data non_uniform: " << endl;
	oIO1.Reset("./my_data/non_uniform_vector1");
	oIO2.Reset("./my_data/non_uniform_vector2");
	READ_CALCURATE()
	
	//计算生成的数据: 对称向量
	cout << "cal generated data uniform: " << endl;
	oIO1.Reset("./my_data/uniform_vector1");
	oIO2.Reset("./my_data/uniform_vector2");
	READ_CALCURATE()
	
	return 0;
}
