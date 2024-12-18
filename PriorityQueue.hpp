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
        int left(int index);
        int right(int index);
        int parent (int index);
    public:
        MinPQueue(); //Default constructor
        ~MinPQueue(); //Destructor
        MinPQueue(const MinPQueue<T>& other); //Copy constructor
        MinPQueue<T>& operator=(const MinPQueue<T>& other);
        T& operator[](int i);
        void heapify(const MinPQueue<T>& array, int i);
        void buildHeap(const MinPQueue<T>& array, int s);
        bool search(const T& value);
        void insert(const T& value);
        T getMin() const;
        int extractMin();
        void decreaseKey(int i, const T& newValue);
        void remove(const T& value);
};

#endif
