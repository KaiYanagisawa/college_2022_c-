#include "./automaton.hpp"
#include <iostream>

template <typename T>
void test(Automaton<T> &A, const std::vector<T> &cs, bool expected)
{
    for (auto c : cs)
    {
        std::cout << c << " ";
    }
    bool result = A.accept(cs);
    std::cout << "-> " << (result ? "accepted" : "rejected") << " " << (result == expected ? "OK" : "NG") << std::endl;
}