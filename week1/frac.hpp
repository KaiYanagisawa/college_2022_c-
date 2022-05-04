#include <numeric>
#include <iostream>
#include <sstream>

class Frac
{
public:
    int nume{0}, deno{1}, t{0};
    int get_nume() const { return nume; }
    int get_deno() const { return deno; }
    void set(int n, int d)
    {
        //符号判定
        if (n >= 0 && d >= 0)
        {
            nume = n;
            deno = d;
        }
        else if ((n < 0 && d < 0) || (n >= 0 && d < 0))
        {
            nume = -n;
            deno = -d;
        }
        else if (n < 0 && d >= 0)
        {
            nume = -n;
            deno = d;
        }

        ///既約分数処理
        t = std::gcd(n, d);
        if (t > 1)
        {
            nume /= t;
            deno /= t;
        }
    }
    std::string value() const
    {
        double quotient{static_cast<double>(nume) / static_cast<double>(deno)};

        std::ostringstream oss;
        oss << quotient;
        return oss.str();
    }
    std::string str() const
    {
        std::ostringstream oss;
        oss << nume
            << "/"
            << deno;
        return oss.str();
    }
};