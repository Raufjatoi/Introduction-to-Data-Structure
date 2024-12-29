// heap is a tree structure that maintains priority order.
#include <iostream>
#include <vector>
using namespace std;

struct Heap {
    vector<pair<int, int>> heap; // pair: {priority, data}

    // helper functions to get parent and child indices
    int parent(int i) { return (i - 1) / 2; }
    int leftChild(int i) { return 2 * i + 1; }
    int rightChild(int i) { return 2 * i + 2; }

    // add
    void push(int data, int priority) {
        heap.push_back({priority, data}); 
        int i = heap.size() - 1;

        while (i != 0 && heap[parent(i)].first > heap[i].first) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    // remove and return the element with the highest priority (lowest value)
    pair<int, int> pop() {
        if (heap.empty()) {
            throw runtime_error("Heap is empty");
        }

        pair<int, int> root = heap[0];
        heap[0] = heap.back(); //  last element to the root
        heap.pop_back();       // remove last element

        heapify(0); // restore heap property
        return root;
    }

    // min-heap
    void heapify(int i) {
        int smallest = i;
        int left = leftChild(i);
        int right = rightChild(i);

        // smallest among root, left child, and right child
        if (left < heap.size() && heap[left].first < heap[smallest].first) {
            smallest = left;
        }
        if (right < heap.size() && heap[right].first < heap[smallest].first) {
            smallest = right;
        }

        // swap and continue heapifying if the root is not the smallest
        if (smallest != i) {
            swap(heap[i], heap[smallest]);
            heapify(smallest);
        }
    }

    // if the heap is empty
    bool isEmpty() {
        return heap.empty();
    }

    // print 
    void print() {
        for (auto &p : heap) {
            cout << "data: " << p.second << ", priority: " << p.first << endl;
        }
    }
};

int main() {
    Heap pq;

    pq.push(10, 2);
    pq.push(20, 1); 
    pq.push(30, 3);

    pq.print();

    cout << endl;
    cout<< "after poping left leave" << endl;
    cout<< endl;
    
    auto top = pq.pop(); 
    pq.print();
}