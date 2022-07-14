// ex14-2-main_raw.cpp
#include <iostream>
#include <memory>

using std::cout, std::cin, std::endl;

struct Node
{
    int idata;
    std::shared_ptr<Node> next;
    Node(int a, std::shared_ptr<Node> np) : idata{a}, next{np} {}
    ~Node() { cout << "dtor: " << idata << "\n"; }
    void print() { cout << idata << " "; }
};

class Stack
{
    std::shared_ptr<Node> top; // スタックトップ
    int length;                // スタック内のデータ数（スタックの長さ）
public:
    Stack() : top{nullptr}, length{0} {} // コンストラクタ
    void push(int d);                    // スタックにデータをpushする
    int back();                          // スタックトップのデータを返す
    void pop();                          // スタックトップのデータを取り出す（取り除く）
    bool empty() { return length == 0; } // スタックが空かの判定
    int size() { return length; }        // スタックの長さを返す
    void print();                        // スタックの内容をすべて表示する
    ~Stack()                             // デストラクタ（先頭から順にpopする）
    {
        while (top != nullptr)
            pop();
    }
};

void Stack::push(int d)
{
    top = std::shared_ptr<Node>{new Node{d, top}};
    length++;
}

int Stack::back() { return top->idata; }

void Stack::pop()
{
    auto tmp{top};   // 解放する対象を覚えておく
    top = top->next; // 先頭の変更
    // delete tmp;      // 解放 ※スマートポインタを用いているのでdelete処理は不必要.
    length--;
}

void Stack::print()
{
    for (std::shared_ptr<Node> p{top}; p; p = p->next)
        cout << p->idata;
}

int main()
{
    Stack s, g, b;        // ３本の杭，s:スタート，g:ゴール，b:バッファ，
    int n;                // 円盤の数
    std::string from, to; // 始点と終点の入力
    Stack *fp, *tp;       // 始点と終点の杭を指すポインタ

    cout << "円盤の数--> ";
    cin >> n;
    for (int i{n}; i > 0; i--)
        s.push(i);

    for (int i{0}; i < n - s.size(); i++)
        cout << "-";
    s.print();
    cout << "-S\n";
    for (int i{0}; i < n - g.size(); i++)
        cout << "-";
    g.print();
    cout << "-G\n";
    for (int i{0}; i < n - b.size(); i++)
        cout << "-";
    b.print();
    cout << "-B\n";

    cout << "移動指示 : S (or s), G (or g), B (or b)\n";
    while (cout << "From -> To : " && cin >> from >> to)
    {
        if (from == "S" || from == "s")
            fp = &s;
        else if (from == "B" || from == "b")
            fp = &b;
        else if (from == "G" || from == "g")
            fp = &g;
        else
        {
            cout << "杭はS, B, Gの中から選んでください\n";
            continue;
        }
        if (to == "S" || to == "s")
            tp = &s;
        else if (to == "B" || to == "b")
            tp = &b;
        else if (to == "G" || to == "g")
            tp = &g;
        else
        {
            cout << "杭はS, B, Gの中から選んでください\n";
            continue;
        }

        if (fp->empty())
        {
            cout << "cannot move\n";
            continue;
        }
        if (!tp->empty() && tp->back() < fp->back())
        {
            cout << "cannot move\n";
            continue;
        }
        tp->push(fp->back());
        fp->pop();

        for (int i{0}; i < n - s.size(); i++)
            cout << "-";
        s.print();
        cout << "-S\n";
        for (int i{0}; i < n - g.size(); i++)
            cout << "-";
        g.print();
        cout << "-G\n";
        for (int i{0}; i < n - b.size(); i++)
            cout << "-";
        b.print();
        cout << "-B\n";

        if (g.size() == n)
        {
            cout << "Finished!\n";
            break;
        }
    }
    return 0;
}