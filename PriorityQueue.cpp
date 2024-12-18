//=========================================
// PriorityQueue.cpp
// Date: 12/16/24
// Authors: Tri Dang, Omar Perez, Esther Zhang
// Description: Implemetation of all functions for Priotity Queue
//=========================================

#include "PriorityQueue.hpp"
#include "customexceptions.hpp"
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
    minArray.clear();
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
        minArray = other.minArray;
        size = other.size;
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
        throw index_exception();
    }
    else {
        return minArray[i];
    }
}

//=========================================
// Omar Perez
// Parameter: index
// Return: left child of the index
//considering 0 based indexing
//=========================================
template <typename T>
int MinPQueue<T>::left(int index){
    return ((2 * index)+1 );
}

//=========================================
// Omar Perez
// Parameter: index
// Return: The right child of the index
//considering 0 based indexing
//=========================================
template <typename T>
int MinPQueue<T>::right(int index){
    return ((2 * index) + 2);
}

//=========================================
// Omar Perez
// PArameter: index
// Return: parent of the index. used for internal operations
//=========================================
template <typename T> 
int MinPQueue<T> :: parent (int index){
    return((index - 1) / 2);
}

//=========================================
// Author: Esther Zhang
// Parameter: Index
// Return: None
// Description: Update the priority queue so that the  at i is the 
// smallest value of the sub tree
//=========================================
template <typename T>
//error in the declaration
void MinPQueue<T>::heapify(int i) {
    int l = left(i);
    int r = right(i);
    int smallest = i;

    if (l < size && minArray[l] < minArray[i]) {
        smallest = l;
    }
    if (r < size && minArray[r] < minArray[smallest]) {
        smallest = r;
    }
    if (smallest != i) {
        swap(minArray[i], minArray[smallest]);
        heapify(smallest);
    }
}

//=========================================
// Author: Esther Zhang
// Parameter: Existing queue
// Return: None
// Description: Converts and existing queue to a min priority queue
//=========================================
template <typename T>
void MinPQueue<T>::buildHeap(int s) {
    size = s; // Set the size based on the input parameter
    for (int i = (size / 2) - 1; i >= 0; i--) { // Start from last internal node
        heapify(i); // Heapify each subtree
    }
}

//=========================================
// Author: Esther Zhang
// Parameter: 
// Return: The min value in the queue
// Description: Finds and returns the min value in the queue
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
// Parameter: Pointer to a value
// Return: None
// Description: Inserts a value into the Priority Queue
//=========================================
template<typename T>
void MinPQueue<T>::insert(const T& value) {
    minArray.push_back(value);
    size++;

    int i = size - 1;
    while (i > 0 && minArray[parent(i)] > minArray[i]) {
        swap(minArray[i], minArray[parent(i)]);
        i = parent(i);
    }
}

//=========================================
// Author: Esther Zhang
// Parameter: 
// Return: The min value in the queue
// Description: Finds and returns the min value in the queue
//=========================================
template <typename T>
T MinPQueue<T>::getMin() const {
    if (size == 0) {
        throw empty_heap();
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
void MinPQueue<T>::remove(const T& value) {
    for (int i = 0; i < size; i++) {
        if (minArray[i] == value) {
            minArray[i] = minArray[size - 1];
            minArray.pop_back();
            size--;
            heapify(i);
            return;
        }
            
    }
    throw invalid_value();
    //maybe implement something if the val is not found here
}

//=========================================
// Author: Omar Perez
// Parameter: none
// Return: int, min value 
// Description: while the heap isnt empty we return 
// the min value and delete it from the queue. 
// fixing the min heap property is guaranteed by calling heapify(0)
//=========================================
template <typename T>
T MinPQueue<T>::extractMin() {
    if (size == 0) {
        throw empty_heap();
    }

    T minValue = minArray[0];
    minArray[0] = minArray[size - 1];
    minArray.pop_back();
    size--;

    if (size > 0) {
        heapify(0);
    }

    return minValue;
}

//=========================================
// Author: Omar Perez
//Parameters: index of the value we will substitute,
// and the new smaller value 
//Description: We substitude the value in index 0, 
//with the new value that must be smaller.
//=========================================
template <typename T>
void MinPQueue<T>::decreaseKey(int i, const T& newValue) {
    //int i is the index of the element
    if (i < 0 || i >= minArray.size()) {
        throw index_exception();
    }
    if (newValue > minArray[i]) {
        throw index_exception();
    }

    minArray[i] = newValue;

    while (i > 0 && minArray[parent(i)] > minArray[i]) {
        swap(minArray[i], minArray[parent(i)]);
        i = parent(i);
    }

}

//Author Omar Perez
// Parameters: None
//Description: Print the Priority Queue
//This was usefull only for testing
template <typename T>
void MinPQueue<T>::printQueue() const {
    cout << "Priority Queue (MinArray): ";
   for (size_t i = 0; i < minArray.size(); ++i) { 
        cout << minArray[i] << " ";
    }
    cout << endl;
}