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
MinPQueue::MinPQueue() {

}

//=========================================
// Author: Esther Zhang
// Parameter: None
// Return: None. Queue is deleted
// Description: Deletes everything
//=========================================
MinPQueue::~MinPQueue() {
    heap.clear();
}

//=========================================
// Author: Esther Zhang
// Parameter: Existing queue
// Return: None. 
// Description: Creates a new queue then copies everything from the existing queue
//=========================================
MinPQueue::MinPQueue(const MinPQueue& other) {
    this -> heap = other.heap;
}

//=========================================
// Author: Esther Zhang
// Parameter: Existing queue
// Return: New/this queue
// Description: Similar to copy constructor but it works on prexisting queue
//=========================================
MinPQueue& MinPQueue::operator=(const MinPQueue& other) {
    if (this != &other) {
        this -> heap = other.heap;
    }

    return *this;
} 

//=========================================
// Author: Esther Zhang
// Parameter: Index
// Return: The value at said index
// Description: 
//=========================================
MinPQueue& MinPQueue::operator[](int i) {
    if (i < 0 || i >= heap.size()) {
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
void MinPQueue::heapify(int i) {
    int l = left(i);
    int r = right(i);
    int smallest = i;
    int temp = i;
    if (l <= heap.size() && heap[l] < heap[i]) {
        smallest = l;
    }
    else {
        smallest = i;
    }
    if (r <= heap.size() && heap[r] < heap[i]) {
        smallest = r;
    }
    if (smallest != i) {
        heap[i] = heap[smallest];
        heap[smallest] = heap[temp];
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
void MinPQueue::buildHeap(heap& minHeap) {
    int size = minHeap.size();
    int n = size/2;
    for (int i = n; i > 1; i--) {
        heapify(i);
    }
}

//=========================================
// Author: Esther Zhang
// Paramete  r: 
// Return: A long of the size of the queue
// Description: Find the size of the queue
//=========================================
template <typename T>
long MinPQueue::size() {
    return (heap.size();)
}

//=========================================
// Author: Esther Zhang
// Parameter: Value to be searched
// Return: True if found, false if not
// Description: Searches for a value in the queue
//=========================================
template<typename T>
bool MinPQueue::search(const T& value) {
    for (i = 0; i < heap.size(); i++) {
        if (heap[i] == value;) {
            return true;
        }
        else {
            return false;
        }
    }
}

//=========================================
// Author: Esther Zhang
// Parameter: 
// Return: The min value in the queue
// Description: Finds and returns the min value in the queue
//=========================================
template <typename T>
T MinPQueue::getMin() {
    if (heap.size() = 0) {
        return;
    }
    else {
        heap.heapify();
        return (heap[0]);
    }
}

//=========================================
// Author: Esther Zhang
// Parameter: Pointer to a value
// Return: None
// Description: Searches and deletes a value in the min prioity queue
//=========================================
template <typename T>
void remove(const T& value){
    int temp = 0;
    for (i = 0; i < heap.size(); i++) {
        if (heap[i] == value) {
            temp = i;
            break;
        }
    }
    heap[i] = heap[heap.size()-1]
    heap[heap.size()-1] = heap[temp]; 
    delete (heap[heap.size()-1]);

    heapify(i);
}
