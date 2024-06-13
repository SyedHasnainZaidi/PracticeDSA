#include <iostream>
#include <cstdlib>
using namespace std;

struct Node {
    int value;
    Node* right;
    Node* left;
    int height;
};

Node* createNode(int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->value = value;
    node->right = NULL;
    node->left = NULL;
    node->height = 1; // New node is initially added at leaf
    return node;
}

int height(Node* root) {
    if (root == NULL) {
        return 0;
    }
    return root->height;
}


Node* rightRotate(Node* root) {
    Node* temp = root->left;
    root->left = temp->right;
    temp->right = root;

    
    root->height = max(height(root->left), height(root->right)) + 1;
    temp->height = max(height(temp->left), height(temp->right)) + 1;

    return temp;
}


Node* leftRotate(Node* root) {
    Node* temp = root->right;
    root->right = temp->left;
    temp->left = root;

    
    root->height = max(height(root->left), height(root->right)) + 1;
    temp->height = max(height(temp->left), height(temp->right)) + 1;

    return temp;
}


int getBalance(Node* root) {
    if (root == NULL) {
        return 0;
    }
    return height(root->left) - height(root->right);
}

Node* Insert(Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->value) {
        root->left = Insert(root->left, value);
    } else if (value > root->value) {
        root->right = Insert(root->right, value);
    } else {
        return root;
    }

    root->height = max(height(root->left), height(root->right)) + 1;
    
    int balance = getBalance(root);

    // Left Left Case
    if (balance > 1 && value < root->left->value) {
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 && value > root->right->value) {
        return leftRotate(root);
    }

    // Left Right Case
    if (balance > 1 && value > root->left->value) {// neche ka ulat
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Left Case
    if (balance < -1 && value < root->right->value) {//agur value jo inter hoi he to wo choti he yani ~
        root->right = rightRotate(root->right);                                      //                   ~   
        return leftRotate(root);                                                                 //    ~
    }

    return root;
}


bool Search(Node* root, int toSearch) {
    if (root == NULL) {
        return false;
    }
    if (root->value == toSearch) {
        return true;
    }

    if (toSearch > root->value) {
        return Search(root->right, toSearch);
    } else {
        return Search(root->left, toSearch);
    }
}

void Display(Node* root, string status = "Head") { //pehle sare left phir right
    if (root == NULL) {
        return;
    }
    
    cout << "Value: " << root->value << " - " << status << endl;
    
    if (root->left != NULL) {
        Display(root->left, "Left Child");
    }
    
    if (root->right != NULL) {
        Display(root->right, "Right Child");
    }
}


int main() {
    Node* root = NULL;
    

    while (true) {
        cout << "Press" << endl;
        cout << "1. Insert" << endl;
        cout << "2. Search" << endl;
        cout << "3. Display" << endl;
        cout << "4. Height of tree" << endl;
        cout << "0. Exit" << endl;

        int option;
        cin >> option;

        switch (option) {
            case 1: {
                cout << "Enter value: ";
                int value;
                cin >> value;
                root = Insert(root, value);
                break;
            }
            case 2: {
                cout << "Enter value: ";
                int toSearch;
                cin >> toSearch;

                bool isFound = Search(root, toSearch);
                isFound ? cout << "Found" << endl : cout << "Not Found" << endl;
                break;
            }
            case 3: {
                Display(root);
                cout << endl;
                break;
            }
            case 4: {
                cout << "Height of tree: " << height(root) << endl;
                break;
            }
            case 0: {
                return false;
                break;
            }
            default:
                break;
        }
    }

    return 0;
}
