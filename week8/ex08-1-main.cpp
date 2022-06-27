// ex08-1-main.cpp
#include <iostream>
#include <iterator>
#include <set>

double med(std::multiset<double> ms)
{
    //データの中央値を計算する
    int size = ms.size();
    if (size % 2 != 0)
    {
        for (int i = 0; i <= (ms.size() - 1) / 2; i++)
        {
            auto end{std::prev(ms.end())};
            ms.erase(ms.begin());
            ms.erase(end);
        }
        auto median{ms.begin()};
        return *median;
    }
    else
    {
        for (int i = 0; i <= ms.size() / 2 - 1; ++i)
        {
            auto end{std::prev(ms.end())};
            ms.erase(ms.begin());
            ms.erase(end);
        }
        auto s{ms.begin()};
        auto e{std::prev(ms.end())};
        double median{(*e + *s) / 2};
        return median;
    }
}

double mean(std::multiset<double> ms)
{
    //データの平均を計算する
    double sum, mean;
    for (auto it = ms.begin(); it != ms.end(); ++it)
        sum += *it;
    mean = sum / ms.size();
    return mean;
}

double var(std::multiset<double> ms)
{
    //データの分散を計算する
    double sum, var;
    for (auto it = ms.begin(); it != ms.end(); ++it)
        sum += (*it - mean(ms)) * (*it - mean(ms));
    var = sum / ms.size();
    return var;
}

int main()
{
    std::multiset<double> ms;
    std::istream_iterator<int> it{std::cin};
    std::istream_iterator<int> eos;

    for (; it != eos; ++it)
    {
        //ここを埋める（データの格納を行う．「>>演算子」は使用しないこと）
        double data;
        data = *it;
        ms.insert(data);
    }

    std::cout << "sort_data: "
              << "\n";
    for (const double e : ms)
    {
        std::cout << e << "\n";
    }

    std::cout << "median = " << med(ms) << "\n";
    std::cout << "mean = " << mean(ms) << "\n";
    std::cout << "variance = " << var(ms) << "\n";

    return 0;
}
