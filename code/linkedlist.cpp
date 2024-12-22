#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prv;
};

int main(){
    Node* head = new Node();
    Node* second = new Node();
    Node* third = new Node();

    head -> data = 1;
    head -> next = second;
    second -> data = 2;
    second -> next = third;
    third -> data = 3;
    third -> next = NULL;

    Node* t = head;
    while ( t != NULL){
        cout << "location: " << t << "value: " << t -> data << " next: " << t -> next << endl;
        t = t -> next;
    }
}