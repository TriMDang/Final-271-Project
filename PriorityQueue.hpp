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
<<<<<<< HEAD
        int left(int index);
        int right(int index);
=======
        int left(int i);
        int right(int i);
>>>>>>> refs/remotes/origin/main

    public:
        MinPQueue(); //Default constructor
        ~MinPQueue(); //Destructor
        MinPQueue(const MinPQueue<T>& other); //Copy constructor
        MinPQueue<T>& operator=(const MinPQueue<T>& other);
        T& operator[](int i);
<<<<<<< HEAD
        void heapify(const MinPQueue<T>&, int i);
        void buildHeap(const MinPQueue<T>&, int s);
        bool search(const T& value);
        void insert(const T& value);
        T getMin() const;
=======
        void heapify(const T&, int i); //Esther
        void buildHeap(const T&, int s); //Esther
        bool search(const T& value); //Esther
        void insert(const T& value); //Esther
        T getMin() const; //Esther
>>>>>>> refs/remotes/origin/main
        int extractMin();
        void decreaseKey();
        void remove(const T& value);
};

#endif
