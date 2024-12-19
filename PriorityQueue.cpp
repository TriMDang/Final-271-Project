//=========================================
// PriorityQueue.cpp
// Date: 12/16/24
// Authors: Tri Dang, Omar Perez, Esther Zhang
// Description: Implementation of all functions for Priority Queue supporting tuples
//=========================================

#include "PriorityQueue.hpp"
#include "customexceptions.hpp"
#include <iostream>

using namespace std;

using namespace std;

//=========================================
// Author: Esther Zhang 
// Parameter: None
// Return: None. Queue is constructed
// Description: Construct minimum priority queue
//=========================================
template <typename T>
MinPQueue<T>::MinPQueue() {
    size = 0;
}

//=========================================
// Author: Esther Zhang
// Parameter: None
// Return: None. Queue is deleted
// Description: Deletes everything
//=========================================
template <typename T>
MinPQueue<T>::~MinPQueue() {
    minArray.clear();
    nodePosition.clear();
}

//=========================================
// Author: Esther Zhang
// Parameter: Existing queue
// Return: None. 
// Description: Creates a new queue then copies everything from the existing queue
//=========================================
template <typename T>
MinPQueue<T>::MinPQueue(const MinPQueue& other) {
    size = other.size;
    minArray = other.minArray;
    nodePosition = other.nodePosition;
}

//=========================================
// Author: Esther Zhang
// Parameter: Existing queue
// Return: New/this queue
// Description: Similar to copy constructor but it works on preexisting queue
//=========================================
template <typename T>
MinPQueue<T>& MinPQueue<T>::operator=(const MinPQueue<T>& other) {
    if (this != &other) {
        minArray = other.minArray;
        nodePosition = other.nodePosition;
        size = other.size;
    }
    return *this;
} 

//=========================================
// Author: Esther Zhang
// Parameter: Index
// Return: The value at said index
// Description: Accesses value at index
//=========================================
template<typename T>
T& MinPQueue<T>::operator[](int i) {
    if (i >= size) {
        throw index_exception();
    }
    return minArray[i];
}

//=========================================
// Author: Omar Perez
// Parameter: index
// Return: left child of the index
//=========================================
template <typename T>
int MinPQueue<T>::left(int index) {
    return (2 * index + 1);
}

//=========================================
// Author: Omar Perez
// Parameter: index
// Return: The right child of the index
//=========================================
template <typename T>
int MinPQueue<T>::right(int index) {
    return (2 * index + 2);
}

//=========================================
// Author: Omar Perez
// Parameter: index
// Return: parent of the index
//=========================================
template <typename T> 
int MinPQueue<T>::parent(int index) {
    return (index - 1) / 2;
}

//=========================================
// Author: Esther Zhang
// Parameter: Index
// Return: None
// Description: Update the priority queue so that the value at i is the 
// smallest value of the subtree
//=========================================
template <typename T>
void MinPQueue<T>::heapify(int i) {
    int l = left(i);
    int r = right(i);
    int smallest = i;

    if (l < size && get<0>(minArray[l]) < get<0>(minArray[i])) {
        smallest = l;
    }
    if (r < size && get<0>(minArray[r]) < get<0>(minArray[smallest])) {
        smallest = r;
    }
    if (smallest != i) {
        swap(minArray[i], minArray[smallest]);
        nodePosition[get<1>(minArray[i])] = i;
        nodePosition[get<1>(minArray[smallest])] = smallest;
        heapify(smallest);
    }
}

//=========================================
// Author: Esther Zhang
// Parameter: Existing queue
// Return: None
// Description: Converts an existing queue to a min priority queue
//=========================================
template <typename T>
void MinPQueue<T>::buildHeap(int s) {
    size = s;
    for (int i = (size / 2) - 1; i >= 0; i--) {
        heapify(i);
    }
}

//=========================================
// Author: Esther Zhang
// Parameter: The value to search for
// Return: True if found, otherwise false
// Description: Searches for a value in the queue
//=========================================
template<typename T>
bool MinPQueue<T>::search(const T& value) {
    for (int i = 0; i < size; i++) {
        if (minArray[i] == value) {
            return true;
        }
    }
    return false;
}

//=========================================
// Author: Esther Zhang
// Parameter: A tuple to insert
// Return: None
// Description: Inserts a value into the Priority Queue
//=========================================
template<typename T>
void MinPQueue<T>::insert(const T& value) {
    minArray.push_back(value);
    size++;
    int i = size - 1;
    nodePosition[get<1>(value)] = i;

    while (i > 0 && get<0>(minArray[parent(i)]) > get<0>(minArray[i])) {
        swap(minArray[i], minArray[parent(i)]);
        nodePosition[get<1>(minArray[i])] = i;
        nodePosition[get<1>(minArray[parent(i)])] = parent(i);
        i = parent(i);
    }
}

//=========================================
// Author: Esther Zhang
// Parameter: None
// Return: The minimum value in the queue
// Description: Finds and returns the minimum value in the queue
//=========================================
template <typename T>
T MinPQueue<T>::getMin() const {
    if (size == 0) {
        throw empty_heap();
    }
    return minArray[0];
}

//=========================================
// Author: Esther Zhang
// Parameter: A tuple to remove
// Return: None
// Description: Searches and deletes a value in the min priority queue
//=========================================
template <typename T>
void MinPQueue<T>::remove(const T& value) {
    if (nodePosition.find(get<1>(value)) == nodePosition.end()) {
        throw invalid_value();
    }
    int i = nodePosition[get<1>(value)];
    minArray[i] = minArray[size - 1];
    nodePosition[get<1>(minArray[i])] = i;
    nodePosition.erase(get<1>(value));
    minArray.pop_back();
    size--;

    if (size > 0) {
        heapify(i);
    }
}

//=========================================
// Author: Omar Perez
// Parameter: None
// Return: The minimum value in the queue
// Description: Removes and returns the minimum value
//=========================================
template <typename T>
T MinPQueue<T>::extractMin() {
    if (size == 0) {
        throw empty_heap();
    }

    T minValue = minArray[0];
    minArray[0] = minArray[size - 1];
    nodePosition[get<1>(minArray[0])] = 0;
    nodePosition.erase(get<1>(minValue));
    minArray.pop_back();
    size--;

    if (size > 0) {
        heapify(0);
    }
    return minValue;
}

//=========================================
// Author: Omar Perez
// Parameter: Index of the value, and the new smaller value
// Return: None
// Description: Decreases the key of a value in the queue
//=========================================
template <typename T>
void MinPQueue<T>::decreaseKey(int i, const T& newValue) {
    if (i < 0 || i >= size || get<0>(newValue) > get<0>(minArray[i])) {
        throw index_exception();
    }

    minArray[i] = newValue;
    nodePosition[get<1>(newValue)] = i;

    while (i > 0 && get<0>(minArray[parent(i)]) > get<0>(minArray[i])) {
        swap(minArray[i], minArray[parent(i)]);
        nodePosition[get<1>(minArray[i])] = i;
        nodePosition[get<1>(minArray[parent(i)])] = parent(i);
        i = parent(i);
    }
}

//=========================================
// Author: Omar Perez
// Parameter: None
// Return: None
// Description: Prints the priority queue (used for testing)
//=========================================
template <typename T>
void MinPQueue<T>::printQueue() const {
    cout << "Priority Queue (MinArray): ";
    for (const auto& elem : minArray) {
        cout << "(" << get<0>(elem) << ", " << get<1>(elem) << ") ";
    }
    cout << endl;
}