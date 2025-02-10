#include <iostream>
using namespace std;

class A {
public:
    void display() {
        cout << "Class A display function" << endl;
    }
};

class B : virtual public A {
    public:
    void display1() {
        cout << "Class B display function" << endl;
    }
};

class C : virtual public A {
    public:
    void display2() {
        cout << "Class C display function" << endl;
    }
};

class D :  public B, public C{
    public:
    void display() {
        cout << "Class D display function" << endl;
    }
};

int main() {
    D obj;
    obj.display();
    return 0;
}
