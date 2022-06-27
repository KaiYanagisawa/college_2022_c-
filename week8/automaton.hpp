#include <vector>
#include <set>
#include <map>
#include <iostream>
template <typename T>
class Automaton
{
    int start_state;                              //開始状態
    std::set<int> accept_states;                  //受理状態集合
    std::map<std::pair<int, T>, int> transitions; //遷移関数

public:
    Automaton<T>() {}

    //開始状態を取得する（本課題では使用しない）
    int get_start_state()
    {
        return start_state;
    }

    //開始状態を設定する
    void set_start_state(int q)
    {
        start_state = q;
    }

    //受理状態集合を取得する（本課題では使用しない）
    std::set<int> get_accept_states()
    {
        return accept_states;
    }

    //受理状態を追加する
    void add_accept_state(int q)
    {
    }

    //遷移関数を取得する（本課題では使用しない）
    std::map<std::pair<int, T>, int> get_transitions()
    {
        return transitions;
    }

    //遷移関数に遷移を追加する
    void add_transition(int from, T label, int to)
    {
    }

    //状態qが受理状態であればtrue, そうでなければfalseを返す
    bool is_accept_state(int q)
    {
    }

    //入力文字の列csが受理可能であればtrue, そうでなければfalseを返す
    bool accept(std::vector<T> cs)
    {
    }
}