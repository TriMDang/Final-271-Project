#include "WeightedGraph.cpp"
#include "PriorityQueue.cpp"
#include <iostream>

void test_heapify(int &testPassed, int &testFailed);
void test_buildHeap(int &testPassed, int &testFailed);
void test_insert(int &testpassed, int &testFailed);
void test_getMin(int &testPassed, int &testFailed);
void test_remove(int &testPassed, int &testFailed);
void test_decreasekey(int &testPassed, int &testFailed);
void test_extractkey(int &testPassed, int &testFailed);
void test_left_right(int &testPassed, int &testFailed);

using namespace std;

int main(){
    int testsPassed = 0;
    int testsFailed = 0;

   // test_heapify(testsPassed, testsFailed);
    //test_buildHeap(testsPassed, testsFailed);
    test_insert(testsPassed, testsFailed);
    //test_getMin(testsPassed, testsFailed);
    //test_remove(testsPassed, testsFailed);
    //test_decreasekey(testsPassed, testsFailed);
    //test_extracmin(testPassed, testsFailed);
    //test_left_right(int &testPassed, int &testFailed);

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

    if (pQueue[2] == 3) {
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

void test_decreasekey(int &testPassed, int testFailed){
    MinPQueue<int> pQueue;
    pQueue.insert(1);
    pQueue.insert(5);
    pQueue.insert(7);
    pQueue.insert(8);
    pQueue.insert(3);
    pQueue.insert(9);
    
    pQueue.decreaseKey(4, 2);

   int minValue = pQueue.extractMin(); // Extract the minimum value
    if (minValue == 1) {
        // Check the heap structure manually
        if (pQueue.isValidHeap()) {
            cout << "Test Passed: decreaseKey works correctly." << endl;
            testPassed++;
        } else {
            cout << "Test Failed: Heap structure is invalid after decreaseKey." << endl;
            testFailed++;
        }
    } else {
        cout << "Test Failed: Minimum value is incorrect after decreaseKey. Expected 1 but got " << minValue << endl;
        testFailed++;
    }
    
}

void test_extractmin(int &testPassed, int &testFailed){
MinPQueue<int> pQueue;
    pQueue.insert(1);
    pQueue.insert(5);
    pQueue.insert(7);
    pQueue.insert(8);
    pQueue.insert(3);
    pQueue.insert(9);
    
    pQueue.extractMin();
    
    int extractedMin = pQueue.extractMin();

 
    if (extractedMin == 1) { 
        if (pQueue.isValidHeap()) { 
            cout << "Test Passed: extractMin correctly returned the minimum value and maintained heap property." << endl;
            testPassed++;
        } else {
            cout << "Test Failed: Heap property is invalid after extractMin." << endl;
            testFailed++;
        }
    } else {
        cout << "Test Failed: extractMin returned incorrect value. Expected 1 but got " << extractedMin << endl;
        testFailed++;
    }

}


void test_left_right(int &testPassed, int &testFailed)
  MinPQueue<int> pQueue;


    pQueue.insert(10);  
    pQueue.insert(20); 
    pQueue.insert(30); 
    pQueue.insert(40); 
    pQueue.insert(50); 


    bool testSuccess = true;


    if (pQueue.left(0) != 1 || pQueue.right(0) != 2) {
        cout << "Test Failed: Left or right child of index 0 is incorrect." << endl;
        testSuccess = false;
    }
    if (pQueue.parent(1) != 0 || pQueue.parent(2) != 0) {
        cout << "Test Failed: Parent of index 1 or 2 is incorrect." << endl;
        testSuccess = false;
    }


    if (pQueue.left(1) != 3 || pQueue.right(1) != 4) {
        cout << "Test Failed: Left or right child of index 1 is incorrect." << endl;
        testSuccess = false;
    }
    if (pQueue.parent(3) != 1 || pQueue.parent(4) != 1) {
        cout << "Test Failed: Parent of index 3 or 4 is incorrect." << endl;
        testSuccess = false;
    }


    if (testSuccess) {
        cout << "Test Passed: Left, right, and parent operations work correctly." << endl;
        testPassed++;
    } else {
        testFailed++;
    }

