// ex04-2-main.cpp
#include <vector>
#include <iostream>
using std::cin, std::cout, std::vector, std::string;

//(1) 実行例のようにvectorの要素を出力するprint 関数を作成する
void print(vector<int> p)
{
    for (auto a : p)
        std::cout << a << " ";
}

int main()
{
    vector<int> x;
    vector<int> y;

    cout << "Input elements of a vector x.\n";

    //(2) vector xの要素（整数値）となる一桁の数字（文字）の並びを入力する処理
    //（ただし，#が入力されたら格納を終了する）
    for (int i = 0;; i++)
    {
        char num;
        cout << "x[" << i << "] = ";
        cin >> num;
        if (num == '#')
            break;
        x.push_back(int(num - '0'));
    }

    cout << "\n";
    cout << "Input elements of a vector y.\n";

    //(2) vector yの要素（整数値）となる一桁の数字（文字）の並びを入力する処理
    //（ただし，#が入力されたら格納を終了する）
    for (int i = 0;; i++)
    {
        char num;
        cout << "y[" << i << "] = ";
        cin >> num;
        if (num == '#')
            break;
        y.push_back(int(num - '0'));
    }

    cout << "Input number: ";
    int t{};
    cin >> t; // x[1]に挿入するための変数t

    cout << "\n--original--\n";
    cout << "x: ";
    print(x);
    cout << "\n";
    cout << "y: ";
    print(y);
    cout << "\n";
    cout << std::boolalpha;
    cout << "x == y " << (x == y) << "\n";
    cout << "x != y " << (x != y) << "\n";
    cout << "x <  y " << (x < y) << "\n";
    cout << "x <= y " << (x <= y) << "\n";
    cout << "x >  y " << (x > y) << "\n";
    cout << "x >= y " << (x >= y) << "\n";

    /*(3)
       ・キーボード入力した値をx[1]に挿入する
       ・vector yの先頭にvector xの最後の要素を挿入する
       ・y[2]の要素を削除する
    */
    x.insert(x.begin() + 1, t);
    y.insert(y.begin(), x.back());
    y.erase(y.begin() + 2);

    cout << "\n------------\n";
    cout << "x: ";
    print(x);
    cout << "\n";
    cout << "y: ";
    print(y);
    cout << "\n";

    cout << std::boolalpha;
    cout << "x == y " << (x == y) << "\n";
    cout << "x != y " << (x != y) << "\n";
    cout << "x <  y " << (x < y) << "\n";
    cout << "x <= y " << (x <= y) << "\n";
    cout << "x >  y " << (x > y) << "\n";
    cout << "x >= y " << (x >= y) << "\n";
}