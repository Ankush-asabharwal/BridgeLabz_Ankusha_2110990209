#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

struct Person {
    string name;
    int age;
};

bool compareAge(const Person& a, const Person& b) {
    return a.age < b.age;
}

int main() {
    list<Person> people = {{"Alice", 25}, {"Bob", 30}, {"Charlie", 25}};
    stable_sort(people.begin(), people.end(), compareAge);
    for (const auto& person : people) {
        cout << person.name << " (" << person.age << ")" << endl;
    }
    return 0;
}
