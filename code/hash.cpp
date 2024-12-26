// hash is a data structure that maps keys to values for efficient data retrieval using hash functions.
#include <iostream>
using namespace std;

struct Node{
    int key;
    int value;
    Node* next;

    // constructor 
    Node(int k, int v): key(k), value(v), next(nullptr) {}
};

struct Hash{
    static const int S = 10;
    Node* table[S];

    Hash(){
        for (int i =0; i < S; i++){
            table[i] = nullptr;
        }
    }

    // hash fun 
    int hashFunction(int key){
        return key % S;
    }

    void add( int key , int value ){
        int index = hashFunction(key); //index for the key
        Node* n = new Node(key, value); 

        if (table[index] == nullptr){
            table[index] = n;
        } else {
            Node* t = table[index];
            while (t -> next != nullptr){
                t = t -> next;
            }
            t -> next = n;
        }
    }

    void print(){
        for (int i = 0; i < S; i++){
            cout << i << ": ";
            Node* t = table[i];
            while(t != nullptr){
                cout << "[" << t-> key << ": " << t-> value << "] -> "; 
                t = t -> next;
            }
            cout << "null" << endl;
        }
    }
};


int main (){
    Hash table;

    table.add(10, 100);
    table.add(20, 200);
    table.add(30, 300);
    table.add(25, 250);
    table.add(27, 77);


    table.print();
}
