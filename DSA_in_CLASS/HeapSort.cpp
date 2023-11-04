#include <bits/stdc++.h>
using namespace std;

void swap(int arr[], int x, int y)
{
    int temp = arr[x];
    arr[x] = arr[y];
    arr[y] = temp;
}

void heapify(int arr[], int n, int i)
{
    int larger = i;
    int left = (2 * i) + 1;
    int right = (2 * i) + 2;

    if (arr[right] > arr[larger] && right < n)
        larger = right;
    if (arr[left] > arr[larger] && left < n)
        larger = left;

    if (larger != i)
    {
        swap(arr, larger, i);
        heapify(arr, n, larger);
    }
}

void buildMaxHeap(int arr[], int n)
{
    for (int i = (n / 2) - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
}

void heapSort(int arr[], int n)
{
    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr, i, 0);
        heapify(arr, i, 0);
    }
}

int main()
{
    int arr[100];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    buildMaxHeap(arr, n);

    cout << "heap: ";
    for (int i = 0; i < n; i++)
    {
        cout << " " << arr[i];
    }
    heapSort(arr, n);

    cout << "\nshorted heap: ";
    for (int i = 0; i < n; i++)
    {
        cout << " " << arr[i];
    }
}
