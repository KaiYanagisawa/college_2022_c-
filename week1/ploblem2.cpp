#include<iostream>
#include "frac.hpp"

void print(const Frac& f){
    std::cout << f.str() << " = " << f.value() << "\n";
}
Frac add(const Frac& a,const Frac& b){
    Frac f;

    //分数計算
    if (a.get_deno() == b.get_deno())
    {
        f.set(a.get_nume() + b.get_nume(), a.get_deno());
    }
    else
    {
        //最大公倍数
        int lcm { a.get_deno()*b.get_deno()/std::gcd(a.get_deno(),b.get_deno())};

        f.set(a.get_nume() * lcm / a.get_deno() + b.get_nume() * lcm / b.get_deno(), lcm);
    }
    return f;
}
int main(){
    Frac a, b, c;
    a.set(1, 3);
    b.set(4, 5);
    c = add(a, b);
    print(c);
    print(add(a, a));
}