#include <iostream>
#include "complex1.hpp"

//(2)演算子<<を一般関数で多重定義せよ
std::ostream &operator<<(std::ostream &o, const Complex c)
{
    if (c.geti() == 0 && c.getr() == 0)
        return o << c.getr();
    else if (c.geti() == 0)
        return o << c.getr() << "i";
    else if (c.getr() == 0)
        return o << c.geti();
    else if (c.getr() > 0)
        return o << c.geti() << "+" << c.getr() << "i";
    else
        return o << c.geti() << c.getr() << "i";
}

int main()
{
    Complex A{1, 3}, B{1}, C{1, -5}, D{}, E{};

    //複素数Dの値を入力
    std::cin >> D;

    //さまざまな計算結果を出力
    std::cout << "A+B=" << A + B << ", A+C=" << A + C << ", A+D="
              << A + D << ", E=" << E << "\n";

    return 0;
}