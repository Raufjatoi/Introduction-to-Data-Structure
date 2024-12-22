// stack is last in first out (LIFO)
#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    
    // constructor
    Node(int v): data(v) , next (nullptr) {}
};

struct Stack{
    Node* head;
    
    Stack(): head (nullptr){}

    // push will add a new node to the top of the stack
    void push(int v){
        Node* n = new Node(v);
        n -> next = head;
        head = n;
    }

    // pop will remove the top node from the stack
    void pop(){
        if(head == nullptr){
            cout << "stack is empty" << endl;
        }  else {
            Node* t = head;
            head = head -> next;
            delete t;
        }   
    }

    // print 
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
    Stack l;

    l.push(1);
    l.push(2);
    l.push(3);

    l.print();

    l.pop();

    l.print();
}