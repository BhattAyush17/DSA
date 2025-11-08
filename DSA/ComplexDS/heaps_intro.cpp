#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stdexcept>

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
    copy(arr, arr + n, minArr);
    buildMinHeap(minArr, n);
    cout << "Min Heap: ";
    printArr(minArr, n);

    // Max-heap
    int maxArr[5];
    copy(arr, arr + n, maxArr);
    buildMaxHeap(maxArr, n);
    cout << "Max Heap: ";
    printArr(maxArr, n);

    // Heap sort ascending
    int asc[5];
    copy(arr, arr + n, asc);
    heapSortAscending(asc, n);
    cout << "Heap Sort Ascending: ";
    printArr(asc, n);

    // Heap sort descending
    int desc[5];
    copy(arr, arr + n, desc);
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

// --- Additional heap utilities and MaxHeap class ---

// Max-heap class (dynamic)
class MaxHeap {
    vector<int> h;

    void siftUp(int idx) {
        while (idx > 0) {
            int parent = (idx - 1) / 2;
            if (h[parent] < h[idx]) {
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
            int largest = idx;
            if (left < n && h[left] > h[largest]) largest = left;
            if (right < n && h[right] > h[largest]) largest = right;
            if (largest != idx) {
                swap(h[idx], h[largest]);
                idx = largest;
            } else break;
        }
    }

public:
    MaxHeap() = default;
    MaxHeap(const vector<int>& arr) : h(arr) {
        for (int i = (int)h.size() / 2 - 1; i >= 0; --i)
            siftDown(i);
    }

    void insert(int val) {
        h.push_back(val);
        siftUp((int)h.size() - 1);
    }

    int extractMax() {
        if (h.empty()) throw runtime_error("Heap is empty");
        int ret = h[0];
        h[0] = h.back();
        h.pop_back();
        if (!h.empty()) siftDown(0);
        return ret;
    }

    int peek() const {
        if (h.empty()) throw runtime_error("Heap is empty");
        return h[0];
    }

    bool empty() const { return h.empty(); }
    size_t size() const { return h.size(); }

    void print() const {
        for (int x : h) cout << x << " ";
        cout << endl;
    }
};

// Heap sort using priority_queue for convenience (returns sorted vector)
vector<int> heapSortUsingPQ(const vector<int>& a, bool ascending = true) {
    vector<int> out;
    if (ascending) {
        // min-heap: use greater to pop smallest first
        priority_queue<int, vector<int>, greater<int>> pq(a.begin(), a.end());
        while (!pq.empty()) { out.push_back(pq.top()); pq.pop(); }
    } else {
        // max-heap default
        priority_queue<int> pq(a.begin(), a.end());
        while (!pq.empty()) { out.push_back(pq.top()); pq.pop(); }
    }
    return out;
}

// Small demo function that can be called from elsewhere if desired
int main_demo() {
    vector<int> vec = {10, 5, 3, 2, 4};
    cout << "--- MaxHeap demo ---\n";
    MaxHeap MH(vec);
    cout << "Built MaxHeap: "; MH.print();
    MH.insert(12);
    cout << "After insert(12): "; MH.print();
    cout << "peek(): " << MH.peek() << ", size(): " << MH.size() << "\n";
    cout << "Extracting maxes: ";
    while (!MH.empty()) cout << MH.extractMax() << " ";
    cout << "\n";

    cout << "--- heapSortUsingPQ ---\n";
    vector<int> ascSorted = heapSortUsingPQ(vec, true);
    cout << "Ascending (pq): "; for (int x : ascSorted) cout << x << " "; cout << '\n';
    vector<int> descSorted = heapSortUsingPQ(vec, false);
    cout << "Descending (pq): "; for (int x : descSorted) cout << x << " "; cout << '\n';

    return 0;
}
