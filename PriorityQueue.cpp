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
