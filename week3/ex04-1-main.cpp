// ex04-1-main.cpp
//
#include <iostream>
#include <vector>

int main()
{
    std::vector<char> Capture, Appear;

    // ７文字の入力とCapture配列への引き渡し
    std::vector<char> words(7);
    std::cin >> words[0] >> words[1] >> words[2] >> words[3] >> words[4] >> words[5] >> words[6];
    for (int i = 0; i < 7; i++)
    {
        Capture.push_back(words[i]);
    }

    // 入力した配列（単語）の出力
    for (auto cap : Capture)
    {
        std::cout << cap;
    }

    std::cout << std::endl;

    // 入力の逆順に文字をAppear配列に格納（push_backを使う）
    for (int i = 6; i >= 0; i--)
    {
        Appear.push_back(Capture[i]);
    }

    // 入力の逆順に格納した配列（単語）の出力
    for (auto app : Appear)
    {
        std::cout << app;
    }

    std::cout << std::endl;

    // Appear配列の全消去
    Appear.clear();

    // 3文字目以降をAppear配列に格納
    for (int i = 2; i < 7; i++)
    {
        Appear.push_back(Capture[i]);
    }

    // 末尾を削除
    Appear.pop_back();

    // Appear配列を出力
    for (auto app : Appear)
    {
        std::cout << app;
    }

    std::cout
        << std::endl;

    return 0;
}
