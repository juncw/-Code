// 岛问题，主要解决的是在小范围矩阵和大范围矩阵的问题
// 了解并查集的概念
/*
岛问题
	一个矩阵中只有0和1两种值，每个位置都可以和自己的上、下、左、右
	四个位置相连，如果有一片1连在一起，这个部分叫做一个岛，求一个
	矩阵中有多少个岛？
	举例：
	0 0 1 0 1 0
	1 1 1 0 1 0
	1 0 0 1 0 0
	0 0 0 0 0 0
	这个矩阵中有三个岛。
*/
#include <iostream>
#include <iomanip>

using namespace std;
// print array
void printArr(int arr[4][6]) {
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 6; ++j) {
			cout << setw(3) << arr[i][j];
		}
		cout << endl;
	}
}
void checkSubLab(int arr[][6], int i, int j) {
	
	if (i >= 4 || j < 0 || j >= 6 || arr[i][j] == 0) {
		return;
	}
	if (arr[i][j] == 1) {
		arr[i][j] = 2;
		checkSubLab(arr, i + 1, j);
		checkSubLab(arr, i, j - 1);
		checkSubLab(arr, i, j + 1);
	}
	
	
}
void islandNumber(int arr[][6], int& counts) {
	for (int row = 0; row < 4; ++row) {
		for (int col = 0; col < 6; ++col) {
			if (arr[row][col] == 1) {
				counts++;
				cout << "(" << row << "," << col << ")" << endl;
				checkSubLab(arr, row, col);
				
				printArr(arr);
			}
		}
	}
}

int main(void) {
	int arr[][6] = {    {0, 1, 1, 0, 1, 0},
						{1, 1, 1, 0, 1, 0},
						{1, 0, 0, 1, 0, 0 },
						{0, 0, 0, 0, 0, 0 } };
	srand((unsigned)time(0));
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 6; ++j) {
			arr[i][j] = (int)rand() % 2;
		}
	}
	printArr(arr);
	int count = 0; 
	islandNumber(arr, count);
	cout << count << endl;

	return 0;
}
// 在这里截至对小范围数组进行了简单的infect感染方法求解，如果针对大问题求解就需要用到"并行计算"的处理方法。