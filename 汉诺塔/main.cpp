// 汉诺塔
// 问题描述：将多个盘从A盘移动到C盘，借助B盘。
// 借助递归问题进行求解，也就是暴力递归问题
// 考虑问题有无“后效性”的问题
#include <iostream>
using namespace std;


void hanNuoTowel(int floor, char A, char help, char C) {
	if (floor == 1) {
		cout << "from->" << A << "->move to->" << C << endl;
	}
	else {
		hanNuoTowel(floor - 1, A, C, help);                     // 把前N-1移动到help柱子
		cout << "from->" << A << "->move to->" << C << endl;    // 把最后一层移动到目的盘
		hanNuoTowel(floor - 1, help, A, C);                     // 把help盘移动到目的盘
	}	
}
int main(void) {
	hanNuoTowel(3, 'A', 'B', 'C');
	/*
	result:
		A->C
		A->B
		C->B
		A->C
		B->A
		B->C
		A->C
	*/

	return 0;
}