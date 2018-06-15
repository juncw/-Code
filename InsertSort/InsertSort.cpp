#include <iostream>
#include <time.h>
#include <algorithm>   // stlĬ�������㷨
#include <functional>  // ����ʽ���� less<int>() ����  greater<int>() ����
using namespace std;

/*
	ֱ�Ӳ��������㷨, ʱ�临�Ӷ�O(N^2), �ռ临�Ӷ�O(1)�����ʱ�临�Ӷ�O(N), �ȶ������㷨
*/
void swap(int& left, int& right)
{
	int tmp = left;
	left = right;
	right = tmp;
}
void insert_sort(int* arr, int len)
{
	for (int i = 1; i < len; ++i) {
		for (int j = i-1; j >= 0; --j) {
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}
void print_arr(int* arr, int len)
{
	for (int i = 0; i < len; ++i) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

bool check_arr_isequal(int* arr, int* arr2, int size)
{
	if (size <= 0) return false;
	for (int i = 0; i < size; ++i) {
		if (arr[i] != arr2[i]) { // not equal
			return false;
		}
	}
	return true; // arr and arr2 is equal
}
int main()
{
	int *arr;
	int *arr2;
	int size = 10;
	arr = new int[size];
	arr2 = new int[size];

	srand((unsigned int)time(NULL));
	for (int i = 0; i < size; ++i) {
		arr[i] = rand() % 1000;
		arr2[i] = arr[i];
	}
	print_arr(arr, size);
	insert_sort(arr, size);
	print_arr(arr, size);
	sort(arr2, arr2 + size, less<int>());
	print_arr(arr2, size);

	if (check_arr_isequal(arr, arr2, size)) {
		cout << "sort result is right." << endl;
	}
	else {
		cout << "damit, result is wrong." << endl;
	}
	delete[] arr;
	delete[] arr2;
	return 0;
}