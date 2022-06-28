#include <iostream>
#include <vector>
#include <regex>

/*
  空欄1 文字列の受理可能性を順番に判定するcheck関数を作成しなさい．

*/
void check(std::regex r, std::vector<std::string> vec)
{
  std::cout << "----------\n";
  for (auto v : vec)
    (std::regex_match(v, r)) ? std::cout << v << ": accept\n" : std::cout << v << ": reject\n";
}

int main()
{
  std::vector<std::string> vec1{"a", "abc", "abd", "abd",
                                "abcbcd", "babd", "abcbd"};
  std::vector<std::string> vec2{"", "abcac", "aba", "caca",
                                "cacaca", "abcabc", "abcacaca"};

  std::regex r1{"ab(cb)*d"};      //図2の有限オートマトンを受理する正規表現
  std::regex r2{"((ab|ca)c*a)+"}; //図3の有限オートマトンを受理する正規表現

  check(r1, vec1);
  check(r2, vec2);
}