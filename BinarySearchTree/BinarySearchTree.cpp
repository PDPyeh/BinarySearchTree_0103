
#include <iostream>
#include <string>
using namespace std;

class Node {
public :
    string info;
    Node* leftchild;
    Node* rightchild;

    //Constructor
    Node(string i, Node * l, Node* r) {
        info = i;
        leftchild = l;
        rightchild = r;
    }
};

class BinaryTree {
public:
    Node* ROOT;

    BinaryTree() {
        ROOT = NULL; //Init ROOT to NULL
    }
    void insert(string element) {

    }
};

int main()
{
    
}

