// File: MaxHeap.h
#pragma once
#include <iostream>
#include <algorithm>
#include <climits> // for INT_MAX

struct Node {
    int x, y, dist;
    bool operator<(const Node& other) const { return dist < other.dist; }
};

template <typename T>
class MaxHeap {
public:
    MaxHeap();
    ~MaxHeap();
    void InitArray(T n);              // Initialize the array with random values
    void BuildMaxHeap();              // Build max heap
    void MaxHeapify(int i, int size); // Maintain max heap property
    void Display();                   // Display elements in the heap
    void Insert(T item);              // Insert item into the max heap
    T Poll();                         // Delete and return root element
    T Peek();                         // Return the root element without deletion
    bool isEmpty() const { return size == 0; } // Check if heap is empty

private:
    T* a;            // Dynamic array for the heap
    int capacity;    // Max capacity of the heap
    int size;        // Current size of the heap

    void resizeArray(); // Resize the array if needed
};

// Implementation of MaxHeap methods

template <typename T>
MaxHeap<T>::MaxHeap() : a(nullptr), size(0), capacity(0) {}

template <typename T>
MaxHeap<T>::~MaxHeap() {
    delete[] a;
}

template <typename T>
void MaxHeap<T>::resizeArray() {
    capacity = (capacity == 0) ? 2 : capacity * 2;
    T* newArray = new T[capacity];
    for (int i = 1; i <= size; ++i) {
        newArray[i] = a[i];
    }
    delete[] a;
    a = newArray;
}

template <typename T>
void MaxHeap<T>::InitArray(T n) {
    capacity = n + 1;
    size = n;
    a = new T[capacity];
    for (int i = 1; i <= n; ++i) {
        a[i] = static_cast<T>((1.0 * rand() / RAND_MAX) * n);
    }
}

template <typename T>
void MaxHeap<T>::BuildMaxHeap() {
    for (int i = size / 2; i >= 1; --i) {
        MaxHeapify(i, size);
    }
}

template <typename T>
void MaxHeap<T>::Display() {
    int DisplayLimit = std::min(100, size); // Display up to 100 elements only
    for (int i = 1; i <= DisplayLimit; ++i) {
        std::cout << a[i] << "\t";
        if (i % 10 == 0) std::cout << std::endl;
    }
    std::cout << std::endl;
}

template <typename T>
void MaxHeap<T>::MaxHeapify(int i, int heapSize) {
    int left = 2 * i;
    int right = 2 * i + 1;
    int largest = i;

    if (left <= heapSize && a[left] > a[i]) largest = left;
    if (right <= heapSize && a[right] > a[largest]) largest = right;
    
    if (largest != i) {
        std::swap(a[i], a[largest]);
        MaxHeapify(largest, heapSize);
    }
}

template <typename T>
void MaxHeap<T>::Insert(T item) {
    if (size + 1 >= capacity) resizeArray();
    size++;
    int i = size;
    a[i] = item;

    while (i > 1 && a[i / 2] < a[i]) {
        std::swap(a[i], a[i / 2]);
        i = i / 2;
    }
}

template <typename T>
T MaxHeap<T>::Poll() {
    if (isEmpty()) {
        // Return a default "empty" T value if the heap is empty
        return T{-1, -1, INT_MAX}; // assuming T is a struct like PathNode
    }

    T maxItem = a[1];
    a[1] = a[size];
    size--;
    MaxHeapify(1, size);
    return maxItem;
}

template <typename T>
T MaxHeap<T>::Peek() {
    if (isEmpty()) {
        // Return a default "empty" T value if the heap is empty
        return T{-1, -1, INT_MAX}; // assuming T is a struct like PathNode
    }
    return a[1];
}
