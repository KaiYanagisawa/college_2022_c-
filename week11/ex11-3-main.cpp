// ex11-3-main.cpp
#include <algorithm>
#include <vector>
#include <string>
#include <numeric>
#include <iostream>

class Student
{
private:
    std::string name;
    bool gender; // true-> male, false->female
    int score;

public:
    Student(std::string name, bool gender, int score) : name(name), gender(gender), score(score) {}
    bool getGender() const { return gender; }
    int getScore() const { return score; }
    std::string getName() const { return name; }
    bool operator>(const Student s)
    {
        return getScore() > s.getScore();
    }
    int operator+(const Student &b)
    {
        return getScore() + b.getScore();
    }
};

int main()
{
    std::vector<Student> students;
    students.push_back(Student("haruto", true, 66));
    students.push_back(Student("mio", false, 90));
    students.push_back(Student("souta", true, 84));
    students.push_back(Student("minato", true, 77));
    students.push_back(Student("mei", false, 96));
    students.push_back(Student("haruki", true, 59));

    // 学生を点数の降順にソートする（実験課題11-1）
    std::sort(students.begin(), students.end(), [](Student &alpha, Student &beta)
              { return alpha > beta; });

    for (int i = 0; i < students.size(); i++)
        std::cout << "Score: " << students[i].getScore() << "(Name: " << students[i].getName() << ")\n";

    // 学生の合計点を出力する
    int total{std::accumulate(students.begin(), students.end(), 0, [](Student &alpha, Student &beta)
                              { return alpha + beta; })}; // accumulate とラムダ式を用いて実装すること
    std::cout << "Total score: " << total << "\n";

    // // 学生の点数の平均を計算する
    // double ave{};
    // std::cout << "Average: " << ave << "\n";

    // // 学生の点数の中央値を計算する
    // // -(3)-
    // std::cout << "Median: " << med << "\n";

    // // 学生の点数の分散を計算する
    // // inner_product を使用して実装すること．必要に応じて得点用のvector を用意しても良い
    // std::cout << "Variance: " << var << "\n";

    return 0;
}

/* g++ -std=c++17 ex11-3-main.cpp  && ./a.out
Score: 96(Name: mei)
Score: 90(Name: mio)
Score: 84(Name: souta)
Score: 77(Name: minato)
Score: 66(Name: haruto)
Score: 59(Name: haruki)
Total score: 472
Average: 78.6667
Median: 80.5
Variance: 167.889
*/