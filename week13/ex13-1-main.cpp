#include <iostream>

int main(int argc, char *argv[])
{
    // 空欄1: Hi, (1 つ目のコマンド引数)!と出力する．

    if (/* 空欄2-1: 2つ目のコマンド引数の1文字目が - の場合 */)
    {
        // 空欄2-2: 2つ目のコマンド引数の2文字目が m なら Good Morning!, e なら Good Evening! と出力する．
    }
    std::cout << "\n";
}

// g++ -std=c++17 ex13-1-main_ans.cpp -o ex13-1  && ./ex13-1 Taro -m
// Hi, Taro! Good Morning!

//./ex13-1 Hanako -e
// Hi, Hanako! Good Evening!