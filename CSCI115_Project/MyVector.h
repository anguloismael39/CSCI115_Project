// File: MyVector.h
#pragma once
#include <iostream>

template <typename T>
class MyVector {
private:
    T* data;
    int capacity;
    int length;

    void resize(int new_capacity) {
        T* new_data = new T[new_capacity];
        for (int i = 0; i < length; i++) {
            new_data[i] = data[i];
        }
        delete[] data;
        data = new_data;
        capacity = new_capacity;
    }

public:
    MyVector() : data(new T[10]), capacity(10), length(0) {}

    // New constructor to initialize with a specific size and default value
    MyVector(int initial_size, T default_value = T()) : data(new T[initial_size]), capacity(initial_size), length(initial_size) {
        for (int i = 0; i < initial_size; i++) {
            data[i] = default_value;
        }
    }

    ~MyVector() { delete[] data; }

    int size() const { return length; }

    bool isEmpty() const { return length == 0; }

    void push_back(const T& value) {
        if (length == capacity) resize(2 * capacity);
        data[length++] = value;
    }

    void pop_back() {
        if (length > 0) length--;
    }

    T& operator[](int index) { return data[index]; }

    const T& operator[](int index) const { return data[index]; }

    void clear() { length = 0; }
};
