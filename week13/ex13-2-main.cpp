#include<iostream>
using std::cout; using std::cin;

// 配列 a の先頭 n 個の要素から値 key を線形探索（逐次探索）
int array_search(int a[], int n, int key) {
	int* p{ a };
	while (n-- > 0) {
		if (p[0] == key) return /*空欄(1)*/; // 探索成功
		else p++;
	}
	return -1; // 探索失敗
}

int main() {
	int key, idx;
	int x[5]; // int[5] 型の配列（要素型が int 型で要素数 5 の配列）
	int x_size = /*空欄(2)*/ / sizeof(x[0]); // 配列 x の要素数

	// 空欄(3): 配列 x に整数値を格納

	// 空欄(4): 検索キーワード key の入力

	if ((idx = /*空欄(5)*/) != -1)
		cout << "The value is in x[" << idx << "].\n";
	else
		cout << "Not found.\n";
}