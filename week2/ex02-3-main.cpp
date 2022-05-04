#include <iostream>
#include "complex2.hpp"

//(0) 課題２で作成したものと同じように演算子<<を一般関数で多重定義せよ
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

    std::cin >> D;

    std::cout << "A=" << A << ", D=" << D << "\n";
    std::cout << "The modules of A is " << A.getModules() << "\n";
    std::cout << "The modules of D is " << D.getModules() << "\n";

    //絶対値を比較する
    if (A < D)
    {
        std::cout << "The modulus of A is smaller than the modulus of D."
                  << "\n";
    }

    return 0;
}