#include <iostream>
#include <iomanip>

using namespace std;

class Employee {
protected:
    int empId;
    float salary;

public:
    Employee(int id, float sal) : empId(id), salary(sal) {}

    void display() {
        cout << "Employee ID: " << empId << endl;
        cout << "Salary: $" << fixed << setprecision(2) << salary << endl;
    }
};

class empLevel : public Employee {
public:
    empLevel(int id, float sal) : Employee(id, sal) {}

    void display() {
        Employee::display();
        if (salary > 100) {
            cout << "Level: 1" << endl;
        } else {
            cout << "Level: 2" << endl;
        }
    }
};

int main() {
    int empId;
    float salary;

    cin >> empId >> salary;

    empLevel emp(empId, salary);
    emp.display();

    return 0;
}
