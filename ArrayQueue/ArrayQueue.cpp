/*
	����ʵ�ֶ���
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

	// ��ջ
	int pop() {
		if (this->size <= 0) {
			throw exception("exception:queue is empty!");
		}
		int tmp = arr[start++];
		start = start >= MAX_LENGTH ? 0 : start;
		size--;
		return tmp;
	}
	// ��ջ
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
	// assert ���������������жϴ���ֱ�ӽ���ִ�У��׳��쳣��
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