// �����⣬��Ҫ���������С��Χ����ʹ�Χ���������
// �˽Ⲣ�鼯�ĸ���
/*
������
	һ��������ֻ��0��1����ֵ��ÿ��λ�ö����Ժ��Լ����ϡ��¡�����
	�ĸ�λ�������������һƬ1����һ��������ֽ���һ��������һ��
	�������ж��ٸ�����
	������
	0 0 1 0 1 0
	1 1 1 0 1 0
	1 0 0 1 0 0
	0 0 0 0 0 0
	�������������������
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
// �����������С��Χ��������˼򵥵�infect��Ⱦ������⣬�����Դ�����������Ҫ�õ�"���м���"�Ĵ�������