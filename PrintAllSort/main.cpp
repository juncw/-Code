// 打印 全排列问题
// "abc"排列顺序为：abc acb bac bca cab cba

#include <iostream>
using namespace std;


void swap(string& source, int i, int j) {     // 添加引用，使得值唯一
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
		swap(source, i, j);                                                 // 移位，将要插入的数据与兑换位置进行交换
		//cout << i << ":1:" << j << "->" << source.c_str() << endl;
		printAllSort(source, res + source[i], i + 1, sum);                  // 递归加
		swap(source, i, j);                                                 // 把移位的结果又换回来
		//cout << i << ":2:" << j << "->" << source.c_str() << endl;
	}

}

int main(void) {
	int sum = 0;
	printAllSort("abcdef", "", 0, sum);
	cout << "total sum:" << sum << endl;
	return 0;
}