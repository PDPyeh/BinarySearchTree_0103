
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

    void search(string element, Node*& parent, Node*& currentNode) {
        
        currentNode = ROOT;
        parent = NULL;
        while ((currentNode != NULL) && (currentNode->info != element)) {
            parent = currentNode;
            if (element < currentNode->info)
                currentNode = currentNode->leftchild;
            else
                currentNode = currentNode->rightchild;
        }

    }
    
    void inorder(Node* ptr) {
        if (ROOT == NULL) {
            cout << "Tree is Empty" << endl;
            return;
        }
        if (ptr != NULL) {
            inorder(ptr->leftchild);
            cout << ptr->info << " ";
            inorder(ptr->rightchild);
            
        }
    }

    void preorder(Node* ptr) {
        if (ROOT == NULL) {
            cout << "Tree is Empty" << endl;
            return;
        }
        if (ptr != NULL) {
            
            cout << ptr->info << " ";
            preorder(ptr->leftchild);
            preorder(ptr->rightchild);

        }
    }

    void postorder(Node* ptr) {
        if (ROOT == NULL) {
            cout << "Tree is Empty" << endl;
            return;
        }
        if (ptr != NULL) {

            postorder(ptr->leftchild);
            postorder(ptr->rightchild);
            cout << ptr->info << " ";
        }
    }
    
};

int main()
{
    BinaryTree obj;
    while (true)
    {
        cout << "\nMenu" << endl;
        cout << "1. Implement insert Operation" << endl;
        cout << "2. Perform Inorder traversal" << endl;
        cout << "3. Perform preorder traversal" << endl;
        cout << "4. Perform postorder traversal" << endl;
        cout << "5. Exit" << endl;
        cout << "\nEnter Your Choice (1 to 5)" << endl;

        char ch;
        cin >> ch;
        cout << endl;

        switch (ch) {
        case '1': {
            cout << "Enter a word :";
            string word;
            cin >> word;
            obj.insert(word);
            break;
        }
        case '2': {
            obj.inorder(obj.ROOT);
            break;
        }
        case '3': {
            obj.preorder(obj.ROOT);
            break;
        }
        case '4': {
            obj.postorder(obj.ROOT);
            break;
        }
        case '5': 
            return 0;
        default: {
            cout << "Invalid Option" << endl;
            break;
        }

        }
    }
}


