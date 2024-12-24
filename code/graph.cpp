#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    // Constructor
    Node(int v) : data(v), next(NULL) {};
};

struct Edge {
    // source and destination
    int src, dest;

    Edge(int s, int d) : src(s), dest(d) {};

    // add 
    void addEdge(Node* adj[], Edge e) {
        Node* n = new Node(e.dest);
        n->next = adj[e.src - 1]; // Adjusting index to start from 1 instead of 0
        adj[e.src - 1] = n;
    }
};

int main() {
    int V = 4;
    Node* adj[V];  

    for (int i = 0; i < V; i++) {
        adj[i] = nullptr;
    }

    Edge e1(1, 2);
    e1.addEdge(adj, e1);
    Edge e2(1, 3);
    e2.addEdge(adj, e2);
    Edge e3(1, 4);
    e3.addEdge(adj, e3);
    Edge e4(2, 3);
    e4.addEdge(adj, e4);
    Edge e5(2, 4);
    e5.addEdge(adj, e5);
    Edge e6(3, 4);
    e6.addEdge(adj, e6);

    for (int i = 0; i < V; i++) {
        Node* n = adj[i];
        cout << i + 1 << " -> ";  // Adjusting index to start from 1 instead of 0
        while (n) {
            cout << n->data << " ";
            n = n->next;
        }
        cout << endl;
    }
}