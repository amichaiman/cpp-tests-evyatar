#include<iostream>
#include <memory>

using namespace std;

class Live {
    string _name;
public:
    Live(const char *init) : _name(init) {}

    ~Live() { cout << _name << endl; }
};

class LiveException : public exception {
};

void foo() throw(LiveException) {
    auto_ptr<Live> LF(new Live("foo")); //Live object with "foo"    ON THE STACK!
    throw LiveException();              // DESTRUCTOR OF OBJECTS ON THE STACK THAT WERE DEFINED IN FOO!
                                        // call LF d'tor
}

void goo() throw(LiveException) {
    Live LG("goo"); //Live object with "goo"    ON THE STACK!
    foo();              //not in a try catch statement.
                        // DESTRUCTOR OF OBJECTS ON THE STACK THAT WERE DEFINED IN FOO!
                        // call LG d'tor
}

int main(void) {
    try {
        goo();
    } catch (exception &e) { //first exception that contains our exception
        cerr << "Papa Exception\n";
        return 1;
    } catch (LiveException &e) {
        cerr << "Figlio Exception\n";
        return 1;
    }
    return 0;
}
