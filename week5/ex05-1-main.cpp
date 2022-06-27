#include <iostream>
#include <vector>
#include <stack>
using std::cout, std::cin, std::stack, std::vector;

const int n{2}; //ハノイの塔の高さ(円盤の枚数)

void print(vector<stack<int>> vs)
{ //ハノイの塔を出力する関数
    for (int i = 0; i < n; i++)
    {
        cout << " ";
        for (int j = 0; j < 3; j++)
        {
            if (vs[j].size() < (n - i))
                cout << "      ";
            else
            {
                cout << "--" << vs[j].top() << "-- ";
                vs[j].pop();
            }
        }
        cout << "\n";
    }
    cout << " ----------------- \n";
    cout << "  [0]   [1]   [2]  \n";
}

int main()
{
    vector<stack<int>> Hanoi(3); // 3つの棒(スタック)を用意

    /* (1) 棒0(Hanoi[0])の初期状態を設定せよ */
    for (int i = n; i > 0; i--)
    {
        Hanoi[0].push(i);
    }

    stack<int> goal{Hanoi[0]}; //棒0の状態を終了判定のためにコピーしておく
    int k{0};                  //円盤を動かす回数のカウンター
    print(Hanoi);              //初期状態を出力
    int From{}, To{};
    while (cin >> From >> To)
    { //円盤の移動元と移動先を入力

        //(2) 空欄を埋めて円盤を適切に動かせるようにしなさい
        if (From < 0 || From > 2 || To < 0 || To > 2)
            cout << "cannot move\n";
        else if (Hanoi[From].empty())
            cout << "cannot move\n";
        else if (!Hanoi[To].empty() && Hanoi[From].top() > Hanoi[To].top())
            cout << "cannot move\n";
        else
        {
            Hanoi[To].push(Hanoi[From].top());
            Hanoi[From].pop();
        }

        print(Hanoi); //移動後の状態を出力
        k++;          //カウンターに+1
        if (Hanoi[1] == goal)
        { //終了判定
            cout << "Finished! " << k << "steps\n";
            break;
        }
    }
}