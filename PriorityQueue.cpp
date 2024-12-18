//=========================================
// PriorityQueue.cpp
// Date: 12/16/24
// Authors: Tri Dang, Omar Perez, Esther Zhang
// Description: Implemetation of all functions for Priotity Queue
//=========================================

#include "PriorityQueue.hpp"
#include <iostream>

using namespace std;

//=========================================
// Author: Esther Zhang
// Parameter: None
// Return: None. Queue is constructed
// Description: Construct minimum prioity queue
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
    heap.clear();
}

//=========================================
// Author: Esther Zhang
// Parameter: Existing queue
// Return: None. 
// Description: Creates a new queue then copies everything from the existing queue
//=========================================
template <typename T>
MinPQueue<T>::MinPQueue(const MinPQueue& other) {
    size = other.size();
    minArray(other.minArray);
}

//=========================================
// Author: Esther Zhang
// Parameter: Existing queue
// Return: New/this queue
// Description: Similar to copy constructor but it works on prexisting queue
//=========================================
template <typename T>
MinPQueue<T>& MinPQueue<T>::operator=(const MinPQueue<T>& other) {
    if (this != &other) {
        size = other.size;
        minArray = other.minArray;
    }

    return *this;
} 

//=========================================
// Author: Esther Zhang
// Parameter: Index
// Return: The value at said index
// Description: 
//=========================================
template<typename T>
T& MinPQueue<T>::operator[](int i) {
    if (i >= size) {
        return;
    }
    else {
        return heap[index];
    }
}

//=========================================
// Author: Esther Zhang
// Parameter: Index
// Return: None
// Description: Update the priority queue so that the  at i is the 
// smallest value of the sub tree
//=========================================
template <typename T>
void MinPQueue<T>::heapify(const T& array, int i) {
    int l = left(i);
    int r = right(i);
    int smallest = i;
    T temp;
    if (l <= size && array[l] < array[i]) {
        smallest = l;
    }
    else {
        smallest = i;
    }
    if (r <= size && array[r] < array[i]) {
        smallest = r;
    }
    if (smallest != i) {
        T temp = array[i];
        array[i] = array[smallest];
        array[smallest] = temp;

        heapify(array, smallest);
    }

}
}

//=========================================
// Author: Esther Zhang
// Parameter: Existing queue
// Return: None
// Description: Converts and existing queue to a min priority queue
//=========================================
template <typename T>
void MinPQueue<T>::buildHeap(const T& array, int s) {
    s = size;
    int n = size/2;
    for (int i = n; i > 1; i--) {
        heapify(array, i);
    }
}

//=========================================
// Author: Esther Zhang
// Paramete  r: 
// Return: A long of the size of the queue
// Description: Find the size of the queue
//=========================================
template <typename T>
long MinPQueue<T>::size() {
    size = minArray.size();
    return (minArray.size();)
}

//=========================================
// Author: Esther Zhang
// Parameter: 
// Return: The min value in the queue
// Description: Finds and returns the min value in the queue
//=========================================
template<typename T>
bool MinPQueue<T>::search(const T& value) {
    for (i = 0; i < size; i++) {
        if (minArray[i] == value;) {
            return true;
        }
        else {
            return false;
        }
    }
}

//=========================================
// Author: Esther Zhang
// Parameter: Pointer to a value
// Return: None
// Description: Inserts a value into the Priority Queue
//=========================================
void MinPQueue<T>::insert(const T& value) {
    if (size == minArray.size()) {
        minArray.push_back(value);
    }
    else {
        minArray[size] == value;
    }

    size++;
    int i = size -1;
    while(i > 0) {
        int parent = (index - 1) / 2;

        if (minArray[i] >= minArray[parent]) {
            break;
        }
    }

    T temp = minArray[i];
    minArray[i] = minArray[parent];
    minArray[parent] = temp;
    
    i = parent;
}

//=========================================
// Author: Esther Zhang
// Parameter: 
// Return: The min value in the queue
// Description: Finds and returns the min value in the queue
//=========================================
template <typename T>
const T& MinPQueue<T>::getMin() const {
    if (size == 0) {
        return;
    }
    else {
        return (minArray[0]);
    }
}

//=========================================
// Author: Esther Zhang
// Parameter: Pointer to a value
// Return: None
// Description: Searches and deletes a value in the min prioity queue
//=========================================
template <typename T>
void minPQueue<T>::remove(const T& value){
    int temp = 0;
    int i = search(value);
    if (i == false) {
        return;
    }
    T temp = minArray[i];
    minArray[i] = minArray[size-1];
    minArray[size-1] = temp; 
    delete (minArray[minArray.size()-1]);

    heapify(i);
}

