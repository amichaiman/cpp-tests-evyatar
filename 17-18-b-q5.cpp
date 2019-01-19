#include<iostream>

using namespace std;

class padrino {
public:
    // "compadre constructed
    padrino(string const &msg) : msg_(msg) { cout << msg << '\n'; }

    virtual string msg() const { return msg_; }

private:
    string msg_;
};

class comadre : virtual public padrino {
public:

    comadre(string const &str) : padrino("comadre(" + str + ") constructed") { cout << " comadre " << endl;}
};

class compadre : virtual public padrino {
public:
    //          1
    compadre(int x) : padrino("compadre constructed"), value_(x) { cout << " compadre " << endl;}

    virtual int value() const { return value_; }

private:
    int value_;
};

class hijo : public comadre, public compadre {
public:
    //       -1             memphis
    hijo(int i, string const &str) : padrino(str), comadre("junior"), compadre(1) {} // order of c'tors doesnt matter
                                    // only hijo can call padrino!
                                    // comadre and compadre are called based on the order in line 34

    int value() const { return compadre::value(); }

    virtual string msg() const { return compadre::msg() + ' ' + comadre::msg(); }
};

int main(void) {
    hijo h(-1, "Memphis!");
    cout << h.value() << ' ' << h.msg() << '\n';
    return 0;
}

