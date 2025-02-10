// Polymorphism

// #include <iostream>

// using namespace std;

// class First 
// {
//     public:
//     void display()
//     {
//         cout << "This is my Base class" << endl;
//     }
// };

// class Second : public First 
// {
//     public :
//     virtual void display()
//     {
//         cout << "This is my derived class" << endl;
//     }
// };

// int main()
// {
//     Second obj;
//     obj.display();
//     return 0;
// }


// Second Example

// #include <iostream>
// using namespace std;

// class Calculator {
// public:
//     int add(int a, int b) {
//         return a + b;
//     }
//     int add(int a, int b, int c) {
//         return a + b + c;
//     }
//     float add(float a, float b) {
//         return a + b;
//     }
//     string add(string a, string b) {
//         return a + b;
//     }
// };

// int main() {
//     Calculator calc;

//     cout << "Sum of 10 and 20: " << calc.add(10, 20) << endl;               
//     cout << "Sum of 10, 20, and 30: " << calc.add(10, 20, 30) << endl;     
//     cout << "Sum of 1.5 and 2.5: " << calc.add(1.5f, 2.5f) << endl;        
//     cout << "Concatenation of 'Hello' and ' World': " << calc.add("Hello", " World") << endl; 

//     return 0;
// }


//Operator Overloading

#include <iostream>
using namespace std;

class Number {
private:
    int value;

public:
    Number(int v = 0) : value(v) {}
    Number operator+(const Number& obj) {
        return Number(value + obj.value);
    }
    void display() const {
        cout << value << endl;
    }
};

int main() {
    Number n1(10);  
    Number n2(20);  
    Number n3    = n1 + n2;  
    cout << "First Number: ";
    n1.display();
    cout << "Second Number: ";
    n2.display();
    cout << "Sum: ";
    n3.display();
    return 0;
}

// kya h
// importance kya h
// where to use apllication of that 
// one example
// 
