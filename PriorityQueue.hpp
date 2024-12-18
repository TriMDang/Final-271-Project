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

template <typename T>
class MinPQueue {
    private:
        vector<T> heap; //Store the values of the priority queue
        //int left(i);
        //int right(i);

    public:
        MinPQueue(); //Default constructor
        ~MinPQueue(); //Destructor
        MinPQueue(const MinPQueue& other); //Copy constructor
        MinPQueue& operator=(const MinPQueue& other);
        MinPQueue& operator[](int i);
        void heapify(int i);
        void buildHeap();
        long size();
        //void insert(value);
        T getMin();
        int extractMin();
        void decreaseKey();
        void remove(const T& value);
};

#endif
