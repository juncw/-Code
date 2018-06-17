// KMP算法，旨在O(N)时间内寻找子串在字符串中出现的位置
// 1970年由Knuth-Morris-Pratt三个人独自发明

// 算法讲解及执行过程

/*
	1. 获取子串中每个位置之前出现的"最长前缀和最长后缀"匹配长度next[]。
	2. 与字符串进行匹配。如果i1和i2位置处字符相等则i1++,i2++，否则i2 = next[i2]。
	3. 如果next[i2] == -1时，i1++(i2在0处的位置为-1，则不需要重新给i2赋值);


	next[] 数组的求法
	i2 = 0 时 next[0] = -1;
	i2 = 1 时 next[1] = 0;

	i2 > 1 时 if str2[i2] == str2[next[i2]] 时 next[i2] = next[i2]++;
	else i2 = next[next[i2]]
*/
#include <iostream>
#include <string>
using namespace std;


void getStrNext(string str, int* next) {
	if (str.empty()) {
		return;
	}

	next[0] = -1;
	next[1] = 0;
	int len = str.length();
	int i = 2, j = 0;
	while (i <= len) {
		if (str[i-1] == str[j]) {
			next[i++] = ++j;
		}
		else if(next[j] == -1){
			next[i++] = 0;
		}
		else {
			j = next[j];
		}
	}
}
int getIndexofStr(string str1, string str2) {
	int* next = new int[str2.length()];
	getStrNext(str2, next);               // get "next[]" 加速寻找位置操作
	cout << "str2中的next[]数组：";
	for (int i = 0; i < str2.length(); ++i) {
		cout << next[i] << " ";
	}
	cout << endl;

	int i = 0, j = 0;
	while (i < str1.length() && j < str2.length()) {
		if (str1[i] == str2[j]) {
			i++;
			j++;
		}
		else if(next[j] == -1) {
			i++;
		}
		else {
			j = next[j];
		}
	}
	int index = j != str2.length() ? -1 : i - str2.length();
	return index;
}


int main(void) {
	string str1 = "abdabcdeabdabcdf";
	string str2 = "abdabcdf";
	int indexStr = getIndexofStr(str1, str2);
	cout << indexStr << endl;
	return 0;
}