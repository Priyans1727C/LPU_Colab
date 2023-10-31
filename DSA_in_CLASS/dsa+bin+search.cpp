#include "iostream"
#include "string.h"
using namespace std;

int main()
{
    int arr[] = {5, 9, 17, 23, 25, 45, 59, 63, 71, 89};
    int n = 9;
    int mid = n / 2;
    int find;
    cout << "enter element to find: ";
    cin >> find;
    if (find == arr[mid])
        cout << "Position is: " << mid;
    else if (find > arr[mid])
    {
        for (int i = mid + 1; i < n + 1; i++)
        {
            if (find == arr[i])
                cout << "Position is: " << i;
        }
    }
    else if (find < arr[mid])
    {
        for (int j = 0; j < mid; j++)
        {
            if (find == arr[j])
                cout << "Position is: " << j;
        }
    }
}