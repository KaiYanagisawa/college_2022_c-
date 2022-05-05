    /*(3)
       ・キーボード入力した値をx[1]に挿入する
       ・vector yの先頭にvector xの最後の要素を挿入する
       ・y[2]の要素を削除する
    */
    y.insert(y.begin(), x[1]);
    y.erase(y.begin() + 2);

    cout << "\n------------\n";
    cout << "x: ";
    print(x);
    cout << "\n";
    cout << "y: ";
    print(y);
    cout << "\n";

    cout << std::boolalpha;
    cout << "x == y " << (x == y) << "\n";
    cout << "x != y " << (x != y) << "\n";
    cout << "x <  y " << (x < y) << "\n";
    cout << "x <= y " << (x <= y) << "\n";
    cout << "x >  y " << (x > y) << "\n";
    cout << "x >= y " << (x >= y) << "\n";
