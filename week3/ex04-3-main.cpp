// ex04-3-main.cpp
//
#include <iostream>
#include "myvec.hpp"
using std::cin, std::cout, std::vector;

//(1) print

int main() {
    MyVec<char> x, y;
       
    cout << "Input elements of a vector x.\n";
    //(2) input x

    cout << "Input elements of a vector y.\n";
    //(3) input y


    cout << std::boolalpha;
    cout << "x == y " << (x == y) << "\n"; //(4) operator==
    
    cout << "Reversal of order.\n";
    y.reverse(); //(5) reverse

    print(y);
    cout << "\n";

    cout << "Add elements.\n";
    //(6) add y

    print(y);
    cout << "\n";

    cout << "x == y " << (x == y) << "\n"; //(4) operator==

    return 0;
}