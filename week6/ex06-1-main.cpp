// ex06-1-main.cpp
#include <iostream>
#include <list>
using std::cin;
using std::cout;
using std::list;

void erase(list<int> &lst, int n)
{
	list<int> L1{}, L2{lst}; //はじめは L2 に lst を保持
							 // 一般関数の erase 関数を完成させよ
	for (auto &e : lst)
	{
		// n がリストの要素 e と一致しなければ，e を L1 の末尾に格納し L2 の先頭を削除
		if (n != e)
		{
			L1.push_back(e);
			L2.pop_front();
		}
		// n がリストの要素 e と一致すれば，e を L1 の末尾に格納することはせずに L2 の先頭のみを削除
		else
			L2.pop_front();
	}
	L1.splice(L1.end(), L2); // L1 の末尾に L2 が結合される
	lst = L1;				 // lst を L1 で更新
}

int main()
{
	list<int> L{1, 3, 8, 4, 5, 3, 5, 9};

	cout << "The original list is as follows:\nL0 = ";
	for (auto &e : L)
		cout << e << " ";
	cout << "\n";

	// メンバ関数の erase() を使って要素を削除
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

	// 一般関数の erase() を使って要素を削除
	cout << "\nSelect a number from the list L1 to erase: ";
	int x;
	cin >> x;
	erase(L, x);

	cout << "\nBy finding '" << x << "' from the list L1 and erasing it, \nL2 = ";
	for (auto &e : L)
		cout << e << " ";
	cout << "\n";
}