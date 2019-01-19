#include<iostream>
#include <typeinfo>
using namespace std;

template<int id>
class Minerva {
    public:
    Minerva() {
        cout << typeid(*this).name() << " " << id <<" ctor " << endl;
    }
    ~Minerva() {
        cout << typeid(*this).name() << " " << id <<" dtor " << endl;
    }
};

class X : public Minerva<0> {
    Minerva<1> m1;
    public:
    X() { cout << "X::X()" << endl; }
    ~X() { cout << "X::~X()" << endl; }
};

int main(void) {
   X x;
   return 0;
 }