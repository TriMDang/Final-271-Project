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
        vector<T> minArray; //Store the values of the priority queue
        int size;
        int left(int i);
        int right(int i);

    public:
        MinPQueue(); //Default constructor
        ~MinPQueue(); //Destructor
        MinPQueue(const MinPQueue<T>& other); //Copy constructor
        T& operator=(const MinPQueue& other);
        T& operator[](int i);
        void heapify(const T&, int i); //Esther
        void buildHeap(const T&, int s); //Esther
        bool search(const T& value); //Esther
        void insert(const T& value); //Esther
        T getMin() const; //Esther
        int extractMin();
        void decreaseKey();
        void remove(const T& value);
};

#endif
