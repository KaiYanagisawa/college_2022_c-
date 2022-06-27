#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <regex>

int main() {

    std::cout << "----  Read file ----" << "\n";
    std::ifstream fin("prac3.txt");
    if (!fin) { std::cerr << "file open error\n"; return 1; }

    std::string line;
    int w1count{ 0 }, w2count{ 0 }, linenum{ 0 };   // 単語数，行数

    //空欄１：(1)冒頭はTかBである単語の正規表現
    
    //空欄２：(2)末尾はeである単語の正規表現


    std::map<std::string, int> wlist1{}; // 空欄１に対応する単語と出現回数をpairとするmap
    std::map<std::string, int> wlist2{}; // 空欄２に対応する単語と出現回数をpairとするmap

    while (getline(fin, line))  // ファイルの終わりまで，ファイルから１行ずつlineへ読む 
    {
        ++linenum;  //行数をカウント

        //空欄３：正規表現に一致する単語の格納と出現回数の数え上げ


    }

    // 空欄４：空欄１の正規表現に一致する単語と出現回数を表示 (単語のアルファベット順)
    
    std::cout <<"=============================" << "\n";
    // 空欄５：空欄２の正規表現に一致する単語と出現回数を表示 (単語のアルファベット順)


    /* 空欄６： ファイルの行数，(1)の条件を満たした単語の総数，(2)の条件を満たした単語の総数，
    (1)の条件を満たした単語の種類数，(2)の条件を満たした単語の種類数をそれぞれ表示* /
}