#include <cmath> //平方根の計算にstd::sqrt()を使う

class Complex
{
    int re{}, im{};

public:
    //コンストラクタの作成
    Complex(int r = 0, int i = 0)
    {
        re = r;
        im = i;
    }
    //ゲッター
    int getr() const { return re; }
    int geti() const { return im; }

    //(1) 絶対値を計算する関数を作ろう
    double getModules() const
    {
        double abs{std::sqrt(std::pow(re, 2) + std::pow(im, 2))};
        return abs;
    }

    //演算子>>のフレンド関数での多重定義
    friend std::istream &operator>>(std::istream &in, Complex &c)
    {
        return in >> c.re >> c.im;
    }

    //(2)演算子<をメンバ関数で多重定義せよ
    bool operator<(const Complex &D) const
    {
        return getModules() < D.getModules();
    }
};