#include <iostream>
#define MAX_SIZE 100

using namespace std;


int main(){
    int arr[MAX_SIZE], size, pos, value;
    cin >> size;
    
    for(int i = 0; i < size; i++){
        cin >> arr[i];
    }
    
    cin >> pos >> value;
    
    if(pos < 1 || pos > size + 1) {
        cout << "Original array: ";
        for(int i = 0; i < size; i++){
            cout << arr[i] << " ";
        }
        cout << "\nInvalid position!";
        return 0;
    }
    
    cout << "Original array: ";
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    
    for(int i = size; i >= pos; i--){
        arr[i] = arr[i - 1];
    }
    
    arr[pos - 1] = value;
    
    cout << "\nUpdated array: ";
    for(int i = 0; i <= size; i++){
        cout << arr[i] << " ";
    }
    
    return 0;
}
