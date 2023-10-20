#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct Item {
    string name;
    int number;
    double price;
    int discountPercent;
};

int main() {
    int cnt;
    cin >> cnt;
    
    Item items[cnt];
    
    double totalPrice = 0.0;
    double totalDiscount = 0.0;
    
    for (int i = 0; i < cnt; i++) {
        cin.ignore();  // Clear the newline character left in the buffer.
        
        cout << "Details of item " << (i + 1) << " :" << endl;
        
        cout << "1. Item Name: ";
        getline(cin, items[i].name);
        
        cout << "2. Item No.: ";
        cin >> items[i].number;
        
        cout << "3. Item Price: ";
        cin >> items[i].price;
        
        cout << "4. Discount Percent: ";
        cin >> items[i].discountPercent;
        
        double discountedPrice = items[i].price * (1.0 - items[i].discountPercent / 100.0);
        cout << "5. Discounted Price: " << fixed << setprecision(2) << discountedPrice << endl;
        
        totalPrice += items[i].price;
        totalDiscount += items[i].price - discountedPrice;
    }
    
    for (int i = 0; i < cnt; i++) {
        cout << endl;
    }
    
    cout << "Total Price: " << fixed << setprecision(2) << totalPrice << endl;
    cout << "Total Discount: " << fixed << setprecision(2) << totalDiscount << endl;
    
    return 0;
}
