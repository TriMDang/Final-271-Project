#include "WeightedGraph.hpp"
#include "PriorityQueue.hpp"
#include <iostream>
<<<<<<< HEAD
#include <iostream>
=======
>>>>>>> refs/remotes/origin/main

void test_heapify(int &testPassed, int &testFailed);
void test_buildHeap(int &testPassed, int &testFailed);
void test_insert(int &testpassed, int &testFailed);
void test_getMin(int &testPassed, int &testFailed);
void test_remove(int &testPassed, int &testFailed);

using namespace std;

int main(){
    int testsPassed = 0;
    int testsFailed = 0;

    test_heapify(testsPassed, testsFailed);
    test_buildHeap(testsPassed, testsFailed);
    test_insert(testsPassed, testsFailed);
    test_getMin(testsPassed, testsFailed);
    test_remove(testsPassed, testsFailed);
    //Graph g;
    //g.readFromSTDIN();

    return (0);

}

void test_heapify(int &testPassed, int &testFailed) {
    MinPQueue<int> pQueue;

    pQueue.insert(1);
    pQueue.insert(5);
    pQueue.insert(7);
    pQueue.insert(3);
    pQueue.insert(9);

    pQueue.heapify(pQueue, 2);

    if (pQueue[2] = 3) {
        testPassed++;
        cout << "Passed test_heapify" << endl;
    }
    else {
        testFailed++;
        cout << "Failed test_heapify" << endl;
    }
}
 
void test_buildHeap(int &testPassed, int &testFailed) {
    MinPQueue<int> pQueue1;
    MinPQueue<int> pQueue2;

    pQueue1.insert(1);
    pQueue1.insert(5);
    pQueue1.insert(7);
    pQueue1.insert(3);
    pQueue1.insert(9);

    pQueue2.buildHeap(pQueue1, 5);

    if (pQueue2.search(1) == true && pQueue2.search(5) == true && pQueue2.search(7)
        && pQueue2.search(3) == true && pQueue2.search(9) == true) {
        testPassed++;
        cout << "Passed test_buildHeap" << endl;
    }
    else {
        testFailed++;
        cout << "Failed test_buildHeap" << endl;
    }
    
}

void test_insert(int &testPassed, int &testFailed) {
    MinPQueue<int> pQueue;

    pQueue.insert(1);

    if (pQueue.search(1) == true) {
        testPassed++;
        cout << "Passed test_insert" << endl;
    }
    else {
        testFailed++;
        cout << "Failed test_instert" << endl;
    }
}

void test_getMin(int &testPassed, int &testFailed) {
    MinPQueue<int> pQueue;

    pQueue.insert(1);
    pQueue.insert(5);
    pQueue.insert(7);
    pQueue.insert(3);
    pQueue.insert(9);

    int min = pQueue.getMin();
    if (min == 1) {
        testPassed++;
        cout << "Passed test_buildHeap" << endl;
    }
    else {
        testFailed++;
        cout << "Failed test_buildHeap" << endl;
    }
}

void test_remove(int &testPassed, int &testFailed) {
    MinPQueue<int> pQueue;

    pQueue.insert(1);
    pQueue.insert(5);
    pQueue.insert(7);
    pQueue.insert(8);
    pQueue.insert(3);
    pQueue.insert(9);

    pQueue.remove(8);

    if (pQueue.search(8) == false) {
        testPassed++;
        cout << "Passed test_remove" << endl;
    }
    else {
        testFailed++;
        cout << "Failed test_remove" << endl;
    }
}
