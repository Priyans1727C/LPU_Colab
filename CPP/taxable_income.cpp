#include <iostream>
#include <string>

using namespace std;

class PartA {
public:
    string name;
    string PAN;

    PartA(const string &n, const string &pan) : name(n), PAN(pan) {}
};

class PartB : public PartA {
public:
    int grossSalary;
    int incomeOtherSources;

    PartB(const string &n, const string &pan, int salary, int otherSources)
        : PartA(n, pan), grossSalary(salary), incomeOtherSources(otherSources) {}
};

class PartC : public PartA {
public:
    int deductions;

    PartC(const string &n, const string &pan, int deduct) : PartA(n, pan), deductions(deduct) {}
};

class TaxComp : public PartB, public PartC {
public:
    TaxComp(const string &n, const string &pan, int salary, int otherSources, int deduct)
        : PartB(n, pan, salary, otherSources), PartC(n, pan, deduct) {}

    void calculateTax() {
        int taxableIncome = grossSalary + incomeOtherSources - deductions;
        int taxPayable = 0.3 * taxableIncome;
        cout << "Income Tax Calculation" << endl;
        cout << "Account Holder Name: " << name << endl;
        cout << "PAN: " << PAN << endl;
        cout << "Gross Salary: " << grossSalary << endl;
        cout << "Income from Other Sources: " << incomeOtherSources << endl;
        cout << "Deductions: " << deductions << endl;
        cout << "Taxable Income (computed): " << taxableIncome << endl;
        cout << "Tax Payable (computed): " << taxPayable << endl;
    }
};

int main() {
    string name, PAN;
    int grossSalary, incomeOtherSources, deductions;

    cin >> name >> PAN >> grossSalary >> incomeOtherSources >> deductions;

    TaxComp taxForm(name, PAN, grossSalary, incomeOtherSources, deductions);
    taxForm.calculateTax();

    return 0;
}
