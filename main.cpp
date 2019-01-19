#include<iostream>
using namespace std;

int num(0);

class X{
public:
   X() {num++;}
   X& operator=(void* ptr) {
        if (ptr) num++;
        else num=0;
   }
    ~X() {num--; cout << "bi x" << endl;}
 };

class Y : public X {
    X _x;
    public:
    Y() {num++;}
    ~Y() {num--; cout << "bi y" << endl;}
};

int main() {
    X* x1 = new X; //num = 1
    X* x2 = new Y; //c'tor x -> num=2. c'tor y -> num=3. x object in y -> num=4
    cout << "1: " << num << endl; //num = 4
    delete x1; //num=3
    delete x2; //num=2
    cout << "2: " << num << endl; //num = 2
    return 0;
}