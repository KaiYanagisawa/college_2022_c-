#include <iostream>
#include <deque>
#include <string>

int main() {
    std::deque<std::string> history;
    std::string str{};

    while(true) {
        // cin で文字列を入力（str へ格納）
        std::cout << "Input: ";
        std::cin >> str;

        // 入力された文字列により処理を変更
        if (str == "show") {
            //
            // show を入力したときのプログラムを作成せよ
            //
        }
        else if (str == "undo") {
            std::cout << "Undo\n";
            //
            // undo を入力したときのプログラムを作成せよ
            //
        }
        else if (str == "exit") {
            // exit を入力すると終了
            std::cout << "Finished." << std::endl;
            return 0;
        }
        else {
            //
            // そのほかの文字列を入力したときのプログラムを作成せよ
            //
        }
    }
}