// ex08-2-main.cpp
#include <iostream>
#include <map>
#include <list>
#include "random.hpp"

void count(const std::list<char> &data, std::map<char, std::string> &histogram)
{
    // 1
    for (auto d : data)
    {
        std::string s{"-"};
        // auto it{std::find(data.begin(), data.end(), d)};
        auto r{histogram.equal_range(d)};
        histogram.insert({d, s});
        for (auto it = r.first; it != r.second; ++it)
        {
            auto &[k, v]{*it};
            v += s;
        }
    }
}
void print(const std::map<char, std::string> &histogram)
{
    // 2
    for (auto [k, v] : histogram)
        std::cout << k << " " << v << "\n";
}

int main()
{
    const size_t N{100};
    ExpDist e(0.5);
    std::list<char> data;
    std::map<char, std::string> histogram;

    for (size_t i{0}; i < N; i++)
        data.insert(data.begin(), e.get() + 97);

    count(data, histogram);
    print(histogram);

    return 0;
}