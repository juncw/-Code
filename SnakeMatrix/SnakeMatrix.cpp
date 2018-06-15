/*
	蛇形矩阵，对矩阵的由外向内的遍历。
*/

#include <iostream>
using namespace std;
void print_matrix_edge(int** arr, int Tr, int Tc, int Br, int Bc)
{
	if (Tr == Br) {
		while (Tc <= Bc) {
			cout << arr[Tr][Tc++] << " ";
		}
		cout << endl;
	}
	else if (Tc == Bc) {
		while (Tr <= Br) {
			cout << arr[Tr++][Tc] << " ";
		}
		cout << endl;
	}
	else {
		int tmp_Tr = Tr, tmp_Tc = Tc;
		while (tmp_Tc != Bc) {
			cout << arr[Tr][tmp_Tc++] << " ";
		}
		while (tmp_Tr != Br) {
			cout << arr[tmp_Tr++][Bc] << " ";
		}
		while (Bc != Tc) {
			cout << arr[Br][Bc--] << " ";
		}
		while (Br != Tr) {
			cout << arr[Br--][Tc] << " ";
		}
	}
	cout << endl;
}
void print_matrix(int** arr, int Tr, int Tc, int Br, int Bc)
{
	while (1) {
		
		if (Tr > Br || Tc > Bc) break;
		print_matrix_edge(arr, Tr, Tc, Br, Bc);
		Tr++;
		Br--;
		Tc++;
		Bc--;
	}

}

int main()
{
	int m = 4, n = 4;
	int** arr;
	//= { {1, 2, 3, 4},{5, 6, 7, 8},{9, 10, 11, 12}, {13, 14, 15, 16} };
	arr = new int* [m];
	for (int i = 0; i < n; ++i) {
		arr[i] = new int[n];
	}

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			arr[i][j] = 4 * i + j + 1;
		}
	}

	print_matrix(arr, 0, 0, 3, 3);

	for (int i = 0; i < m; ++i) {
		delete[] arr[i];
	}
	return 0;
}
/*
  1 2 3
  4 5 6
  7 8 9

  1  2  3  4
  5  6  7  8
  9  10 11 12
  13 14 15 16
*/