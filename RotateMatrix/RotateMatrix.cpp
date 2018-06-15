/*
	M*M µÄ¾ØÕóÐý×ª
	1  2  3  4
	5  6  7  8
	9  10 11 12
	13 14 15 16
Rotate:
	13 9  5  1
	14 10 6  2
	15 11 7  3
	16 12 8  4
*/
#include <iostream>
#include <iomanip>
using namespace std;

const int MAX_VALUE = 100;
void roate_matrix_edge(int arr[][MAX_VALUE], int tC, int tR, int bC, int bR)
{
	int x_size = bC - tC;
	int y_size = bR - tR;

	for (int i = 0; i < x_size; ++i) {
		int top_val = arr[tR][tC+i];
		arr[tR][tC + i] = arr[bR-i][tC];
		arr[bR - i][tC] = arr[bR][bC-i];
		arr[bR][bC - i] = arr[tR + i][bC];
		arr[tR + i][bC] = top_val;
	}
}
void print_matrix(int arr[][MAX_VALUE], int tC, int tR, int bC, int bR)
{
	cout << "print matrix:" << endl;
	for (int i = tC; i <= bC; ++i) {
		for (int j = tR; j <= bR; ++j) {
			cout << setw(3) << arr[i][j];
		}
		cout << endl;
	}
}
void rotate_matrix(int arr[][MAX_VALUE], int tC, int tR, int bC, int bR)
{
	int n_rows = bR - tR;
	int n_cols = bC - tC;

	if (n_rows != n_cols) {
		return;
	}

	while (bR >= tR) {
		roate_matrix_edge(arr, tC++, tR++, bC--, bR--);
	}
}

int main()
{
	int M = 4-1;
	int arr[][MAX_VALUE] = { {1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16} };
	print_matrix(arr, 0, 0, M, M);
	rotate_matrix(arr, 0, 0, M, M);
	print_matrix(arr, 0, 0, M, M);
	return 0;
}