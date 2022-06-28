#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <regex>

std::vector<std::string> split(std::string line)
{
    std::vector<std::string> result;
    int first{0};
    int last = line.find_first_of(' ');

    while (first < line.size())
    {
        std::string sub = line.substr(first, last - first);
        result.push_back(sub);

        first = last + 1;
        last = line.find_first_of(' ', first);

        if (last == std::string::npos)
            last = line.size();
    }

    return result;
}

void count(std::map<std::string, int> &wlist, std::string word)
{
    if (wlist.size() != 0)
    {
        if (auto it{wlist.find(word)}; it != wlist.end())
        {
            auto &[k, v]{*it};
            v++;
        }
        else
            wlist.insert({word, 1});
    }
    else
        wlist.insert({word, 1});
}

void print_map(std::map<std::string, int> wlist)
{
    for (auto [k, v] : wlist)
        std::cout << k << " :" << v << "\n";
}

int total_words(std::map<std::string, int> wlist)
{
    int total{0};
    for (auto [k, v] : wlist)
        total += v;
    return total;
}

int main() {

    std::cout << "----  Read file ----" << "\n";
    std::ifstream fin("prac3.txt");
    if (!fin) { std::cerr << "file open error\n"; return 1; }

    std::string line;
    int w1count{ 0 }, w2count{ 0 }, linenum{ 0 };   // 単語数，行数

    //空欄１：(1)冒頭はTかBである単語の正規表現
    std::regex r_TB{"(T|B).*"};
    //空欄２：(2)末尾はeである単語の正規表現
    std::regex r_e{".*e"};

    std::map<std::string, int> wlist1{}; // 空欄１に対応する単語と出現回数をpairとするmap
    std::map<std::string, int> wlist2{}; // 空欄２に対応する単語と出現回数をpairとするmap

    while (getline(fin, line))  // ファイルの終わりまで，ファイルから１行ずつlineへ読む 
    {
        ++linenum;  //行数をカウント

        //空欄３：正規表現に一致する単語の格納と出現回数の数え上げ
        for (auto word : split(line))
        {
            if (std::regex_match(word, r_TB))
                count(wlist1, word);
            if (std::regex_match(word, r_e))
                count(wlist2, word);
        }
    }

    // 空欄４：空欄１の正規表現に一致する単語と出現回数を表示 (単語のアルファベット順)
    print_map(wlist1);

    std::cout << "============================="
              << "\n";

    // 空欄５：空欄２の正規表現に一致する単語と出現回数を表示 (単語のアルファベット順)
    print_map(wlist2);

    //  空欄６： ファイルの行数，(1)の条件を満たした単語の総数，(2)の条件を満たした単語の総数，
    // (1)の条件を満たした単語の種類数，(2)の条件を満たした単語の種類数をそれぞれ表示

    std::cout << "---------\n";
    std::cout << "ファイルの行数:" << linenum << "\n"
              << "(1)の条件を満たした単語の総数:" << total_words(wlist1) << "\n"
              << "(2)の条件を満たした単語の総数:" << total_words(wlist2) << "\n"
              << "(1)の条件を満たした単語の種類数：" << wlist1.size() << "\n"
              << "(2)の条件を満たした単語の種類数：" << wlist2.size() << "\n";
}