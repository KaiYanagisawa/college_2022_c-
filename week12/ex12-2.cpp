#include <iostream>
#include <vector>
#include <regex>

/*
  空欄1 文字列の受理可能性を順番に判定するcheck関数を作成しなさい．

*/

int main()
{
  std::vector<std::string> vec1{"a", "abc", "abd", "abd",
                                "abcbcd", "babd", "abcbd"};
  std::vector<std::string> vec2{"", "abcac", "aba", "caca",
                                "cacaca", "abcabc", "abcacaca"};

  std::regex r1{/* 空欄2 */}; //図2の有限オートマトンを受理する正規表現
  std::regex r2{/* 空欄3 */}; //図3の有限オートマトンを受理する正規表現

  check(r1, vec1);
  check(r2, vec2);
}