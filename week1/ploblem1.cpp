#include <iostream>
#include "frac.hpp"

void print(const Frac &f)
{
    std::cout << f.str() << " = " << f.value() << "\n";
}

int main()
{
    Frac a;
    print(a);
    a.set(2, 4);
    print(a);
    a.set(32, -128);
    print(a);
    a.set(-3, -9);
    print(a);
}