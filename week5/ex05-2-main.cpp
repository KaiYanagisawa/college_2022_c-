#include <iostream>
#include <queue>
#include <string>

int main()
{
    std::string s{};

    // queueの初期化
    std::queue<std::string> q, q_sub;

    // 5回の入力を実行
    for (int i = 0; i < 5; i++)
    {
        // cin で値を入力する
        std::cout << "Input: ";
        std::cin >> s;

        // queue へ格納
        if (q.empty())
            q_sub.push(s);
        else if (q_sub.empty())
            q.push(s);

        // queue が 4 以上のときに先頭の要素を取り出す
        if (q.size() >= 4)
            q.pop();
        else if (q_sub.size() >= 4)
            q_sub.pop();

        // queue の中身を表示, 注意：begin()関数は使えない
        std::cout << "history: ";
        if (q.empty())
        {
            while (!q_sub.empty())
            {
                std::cout << q_sub.front() << " ";
                q.push(q_sub.front());
                q_sub.pop();
            }
        }
        else if (q_sub.empty())
        {
            while (!q.empty())
            {
                std::cout << q.front() << " ";
                q_sub.push(q.front());
                q.pop();
            }
        }

        std::cout << "\n";
    }
    return 0;
}