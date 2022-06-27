#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <regex>

int main(int argc, char *argv[])
{
    // コマンド引数の確認
    if (argc < 2)
    {
        std::cout << "usage: " << argv[0] << " filename\n";
        return 1;
    }
    // ファイル読み込み
    std::string filename{argv[1]};
    std::ifstream fin(filename.c_str());
    if (!fin)
    {
        std::cout << "file open error\n";
        return 1;
    }
    // ファイル内の単語をvector配列のwordsへ格納する
    std::string w;
    std::vector<std::string> words;
    while (fin >> w)
    {
        words.push_back(w);
    }

    std::cout << "Method 1.\n";
    // [方法1] findを用いて単語に"com"が含まれるか判定し，含まれている場合は出力する
    std::string s{"com"};
    for (auto word : words)
    {
        size_t p{word.find(s)};
        if (p != std::string::npos)
            std::cout << word << " ";
    }
    std::cout << "\n";

    std::cout << "Method 2.\n";
    // [方法2] 正規表現を用いて"com"が含まれるか判定し，含まれている場合は出力する
    std::regex r{".*com.*"};
    for (auto word : words)
    {
        if (std::regex_match(word, r))
            std::cout << word << " ";
    }
    std::cout << "\n";

    return 0;
}