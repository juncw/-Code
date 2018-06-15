/*
	数组实现栈的功能
*/
#include <iostream>
using namespace std;

class ArrayStack {
private:
	int* arr;
	int size;
	int MAX_LENGTH;
public:
	ArrayStack(int size) {
		arr = new int[size];
		MAX_LENGTH = size;
		this->size = 0;
	}
	~ArrayStack() {
		delete[] arr;
	}

	void push(int val) {
		if (size >= MAX_LENGTH) {
			cout << "stack is full" << endl;
			return;
		}
		arr[size++] = val;
	}
	int pop() {
		if (size < 0) {
			cout << "stack is empty" << endl;
			return 0;
		}
		int tmp = arr[--size];
		return tmp;
	}
};
int main()
{
	ArrayStack arrayStack(3);
	arrayStack.push(1);
	arrayStack.push(2);
	arrayStack.push(3);
	arrayStack.push(1);
	cout << arrayStack.pop() << endl;
	arrayStack.push(2);
	return 0;
}