#include "WeightedGraph.cpp"
#include "PriorityQueue.cpp"
#include <iostream>

void test_heapify(int &testPassed, int &testFailed);
void test_buildHeap(int &testPassed, int &testFailed);
void test_search(int &testPassed, int &testFailed);
void test_insert(int &testpassed, int &testFailed);
void test_getMin(int &testPassed, int &testFailed);
void test_remove(int &testPassed, int &testFailed);

using namespace std;

int main(){
    int testsPassed = 0;
    int testsFailed = 0;

    test_heapify(testsPassed, testsFailed);
    test_buildHeap(testsPassed, testsFailed);
    test_search(testsPassed, testsFailed);
    test_insert(testsPassed, testsFailed);
    test_getMin(testsPassed, testsFailed);
    test_remove(testsPassed, testsFailed);
    //Graph g;
    //g.readFromSTDIN();

    cout << "Tests Passed: " << testsPassed << endl;
    cout << "Tests Failed: " << testsFailed << endl;
    return (0);

}

void test_heapify(int &testPassed, int &testFailed) {
    MinPQueue<int> pQueue;

    pQueue.insert(1);
    pQueue.insert(5);
    pQueue.insert(7);
    pQueue.insert(3);
    pQueue.insert(9);

    pQueue.heapify(2);

    if (pQueue[1] == 3) {
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

    pQueue1.insert(7);
    pQueue1.insert(5);
    pQueue1.insert(3);
    pQueue1.insert(1);
    pQueue1.insert(9);

    pQueue1.buildHeap(5);

    if (pQueue1.search(1) == true) {
        testPassed++;
        cout << "Passed test_buildHeap" << endl;
    }
    else {
        testFailed++;
        cout << "Failed test_buildHeap" << endl;
    }
    
}

void test_search(int &testPassed, int &testFailed) {
    MinPQueue<int> pQueue;

    pQueue.insert(7);
    pQueue.insert(5);
    pQueue.insert(3);
    pQueue.insert(1);
    pQueue.insert(9);

    if (pQueue.search (5) == true && pQueue.search(10) == false) {
        testPassed++;
        cout << "Passed test_search" << endl;
    }
    else {
        testFailed++;
        cout << "Failed test_search" << endl;
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
        cout << "Passed test_getMin" << endl;
    }
    else {
        testFailed++;
        cout << "Failed test_getMin" << endl;
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
