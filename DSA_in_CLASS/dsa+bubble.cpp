#include "iostream"
using namespace std;
int main()
{
    int arr[] = {25, 2, 8, 1, 6, 54};
    int n = 6;
    int temp;
    // for (int i = 0; i < n - 1; i++)
    // {
    //     for (int j = 0; j < n - 1 - 1; j++)
    //     {
    //         if (arr[j] > arr[j + 1])
    //         {
    //             temp = arr[j];
    //             arr[j] = arr[j + 1];
    //             arr[j + 1] = temp;
    //         }
    //     }
    // }

//  for(int i=0; i<n-1;i++){
//     for(int j=0;j<n)
//  }


    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

}