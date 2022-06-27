// ex06-1-main.cpp
#include <iostream>
#include <list>
using std::cin;
using std::cout;
using std::list;

void erase(list<int> &lst, int n)
{
	list<int> L1{}, L2{lst}; //�͂��߂� L2 �� lst ��ێ�
							 // ��ʊ֐��� erase �֐�������������
	for (auto &e : lst)
	{
		// n �����X�g�̗v�f e �ƈ�v���Ȃ���΁Ce �� L1 �̖����Ɋi�[�� L2 �̐擪���폜
		if (n != e)
		{
			L1.push_back(e);
			L2.pop_front();
		}
		// n �����X�g�̗v�f e �ƈ�v����΁Ce �� L1 �̖����Ɋi�[���邱�Ƃ͂����� L2 �̐擪�݂̂��폜
		else
			L2.pop_front();
	}
	L1.splice(L1.end(), L2); // L1 �̖����� L2 �����������
	lst = L1;				 // lst �� L1 �ōX�V
}

int main()
{
	list<int> L{1, 3, 8, 4, 5, 3, 5, 9};

	cout << "The original list is as follows:\nL0 = ";
	for (auto &e : L)
		cout << e << " ";
	cout << "\n";

	// �����o�֐��� erase() ���g���ėv�f���폜
	for (auto it = L.begin(); it != L.end(); it++)
	{
		if (*it == 3)
		{
			it = L.erase(it);
			break;
		}
	}

	cout << "\nBy finding '3' from the original list L0 and erasing it, \nL1 = ";
	for (auto &e : L)
		cout << e << " ";
	cout << "\n";

	// ��ʊ֐��� erase() ���g���ėv�f���폜
	cout << "\nSelect a number from the list L1 to erase: ";
	int x;
	cin >> x;
	erase(L, x);

	cout << "\nBy finding '" << x << "' from the list L1 and erasing it, \nL2 = ";
	for (auto &e : L)
		cout << e << " ";
	cout << "\n";
}