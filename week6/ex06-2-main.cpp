#include <iostream>
#include <vector>
#include <set>
using std::cin, std::cout, std::string, std::set, std::vector;

int main()
{
    set<string> zoo;

    zoo.insert("monkey");
    zoo.insert("elephant");
    zoo.insert("rabbit");
    zoo.insert("panda");
    zoo.insert("bear");

    vector<string> search{"giraffe", "panda"};

    // find()�𗘗p���āCzoo�̒���search�̗v�f�����邩�m�F�D
    for (int i = 0; i < search.size(); i++)
    {
        auto it{std::find(zoo.begin(), zoo.end(), search[i])};
        if (it == zoo.end())
            cout << search[i] << " is not found.\n";
        else
            cout << search[i] << " is found."
                 << "\n";
    }
    //�W�����͂���V����������ǉ����C�ǉ��ł����̂��C���łɂ������̂����o�͂���D
    while (true)
    {
        string newcomer;
        cout << "Input newcomer:";
        cin >> newcomer;
        if (auto [it, flag]{zoo.insert(newcomer)}; flag)
            cout << *it << " is inserted.\n";
        else
            cout << *it << " has been already inserted.\n";
    }
}
