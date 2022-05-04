class Complex
{
    //実部と虚部をそれぞれ表す整数reとim
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

    //(1)演算子＋をメンバ関数で多重定義せよ
    Complex operator+(const Complex a)
    {
        Complex sum{geti() + a.geti(), getr() + a.getr()};
        return sum;
    }

    //演算子>>のフレンド関数での多重定義
    friend std::istream &operator>>(std::istream &in, Complex &c)
    {
        return in >> c.re >> c.im;
    }
};