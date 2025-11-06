#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i) {
    int smallest = i;       // root
    int left = 2 * i + 1;   // left child
    int right = 2 * i + 2;  // right child

    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    // If root is not smallest
    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        heapify(arr, n, smallest); // recursively heapify
    }
}

void buildMinHeap(int arr[], int n) {
    // start from last non-leaf node and heapify each
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
}

void printHeap(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {10, 5, 3, 2, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printHeap(arr, n);

    
    buildMinHeap(arr, n);


    cout << "Min Heap: ";
    printHeap(arr, n);

    return 0;
}
