// priority queue will priorite the queue based on its priority
#include <iostream>
using namespace std;

struct Node {
    int data;     
    int priority; 
    Node* next;   

    Node(int d, int p) : data(d), priority(p) {}
};

void enqueue(Node*& head, int data, int priority) {
    Node* n = new Node(data, priority);

    // queue is empty or the new node has the highest priority
    if (!head || priority < head->priority) {
        n->next = head;
        head = n;
        return;
    }

    // correct position to insert the new node
    Node* current = head;
    while (current->next && current->next->priority <= priority) {
        current = current->next;
    }

    n->next = current->next;
    current->next = n;
}

void print(Node* head) {
    while (head) {
        cout << "data: " << head->data << ", priority: " << head->priority << endl;
        head = head->next;
    }
}

int main() {
    Node* pq = nullptr;
    enqueue(pq, 10, 2);
    enqueue(pq, 20, 1);
    enqueue(pq, 30, 3);

    print(pq);

}