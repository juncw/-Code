// KMP�㷨��ּ��O(N)ʱ����Ѱ���Ӵ����ַ����г��ֵ�λ��
// 1970����Knuth-Morris-Pratt�����˶��Է���

// �㷨���⼰ִ�й���

/*
	1. ��ȡ�Ӵ���ÿ��λ��֮ǰ���ֵ�"�ǰ׺�����׺"ƥ�䳤��next[]��
	2. ���ַ�������ƥ�䡣���i1��i2λ�ô��ַ������i1++,i2++������i2 = next[i2]��
	3. ���next[i2] == -1ʱ��i1++(i2��0����λ��Ϊ-1������Ҫ���¸�i2��ֵ);


	next[] �������
	i2 = 0 ʱ next[0] = -1;
	i2 = 1 ʱ next[1] = 0;

	i2 > 1 ʱ if str2[i2] == str2[next[i2]] ʱ next[i2] = next[i2]++;
	else i2 = next[next[i2]]
*/
#include <iostream>
#include <string>
using namespace std;


void getStrNext(string str, int* next) {

}
void getIndexofStr(string str1, string str2) {
	int* next = new int[str2.length()];
	getStrNext(str2, next);               // get "next[]" ����Ѱ��λ�ò���
}


int main(void) {
	string str1 = "abdabcdeabdabcdf";
	string str2 = "abdabcdf";
	return 0;
}