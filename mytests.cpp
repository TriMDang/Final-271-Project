#include "WeightedGraph.hpp"
#include "PriorityQueue.hpp"
#include <iostream>

void test_heapify(int &testPassed, int &testFailed);
void test_buildHeap(int &testPassed, int &testFailed);
void test_getMin(int &testPassed, int &testFailed);
void test_remove(int &testPassed, int &testFailed);

using namespace std;
int main(){
    int testsPassed = 0;
    int testsFailed = 0;
    
    test_heapify(testsPassed, testsFailed);
    test_buildHeap(testsPassed, testsFailed);
    test_getMin(testsPassed, testsFailed);
    test_remove(testsPassed, testsFailed);
    Graph g;
    g.readFromSTDIN();

    return (0);
}

void test_heapify(int &testPassed, int &testFailed) {
    MinPQueue<int> heap;

    heap.insert(1);
    heap.insert(5);
    heap.insert(7);
    heap.insert(3);
    heap.insert(9);

    heap.heapify(2);

    if (heap[2] = 3) {
        testPassed++;
        cout << "Passed test_heapify" << endl;
    }
    else {
        testFailed++;
        cout << "Failed test_heapify" << endl;
    }
}

void test_buildHeap(int &testPassed, int &testFailed) {
    MinPQueue<int> heap1;
    MinPQueue<int> heap2;

    heap.insert(1);
    heap.insert(5);
    heap.insert(7);
    heap.insert(3);
    heap.insert(9);

    heap2.buildHeap(heap1);

    if (heap2 = heap1) {
        testPassed++;
        cout << "Passed test_buildHeap" << endl;
    }
    else {
        testFailed++;
        cout << "Failed test_buildHeap" << endl;
    }
    
}

void test_getMin(int &testPassed, int &testFailed) {
    MinPQueue<int> heap;

    heap.insert(1);
    heap.insert(5);
    heap.insert(7);
    heap.insert(3);
    heap.insert(9);

    int min = heap.getMin();
    if (min == 3) {
        testPassed++;
        cout << "Passed test_buildHeap" << endl;
    }
    else {
        testFailed++;
        cout << "Failed test_buildHeap" << endl;
    }
}

void test_remove(int &testPassed, int &testFailed) {
    MinPQueue<int> heap;

    heap.insert(1);
    heap.insert(5);
    heap.insert(7);
    heap.insert(8);
    heap.insert(3);
    heap.insert(9);

    heap.remove(8);

    if (heap.search(8) == false) {
        testPassed++;
        cout << "Passed test_remove" << endl;
    }
    else {
        testFailed++;
        cout << "Failed test_remove" << endl;
    }
}
