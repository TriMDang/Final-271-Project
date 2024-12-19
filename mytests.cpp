#include "PriorityQueue.cpp"
#include <iostream>
#include <tuple>

using namespace std;

void test_heapify(int &testPassed, int &testFailed);
void test_buildHeap(int &testPassed, int &testFailed);
void test_search(int &testPassed, int &testFailed);
void test_insert(int &testPassed, int &testFailed);
void test_getMin(int &testPassed, int &testFailed);
void test_remove(int &testPassed, int &testFailed);
void test_extractMin(int &testPassed, int &testFailed);
void test_decreaseKey(int &testPassed, int &testFailed);

int main() {
    string response = "";
    cout << "Before starting...type 'y' to run PQ test (any other key if not): ";
    cin >> response;
    if (response == "y") {
        int testsPassed = 0;
        int testsFailed = 0;
        test_heapify(testsPassed, testsFailed);
        test_buildHeap(testsPassed, testsFailed);
        test_search(testsPassed, testsFailed);
        test_insert(testsPassed, testsFailed);
        test_getMin(testsPassed, testsFailed);
        test_remove(testsPassed, testsFailed);
        test_extractMin(testsPassed, testsFailed);
        test_decreaseKey(testsPassed, testsFailed);

        cout << "Tests Passed: " << testsPassed << endl;
        cout << "Tests Failed: " << testsFailed << endl;
    }
    return 0;
}

void test_heapify(int &testPassed, int &testFailed) {
    MinPQueue<tuple<double, long>> pQueue;

    pQueue.insert(make_tuple(7.0, 1));
    pQueue.insert(make_tuple(5.0, 2));
    pQueue.insert(make_tuple(3.0, 3));
    pQueue.insert(make_tuple(1.0, 4));
    pQueue.insert(make_tuple(9.0, 5));

    pQueue.buildHeap(5); // Use buildHeap which invokes heapify internally

    if (get<0>(pQueue.getMin()) == 1.0) {
        testPassed++;
        cout << "Passed test_heapify" << endl;
    } else {
        testFailed++;
        cout << "Failed test_heapify" << endl;
    }
}

void test_buildHeap(int &testPassed, int &testFailed) {
    MinPQueue<tuple<double, long>> pQueue;

    pQueue.insert(make_tuple(7.0, 1));
    pQueue.insert(make_tuple(5.0, 2));
    pQueue.insert(make_tuple(3.0, 3));
    pQueue.insert(make_tuple(1.0, 4));
    pQueue.insert(make_tuple(9.0, 5));

    pQueue.buildHeap(5);

    if (get<0>(pQueue.getMin()) == 1.0) {
        testPassed++;
        cout << "Passed test_buildHeap" << endl;
    } else {
        testFailed++;
        cout << "Failed test_buildHeap" << endl;
    }
}

void test_search(int &testPassed, int &testFailed) {
    MinPQueue<tuple<double, long>> pQueue;

    pQueue.insert(make_tuple(7.0, 1));
    pQueue.insert(make_tuple(5.0, 2));
    pQueue.insert(make_tuple(3.0, 3));
    pQueue.insert(make_tuple(1.0, 4));
    pQueue.insert(make_tuple(9.0, 5));

    if (pQueue.search(make_tuple(5.0, 2)) && !pQueue.search(make_tuple(10.0, 6))) {
        testPassed++;
        cout << "Passed test_search" << endl;
    } else {
        testFailed++;
        cout << "Failed test_search" << endl;
    }
}

void test_insert(int &testPassed, int &testFailed) {
    MinPQueue<tuple<double, long>> pQueue;

    pQueue.insert(make_tuple(3.0, 3));

    if (pQueue.search(make_tuple(3.0, 3))) {
        testPassed++;
        cout << "Passed test_insert" << endl;
    } else {
        testFailed++;
        cout << "Failed test_insert" << endl;
    }
}

void test_getMin(int &testPassed, int &testFailed) {
    MinPQueue<tuple<double, long>> pQueue;

    pQueue.insert(make_tuple(7.0, 1));
    pQueue.insert(make_tuple(5.0, 2));
    pQueue.insert(make_tuple(3.0, 3));
    pQueue.insert(make_tuple(1.0, 4));
    pQueue.insert(make_tuple(9.0, 5));

    auto min = pQueue.getMin();
    if (get<0>(min) == 1.0) {
        testPassed++;
        cout << "Passed test_getMin" << endl;
    } else {
        testFailed++;
        cout << "Failed test_getMin" << endl;
    }
}

void test_remove(int &testPassed, int &testFailed) {
    MinPQueue<tuple<double, long>> pQueue;

    pQueue.insert(make_tuple(1.0, 0));
    pQueue.insert(make_tuple(5.0, 1));
    pQueue.insert(make_tuple(7.0, 2));

    pQueue.remove(make_tuple(5.0, 1)); // Pass the correct tuple

    if (!pQueue.search(make_tuple(5.0, 1))) {
        testPassed++;
        cout << "Passed test_remove" << endl;
    } else {
        testFailed++;
        cout << "Failed test_remove" << endl;
    }
}

void test_extractMin(int &testPassed, int &testFailed) {
    MinPQueue<tuple<double, long>> pQueue;

    pQueue.insert(make_tuple(7.0, 1));
    pQueue.insert(make_tuple(5.0, 2));
    pQueue.insert(make_tuple(3.0, 3));
    pQueue.insert(make_tuple(1.0, 4));

    auto min = pQueue.extractMin();

    if (get<0>(min) == 1.0 && get<0>(pQueue.getMin()) == 3.0) {
        testPassed++;
        cout << "Passed test_extractMin" << endl;
    } else {
        testFailed++;
        cout << "Failed test_extractMin" << endl;
    }
}

void test_decreaseKey(int &testPassed, int &testFailed) {
    MinPQueue<tuple<double, long>> pQueue;

    pQueue.insert(make_tuple(10.0, 0));
    pQueue.insert(make_tuple(20.0, 1));
    pQueue.insert(make_tuple(15.0, 2));
    pQueue.insert(make_tuple(30.0, 3));
    pQueue.insert(make_tuple(25.0, 4));

    pQueue.decreaseKey(1, make_tuple(5.0, 1));

    if (get<0>(pQueue.getMin()) == 5.0) {
        testPassed++;
        cout << "Passed test_decreaseKey" << endl;
    } else {
        testFailed++;
        cout << "Failed test_decreaseKey" << endl;
    }
}
