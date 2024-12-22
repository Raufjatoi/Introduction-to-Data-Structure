// queue is first in first out (FIFO)
#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int v): data(v) , next (nullptr) {}
};

struct Queue{
    Node* head;

    Queue(): head (nullptr) {}

    // enqueue will add a new node to the end of the queue
    void enqueue(int v){
        Node* n = new Node(v);
        if (head == nullptr){
            head = n;
        } else {
            Node* t = head;
            while (t -> next != nullptr){
                t = t -> next;
            }
            t -> next = n;
        }
    }

    // dequeue will remove the first node from the queue
    void dequeue(){
        if(head == nullptr){
            cout << "queue is empty" << endl;
        } else {
            Node* t = head;
            head = head -> next;
            delete t;
        }
    }

    void print(){
        Node* t = head;
        while (t != nullptr){
            cout << t -> data << " -> ";
            t = t -> next;
        } 
        cout << "null" << endl;
    }
};

int main (){
    Queue l;

    l.enqueue(1);
    l.enqueue(2);
    l.enqueue(3);

    l.print();

    l.dequeue();

    l.print();
}