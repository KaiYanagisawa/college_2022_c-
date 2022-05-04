#include<iostream>
class Car{
    char name{};
    int pos{};
    char get_name()const { return name; }
    int get_pos() const{ return pos; }
    void setname(char n) { name = n; }
    void forward(int p) { pos = p; }

    void set_squares(){

    }
};