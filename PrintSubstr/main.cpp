// 打印子字符串问题
// "abc"打印子字符串"a", "ab", "abc", "ac", "b", "bc", "c", " "
// 暴力递归求解问题

#include <iostream>
#include <string>
using namespace std;

void printAllSubstr(string arr, int i, int len, string res) {
	// base case 中断节点
	if (i == len) {
		cout << "result:" << res << endl;
		return;
	}
	printAllSubstr(arr, i + 1, len, res + arr[i]);        // 选择要当前节点
	printAllSubstr(arr, i + 1, len, res);                 // 选择不要当前节点
}



int main(void) {

	printAllSubstr("ABC", 0, 3, "");
	/*
	result:
		ABC
		AB
		AC
		A
		BC
		B
		C
		_
	*/
	return 0;
}