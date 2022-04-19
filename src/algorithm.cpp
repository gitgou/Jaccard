#include "algorithm.h"

using namespace std;

//计算
void Algorithm::Calcurate(ULL lsh, ULL rsh)
{
	bitset<64> btL(lsh), btR(rsh), btTemp;
	btTemp = btL & btR;
	_iInterset += btTemp.count(); //交集相加, bitset.count() 返回 1 的个数
	btTemp.reset();
	btTemp = btL | btR;
	_iAndSet += btTemp.count(); //交集相加, bitset.count() 返回 1 的个数
	btTemp.reset();
	btTemp = btL ^ btR;
	_iHammingDistance += btTemp.count();
}

void Algorithm::PrintResult()
{
	cout << "the numbers of interset is : " << _iInterset << endl;
	cout << "the numbers of andset is : " << _iAndSet << endl;
	cout << "jaccard similary is : " << (double)_iInterset /(double)_iAndSet << endl; 
	cout << "Hamming Distance is : " << _iHammingDistance << endl;
	
	clear();
}
	
void Algorithm::clear()
{
	_iInterset = 0;
	_iAndSet = 0;
	_iHammingDistance = 0;
}
