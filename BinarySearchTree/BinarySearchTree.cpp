
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
        Node* newNode = new Node(element, NULL, NULL);
        newNode->info = element; //Assign Value to data field on newNode
        newNode->leftchild = NULL; //Make leftchild of the newnode point to NULL
        newNode->rightchild = NULL; //Make rightchild of the newnode point to NULL

        Node * parent = NULL;
        Node* currentNode = NULL;
        search(element, parent, currentNode); //Locate Node will be the parent of the node tobe inserted

        if (parent == NULL) {
            ROOT = newNode;
            return;
        }
        if (element < parent->info) {
            parent->leftchild = newNode;
        }
        else if (element > parent->info) {
            parent->rightchild = newNode;
        }
    }

    
    
};

int main()
{
    
}

