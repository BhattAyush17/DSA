#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Min-heapify (recursive)
void heapifyMin(int arr[], int n, int i) {
    int smallest = i;       // root
    int left = 2 * i + 1;   // left child
    int right = 2 * i + 2;  // right child

    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        heapifyMin(arr, n, smallest);
    }
}

// Max-heapify (recursive)
void heapifyMax(int arr[], int n, int i) {
    int largest = i;       // root
    int left = 2 * i + 1;  // left child
    int right = 2 * i + 2; // right child

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapifyMax(arr, n, largest);
    }
}

void buildMinHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; --i)
        heapifyMin(arr, n, i);
}

void buildMaxHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; --i)
        heapifyMax(arr, n, i);
}

void heapSortAscending(int arr[], int n) {
    // Use max-heap to sort in ascending order
    buildMaxHeap(arr, n);
    for (int i = n - 1; i > 0; --i) {
        swap(arr[0], arr[i]);          // move current max to end
        heapifyMax(arr, i, 0);        // heapify reduced heap
    }
}

void heapSortDescending(int arr[], int n) {
    // Use min-heap to sort in descending order
    buildMinHeap(arr, n);
    for (int i = n - 1; i > 0; --i) {
        swap(arr[0], arr[i]);
        heapifyMin(arr, i, 0);
    }
}

void printArr(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

// Simple MinHeap class using vector for dynamic operations
class MinHeap {
    vector<int> h;

    void siftUp(int idx) {
        while (idx > 0) {
            int parent = (idx - 1) / 2;
            if (h[parent] > h[idx]) {
                swap(h[parent], h[idx]);
                idx = parent;
            } else break;
        }
    }

    void siftDown(int idx) {
        int n = (int)h.size();
        while (true) {
            int left = 2 * idx + 1;
            int right = 2 * idx + 2;
            int smallest = idx;
            if (left < n && h[left] < h[smallest]) smallest = left;
            if (right < n && h[right] < h[smallest]) smallest = right;
            if (smallest != idx) {
                swap(h[idx], h[smallest]);
                idx = smallest;
            } else break;
        }
    }

public:
    MinHeap() = default;
    MinHeap(const vector<int>& arr) : h(arr) {
        // build heap in O(n)
        for (int i = (int)h.size() / 2 - 1; i >= 0; --i)
            siftDown(i);
    }

    void insert(int val) {
        h.push_back(val);
        siftUp((int)h.size() - 1);
    }

    int extractMin() {
        if (h.empty()) throw runtime_error("Heap is empty");
        int ret = h[0];
        h[0] = h.back();
        h.pop_back();
        if (!h.empty()) siftDown(0);
        return ret;
    }

    bool empty() const { return h.empty(); }

    void print() const {
        for (int x : h) cout << x << " ";
        cout << endl;
    }
};

int main() {
    int arr[] = {10, 5, 3, 2, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArr(arr, n);

    // Min-heap
    int minArr[5];
    copy(begin(arr), end(arr), begin(minArr));
    buildMinHeap(minArr, n);
    cout << "Min Heap: ";
    printArr(minArr, n);

    // Max-heap
    int maxArr[5];
    copy(begin(arr), end(arr), begin(maxArr));
    buildMaxHeap(maxArr, n);
    cout << "Max Heap: ";
    printArr(maxArr, n);

    // Heap sort ascending
    int asc[5];
    copy(begin(arr), end(arr), begin(asc));
    heapSortAscending(asc, n);
    cout << "Heap Sort Ascending: ";
    printArr(asc, n);

    // Heap sort descending
    int desc[5];
    copy(begin(arr), end(arr), begin(desc));
    heapSortDescending(desc, n);
    cout << "Heap Sort Descending: ";
    printArr(desc, n);

    // Demo MinHeap class
    vector<int> v = {10, 5, 3, 2, 4};
    MinHeap mh(v);
    cout << "MinHeap (vector-built): "; mh.print();
    mh.insert(1);
    cout << "After insert(1): "; mh.print();
    cout << "Extracting elements: ";
    while (!mh.empty()) cout << mh.extractMin() << " ";
    cout << endl;

    return 0;
}
