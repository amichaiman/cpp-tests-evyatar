#include<iostream>

using namespace std;

class A {
    int _x;
public:
    A(int y = 0) : _x(y) {}

    char operator[](unsigned int k) {
        int mask = 1 << k; //k always 0. mask = 1
        return ((_x & mask) ? '1' : '0'); //_x rightmost bit is 0 or 1
    }
};

const int N = 6;

int main(void) {
    A _arr[N];                          //[A][A][A][A][A][A]
    for (int i = 0; i < N; i++) {
        _arr[i] = i + 1;                //try to call: A.operator=(const A& rhs). copy c'tor i+1 -> A
        cout << _arr[i][0] << ' ';      //calls A.operator[](int n)
    }
    cout << '\n';
    return 0;
}

