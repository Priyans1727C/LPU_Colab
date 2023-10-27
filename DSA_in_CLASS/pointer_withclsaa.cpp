#include <iostream>
using namespace std;

class MyClass {
public:
    MyClass(int data) : pData(new int(data)) {}

    MyClass() {
        delete pData;
    }

    int getData() const {
        return *pData;
    }

private:
    int* pData;
};

int main() {
    MyClass obj(42);
    cout << "Data: " << obj.getData() <<endl;

    return 0;
}
