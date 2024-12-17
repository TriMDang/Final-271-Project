//=========================================
// PriorityQueue.hpp
// Date: 12/16/24
// Authors: Tri Dang, Omar Perez, Esther Zhang
// Description: Declaration of all functions and variables for Priotity Queue
//=========================================

#ifndef PRIORITYQUEUE_HPP
#define PRIORITYQUEUE_HPP

#include <iostream>
#include <vector>

using namespace std;

class MinPQueue {
    private:
        vector<long> heap; //Store the values of the priority queue
        void heapify(int i);
        void builHeap();
        int left(i);
        int right(i);

    public:
        MinPQueue(); //Default constructor
        ~MinPQueue(); //Destructor
        MinPQueue(const MinPQueue& other); //Copy constructor
        MinPQueue& operator=(const MinPQueue& other);
        void insert(value);
        int getMin();
        int extractMin();
        void decreaseKey();
        void remove(value);
};

#endif


