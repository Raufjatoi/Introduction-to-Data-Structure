// tree stores elements in a tree like format with root and leaves (left and right) 🌳

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    
    //constructor
    Node(int v) : data(v), left(nullptr), right(nullptr) {}
};

struct Tree {
    Node* root;

    Tree() : root(nullptr) {}
    
    // add  
    void add(int v){
        Node* n = new Node(v);
        if (root == nullptr){
            root = n;
        } else {
            Node* t = root;
            while (true) {
                // if value is < data in that root 
                if (v < t -> data){
                    // if roots left leave ( node ) is empty add that to that 
                    if (t -> left == nullptr){
                        t -> left = n;
                        break;
                    } else {
                        // else if left is not empty, root become the left node and it goes over 
                        t = t -> left;
                    }
                }
                // if value is > data in that root 
                if (v > t -> data){
                    // if roots right leave ( node ) is empty add that to that 
                    if (t -> right == nullptr){
                        t -> right = n;
                        break;
                    } else {
                        // else if right is not empty, root become the right node and it goes over 
                        t = t -> right;
                }
            }
        }
    }
    }
};

int main (){
    Tree t;

    t.add(2);
    t.add(1);
    t.add(3);

    cout << t.root -> data << endl;
    cout << t.root -> left -> data << endl;
    cout << t.root -> right -> data<< endl;
}