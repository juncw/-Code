/*
	数组实现队列
*/
#include <iostream>
using namespace std;
#include <assert.h>

class ArrayQueue {
private:
	int start;
	int end;
	int* arr;
	int MAX_LENGTH;
	int size;
public:
	ArrayQueue(int size) {
		if (size <= 0) {
			cout << "size is small equal 0!" << endl;
			return;
		}
		arr = new int[size];
		MAX_LENGTH = size;
		this->size = 0;
		start = end = 0;
	}
	~ArrayQueue() {
		delete[] arr;
	}

	// 弹栈
	int pop() {
		if (this->size <= 0) {
			throw exception("exception:queue is empty!");
		}
		int tmp = arr[start++];
		start = start >= MAX_LENGTH ? 0 : start;
		size--;
		return tmp;
	}
	// 入栈
	void push(int val) {
		if (this->size >= MAX_LENGTH) {
			throw exception("exception:queue is full!"); 
		}
			arr[end++] = val;
		size++;
		end = end >= MAX_LENGTH ? 0 : end;
	}
};
int main()
{
	char c_choose = '0';
	// assert 断言申明，条件判断错误直接结束执行，抛出异常。
	assert(1 <= 10);
	try {
		ArrayQueue arrayQueue(2);
		while (1) {
			cout << "input choose is(1.push   2.pop):";
			c_choose = getchar();
			switch (c_choose) {
			case '1':
				arrayQueue.push(1);
				break;
			case '2':
				cout << arrayQueue.pop() << endl;
				break;
			default:
				break;
			}
			rewind(stdin);
			if (c_choose == '0') {
				break;
			}
		}
	}
	catch (exception e) {
		cout << e.what() << endl;
		exit(1);
	}

	return 0;
}