// #include<iostream>

// using namespace std;

// class driversClass {
// protected:
//     virtual void start() = 0;
//     virtual void accelerate() = 0;
//     virtual void stop() = 0;
// };

// class Car : public driversClass{
//     protected:
//     void start() override{
//         cout << "Car is starting" <<endl;
//     }
//     // void start() {
//     //     cout << "Car is starting with speed: _ km/h" << endl;
//     // }
//     void accelerate() override{
//         cout << "Car is accelerating" <<endl;
//     }
//     void stop() override{
//         cout << "Car is stop" <<endl;
//     }
//     void coolEngine() {
//         cout << "Cooling the engine" <<endl;
//     }
//     void igniteEngine() {
//         cout << "Igniting the engine" <<endl;
//     }
// };

// int main() {
//     driversClass* car = new Car();
//     car->accelerate();
//     car->stop();
//     car->start();
//     // car->coolEngine();
// }



#include<iostream>

using namespace std;
namespace bigCar {
class driversClass {
protected:
    virtual void start() = 0;
    virtual void accelerate() = 0;
    virtual void stop() = 0;
};

class Car : public driversClass{
    public:
    void start() override{
        cout << "Car is starting" <<endl;
    }
    void accelerate() override{
        cout << "Car is accelerating" <<endl;
    }
    void stop() override{
        cout << "Car is stop" <<endl;
    }
    void coolEngine() {
        cout << "Cooling the engine" <<endl;
    }
    void igniteEngine() {
        cout << "Igniting the engine" <<endl;
    }
};
}

int main() {
    bigCar::Car* car = new bigCar::Car();
    car->accelerate();
    car->stop();
    car->start();

    // bigCar::driversClass* car = new bigCar::Car();
    // car->accelerate();
    // car->stop();
    // car->start();

}