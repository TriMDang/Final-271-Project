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
#include <tuple>
#include <unordered_map>
using namespace std;

template <typename T>
class MinPQueue {
private:
    std::vector<T> minArray; // Vector to store heap elements as tuples
    std::unordered_map<typename std::tuple_element<1, T>::type, int> nodePosition; // Map to track positions
    int size;

    int left(int index);      // Returns the left child index
    int right(int index);     // Returns the right child index
    int parent(int index);    // Returns the parent index
    

public:
    void heapify(int index);  // Maintains the min-heap property
    MinPQueue();                  // Default constructor
    ~MinPQueue();                 // Destructor
    MinPQueue(const MinPQueue& other); // Copy constructor
    MinPQueue& operator=(const MinPQueue& other); // Copy assignment operator

    T& operator[](int index);     // Access operator

    void buildHeap(int size);     // Build heap from existing elements
    bool search(const T& value); // Search for a value in the queue
    void insert(const T& value); // Insert a new value into the queue
    void remove(const T& value); // Remove a specific value from the queue
    T extractMin();              // Extract the minimum value from the queue
    T getMin() const;            // Get the minimum value without extracting
    void decreaseKey(int index, const T& newValue); // Decrease the key of a value

    void printQueue() const;     // Print the queue (for debugging purposes)
};


#endif // PRIORITYQUEUE_HPP



