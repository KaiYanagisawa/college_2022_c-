#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::cout, std::string;

class Flow
{
    string src_ip;   // 送信元IPアドレス
    string dst_ip;   // 宛先IPアドレス
    string protocol; // プロトコル番号
    int src_port;    // 送信元ポート番号
    int dst_port;    // 宛先ポート番号
public:
    Flow(string s, string d, string p, int sp, int dp) : src_ip{s}, dst_ip{d}, protocol{p}, src_port{sp}, dst_port{dp} {}
    string get_src_ip() const { return src_ip; }
    string get_dst_ip() const { return dst_ip; }
    string get_protocol() const { return protocol; }
    int get_src_port() const { return src_port; }
    int get_dst_port() const { return dst_port; }
    void print_flow() const
    {
        cout << "src ip=" << src_ip << ", dst_ip=" << dst_ip
             << ", protocol=" << protocol << ", src_port=" << src_port
             << ", dst_port=" << dst_port << "\n";
    }
    bool operator>(Flow &f)
    {
        return get_src_port() > f.get_src_port();
    }
    friend std::ostream &operator<<(std::ostream &out, const Flow f)
    {
        return out << "src ip=" << f.src_ip << ", dst_ip=" << f.dst_ip
                   << ", protocol=" << f.protocol << ", src_port=" << f.src_port
                   << ", dst_port=" << f.dst_port << "\n";
    }
};

void print(const std::vector<Flow> &ft)
{
    for (auto f : ft)
    {
        f.print_flow();
    }
}

// 課題1：指定したフローを先頭に追加する
auto add_flow(std::vector<Flow> &ft, const Flow &af)
{
    ft.insert(ft.begin(), af);
}

// 課題2: フローテーブルを送信元ポート番号の降順にソートする
auto sort_table(std::vector<Flow> &ft)
{
    std::sort(ft.begin(), ft.end(), [](Flow &alpha, Flow &beta)
              { return alpha > beta; });
}

// 課題3：https通信フロー数をカウントする
int count_https(const std::vector<Flow> &ft)
{
    return std::count_if(ft.begin(), ft.end(), [](Flow alpha)
                         { return alpha.get_protocol() == "tcp" && alpha.get_dst_port() == 443; });
}

// 課題4：指定条件に合致する通信フローをカウントする
int count_ip(const std::vector<Flow> &ft, string dst_ip)
{
    return std::count_if(ft.begin(), ft.end(), [&](Flow alpha)
                         { return alpha.get_dst_ip() == dst_ip; });
}

// 課題5：指定条件に合致するフローを検索し、出力する
auto dump_flows(const std::vector<Flow> &ft, string dst_ip)
{
    for (auto it = ft.begin(); it != ft.end(); it++)
    {
        auto result = std::find_if(it, ft.end(), [&](Flow alpha)
                                   { return alpha.get_dst_ip() == dst_ip; });
        if (it == result)
            std::cout << *it;
    }
}

int main(int argc, char *argv[])
{
    // フローテーブル
    std::vector<Flow> ft{
        {"172.31.5.64", "10.0.10.2", "tcp", 50200, 443},
        {"172.31.5.64", "10.0.10.3", "tcp", 50300, 443},
        {"172.31.5.64", "10.0.10.4", "udp", 50400, 8801},
        {"172.31.5.64", "10.0.10.5", "udp", 50500, 8801},
        {"172.31.5.64", "10.0.10.7", "udp", 50700, 8801},
        {"172.31.5.64", "10.0.30.8", "tcp", 50801, 443},
        {"172.31.5.64", "10.0.30.8", "tcp", 50802, 443},
        {"172.31.5.64", "10.0.30.8", "tcp", 50803, 443},
    };

    // 課題1：指定したフローを先頭に追加する
    Flow af = {"172.31.5.64", "10.0.10.1", "tcp", 50100, 500};
    add_flow(ft, af);
    cout << "1: flow table:\n";
    print(ft);
    cout << "\n";

    // 課題2: フローテーブルを送信元ポート番号の降順にソートする
    cout << "2: sorted flow table:\n";
    sort_table(ft);
    print(ft);
    cout << "\n";

    // 課題3：https通信フロー数をカウントする
    int cnt_https = count_https(ft);
    cout << "3: flow count of HTTPS: " << cnt_https << "\n";

    // 課題4：指定条件に合致する通信フローをカウントする
    string target = "10.0.30.8";
    int cnt_filter = count_ip(ft, target);
    cout << "4: flow count of dst_ip=" + target + ": " << cnt_filter << "\n";

    // 課題5：指定条件に合致するフローを検索し、出力する
    cout << "5: flow info of dst_ip=" + target << ":\n";
    dump_flows(ft, target);

    return 0;
}