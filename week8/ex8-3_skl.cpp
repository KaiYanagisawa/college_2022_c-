#include <iostream>
#include <iterator>
#include <vector>


int main(int argc, const char * argv[]) {
    
    //vectorの定義
    std::vector<int> posi, nega;
   
    //(1)入力イテレータを使って入力処理
   

    
    //(2)非負数と負の数を２つの配列に振り分け
    for (     ){
   

      
    }
    
    //(3)出力イテレータを使って配列に格納した非負数と要素数の出力（x.sizeおよびサイズ関数の使用は禁止）
    if( /*イテレータを用いた要素数判定*/ ){
    std::copy(/*先頭要素のイテレータ*/,/*末尾要素のイテレータ*/, /*出力イテレータ(オブジェクトなし)*/));
    std::cout<<"Num of Plus = "<</*イテレータを用いた要素数の取得*/<<std::endl;
    }
    else
    std::cout<<"Num of Plus = 0"<<std::endl;
    
    //(4)出力イテレータを使って配列に格納した負の数と要素数の出力（x.sizeおよびサイズ関数の使用は禁止）
    if( /*イテレータを用いた要素数判定*/ ){
    std::copy(/*先頭要素のイテレータ*/,/*末尾要素のイテレータ*/, /*出力イテレータ(オブジェクトなし)*/);
    std::cout<<"Num of Minus = "<</*イテレータを用いた要素数の取得*/<<std::endl;
    }
    else
    std::cout<<"Num of Minus = 0"<<std::endl;
}