#include <iostream>

using std::cin, std::cout, std::endl;

class roadcycle
{
public:
    roadcycle(); //コンストラクタ
    //（１−１）←デストラクタ
    ~roadcycle();
    void exercise();       //運動
    void eat(double food); //カロリー摂取

private:
    double calorie;  //カロリー
    double distance; //移動距離
};

//コンストラクタ
roadcycle::roadcycle() : calorie(1.0), distance(0)
{
    cout << "オブジェクト生成" << endl;
}
//デストラクタ
//（１ー２）
roadcycle::~roadcycle()
{
    cout << "オブジェクト破棄" << endl;
}

//運動
void roadcycle::exercise()
{
    //（２）残カロリーが運動１回の消費カロリー以上なら移動：1回の運動で1.8km移動、１回の運動でカロリーを1.2kJ消費
    if (calorie >= 1.2)
    {
        distance += 1.8;
        calorie -= 1.2;
    }

    cout << "移動距離: " << distance << "km" << endl;
    cout << "残カロリー: " << calorie << "kJ" << endl;
}
//カロリー摂取
void roadcycle::eat(double food)
{
    //（３） (１回の運動カロリー以下の場合、初期カロリーに摂取カロリーを加算

    if (calorie <= 1.2)
        calorie += food;

    cout << "累積カロリー: " << calorie << "kJ" << endl; //累積カロリー表示
}

int main()
{

    double num;

    cout << "摂取カロリー: ";
    cin >> num; //摂取カロリー入力

    roadcycle tour;
    tour.eat(num);   //カロリー摂取
    tour.exercise(); //運動

    cout << "摂取カロリー: ";
    cin >> num; //摂取カロリー入力

    tour.eat(num);   //カロリー摂取
    tour.exercise(); //運動

    return 0;
}
