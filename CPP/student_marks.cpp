#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Student {
public:
    string name;
    int physics;
    int chemistry;
    int mathematics;
    int rollNumber;

    Student(string n, int p, int c, int m, int r) : name(n), physics(p), chemistry(c), mathematics(m), rollNumber(r) {}

    void display() {
        int total = physics + chemistry + mathematics;
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Name: " << name << endl;
        cout << "Total marks: " << total << endl << endl;
    }
};

int main() {
    int n;
    cin >> n;

    vector<Student> students;
    for (int i = 0; i < n; i++) {
        string name;
        int physics, chemistry, mathematics;
        cin.ignore();
        getline(cin, name);
        cin >> physics >> chemistry >> mathematics;
        students.emplace_back(name, physics, chemistry, mathematics, i + 1);
    }

    int totalClassMarks = 0;
    for (int i = 0; i < n; i++) {
        students[i].display();
        int total = students[i].physics + students[i].chemistry + students[i].mathematics;
        totalClassMarks += total;
    }

    cout << "Total marks of the class is: " << totalClassMarks << endl;
    cout << "The average marks of the class is: " << (totalClassMarks / static_cast<float>(n)) << endl;

    return 0;
}
