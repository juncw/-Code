// ��ӡ���ַ�������
// "abc"��ӡ���ַ���"a", "ab", "abc", "ac", "b", "bc", "c", " "
// �����ݹ��������

#include <iostream>
#include <string>
using namespace std;

void printAllSubstr(string arr, int i, int len, string res) {
	// base case �жϽڵ�
	if (i == len) {
		cout << "result:" << res << endl;
		return;
	}
	printAllSubstr(arr, i + 1, len, res + arr[i]);        // ѡ��Ҫ��ǰ�ڵ�
	printAllSubstr(arr, i + 1, len, res);                 // ѡ��Ҫ��ǰ�ڵ�
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