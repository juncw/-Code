// ��ӡ ȫ��������
// "abc"����˳��Ϊ��abc acb bac bca cab cba

#include <iostream>
using namespace std;


void swap(string& source, int i, int j) {     // ������ã�ʹ��ֵΨһ
	char tmp;
	tmp = source[i];
	source[i] = source[j];
	source[j] = tmp;
}
void printAllSort(string source, string res, int i, int& sum) {
	if ((int)source.length() == i) {
		cout << res.c_str() << endl;
		++sum;
		return;
	}
	for (int j = i; j < source.length(); ++j) {
		swap(source, i, j);                                                 // ��λ����Ҫ�����������һ�λ�ý��н���
		//cout << i << ":1:" << j << "->" << source.c_str() << endl;
		printAllSort(source, res + source[i], i + 1, sum);                  // �ݹ��
		swap(source, i, j);                                                 // ����λ�Ľ���ֻ�����
		//cout << i << ":2:" << j << "->" << source.c_str() << endl;
	}

}

int main(void) {
	int sum = 0;
	printAllSort("abcdef", "", 0, sum);
	cout << "total sum:" << sum << endl;
	return 0;
}