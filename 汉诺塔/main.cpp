// ��ŵ��
// ����������������̴�A���ƶ���C�̣�����B�̡�
// �����ݹ����������⣬Ҳ���Ǳ����ݹ�����
// �����������ޡ���Ч�ԡ�������
#include <iostream>
using namespace std;


void hanNuoTowel(int floor, char A, char help, char C) {
	if (floor == 1) {
		cout << "from->" << A << "->move to->" << C << endl;
	}
	else {
		hanNuoTowel(floor - 1, A, C, help);                     // ��ǰN-1�ƶ���help����
		cout << "from->" << A << "->move to->" << C << endl;    // �����һ���ƶ���Ŀ����
		hanNuoTowel(floor - 1, help, A, C);                     // ��help���ƶ���Ŀ����
	}	
}
int main(void) {
	hanNuoTowel(3, 'A', 'B', 'C');
	/*
	result:
		A->C
		A->B
		C->B
		A->C
		B->A
		B->C
		A->C
	*/

	return 0;
}