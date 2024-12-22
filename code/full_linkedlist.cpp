#include <iostream> 
using namespace std;

struct Node{
    int data;
    Node* next;
    
    // constructor
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};

// linked list and its functions
struct LinkedList{
    Node* head;

    LinkedList(){
        head = NULL;
    }
    
    //add 
    void add(int data){
        Node* n = new Node(data);
        if ( head == NULL){
            head = n;
        } else {
            Node* t = head;
            while ( t -> next != NULL){
                t = t -> next;
            }
            t -> next = n;
        }
    }
    
    // remove
    void remove(){
        if (head == NULL){
            cout << "list is empty" << endl;
        } else {
            Node* t = head;
            while (t -> next -> next != NULL){
                t = t -> next;
            }
            t -> next = NULL;
        }
    }
 
    // print 
    void print(){
        Node* t = head;
        while (t != NULL ){
            cout << t -> data << " -> ";
            t = t -> next;
        }
        cout << "NULL" << endl;
    }
};

int main (){
    LinkedList l;

    l.add(1);
    l.add(2);
    l.add(3);
    l.add(4);

    l.print();

    l.remove();
    l.print();
}