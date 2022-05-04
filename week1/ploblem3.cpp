#include<iostream>
#include<vector>
#include "car.hpp"
using std::cin, std::cout, std::vector, std::string;
const int width{3}, height{3};
void print(const vector<Car> &vc); //マス目と車を出力
int main(){
    vector<Car> c(3);
    c[0].setname('a');
    c[0].forward(2);
    c[1].setname('b');
    c[1].forward(6);
    c[2].setname('c');
    c[2].forward(4);
    print(c);
    int n;
    while(cin>>n){
        c[2].forward(n);
        pirnt(c);
    }
}