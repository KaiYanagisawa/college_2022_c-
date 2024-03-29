#include <iostream>
#include <string>
#include <map>
using std::cout, std::cin, std::string, std::map;

int main()
{
    map<string, int> cand;

    // 候補者名の入力
    for (int i = 0; i < 5; i++)
    {
        string name;
        std::cout << "Name? ";
        cin >> name;
        cand[name]++;
    }

    // 最大得票者の出力
    string max_name;
    map<string, int> sub_cand{cand};

    int max{}, i{};
    // for (auto [w, c] : sub_cand)
    // {
    //     if(i==0)
    //     max
    //     else if (c >= max)
    //         max = c;
    //     else
    //     {
    //         max_name = w;
    //         sub_cand.erase(max_name);
    //     }
    //     ++i;
    // }
    for (auto it = cand.begin(); it != cand.end(); it++)
    {
        if (i == 0)
            max = it->second;
        else
        {
            if (it->second >= max)
            {
                max = it->second;
                cand.erase(*(it - 1));
            }
        }

        i++;
    }
    for (auto [w, c] : sub_cand)
        cout << w << "\n";

    // Aliceの得票数の出力

    return 0;
}