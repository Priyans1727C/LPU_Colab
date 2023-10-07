#include <iostream>
#include <cstring>

using namespace std;

void swap(char*& a, char*& b) {
    char* temp = a;
    a = b;
    b = temp;
}

int partition(char *names[], int heights[], int low, int high) {
    int pivot = heights[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (heights[j] > pivot) {
            i++;
            swap(names[i], names[j]);
            swap(heights[i], heights[j]);
        }
    }

    swap(names[i + 1], names[high]);
    swap(heights[i + 1], heights[high]);
    return i + 1;
}

void quickSort(char *names[], int heights[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(names, heights, low, high);

        quickSort(names, heights, low, pivotIndex - 1);
        quickSort(names, heights, pivotIndex + 1, high);
    }
}

int main() {
    int N;
    cin >> N;
    char* names[N];
    int heights[N];

    for (int i = 0; i < N; i++) {
        names[i] = new char[100]; 
        cin >> names[i] >> heights[i];
    }

    quickSort(names, heights, 0, N - 1);

    for (int i = 0; i < N; i++) {
        cout << names[i] << " ";
        delete[] names[i];
    }

    return 0;
}
