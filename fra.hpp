#include <numeric>
#include <iostream>
#include <sstream>

class Frac
{
public:
    int nume{0}, deno{1}, t{0};
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

        ///約分
        t = std::gcd(n, d);
        if (t > 0)
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
