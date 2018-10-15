#include <iostream>
#include <fstream>
#include "menu.h"
using namespace std;

int main()
{
	ofstream result;
	result.open("Result.csv", ios::out);
	result << "Input State,Input size,Selection sort,Insertion sort,Shaker sort,Shell sort,Quick sort,Merge sort,Heap sort,Radix sort,Interchange sort,Binary Insertion sort" << endl;
	result.close();
	int phimTat;
	menu();
	chonMenu(phimTat);
	xuLyMenu(phimTat);
	system("pause");
	return 0;
}