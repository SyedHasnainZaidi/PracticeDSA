#include <iostream>
#include <cstdlib>

using namespace std;

struct BSTNode {
    int data;
    BSTNode* left;
    BSTNode* right;
};

BSTNode* insert(BSTNode* node, int insertValue) {
    if (node == NULL) {
        node = (BSTNode*)malloc(sizeof(BSTNode));
        node->data = insertValue;
        node->left = node->right = NULL;
        return node;
    }

    if (insertValue < node->data) {
        node->left = insert(node->left, insertValue);
    } else {
        node->right = insert(node->right, insertValue);
    }

    return node;
}

void search(BSTNode* node, int searchValue) {
    if (node == NULL) {
        cout << "Value not found" << endl;
        return;
    }

    if (searchValue == node->data) {
        cout << "Value Found" << endl;
        return;
    }

    if (searchValue < node->data) {
        search(node->left, searchValue);
    } else {
        search(node->right, searchValue);
    }
}

void Inordertrav(BSTNode* node) {
    if (node != NULL) {
        Inordertrav(node->left);
        cout << node->data << " ";
        Inordertrav(node->right);
    }
}

void Preordertrav(BSTNode* node) {
    if (node != NULL) {
        cout << node->data << " ";
        Preordertrav(node->left);
        Preordertrav(node->right);
    }
}

void Postordertrav(BSTNode* node) {
    if (node != NULL) {
        Postordertrav(node->left);
        Postordertrav(node->right);
        cout << node->data << " ";
    }
}

BSTNode* FindMin(BSTNode* node) {
    if (node == NULL) {
        cout << "NOT EXIST" << endl;
        return NULL;
    }

    while (node->left != NULL) {
        node = node->left;
    }
    cout << node->data << endl;
    return node;
}

BSTNode* FindMax(BSTNode* node) {
    if (node == NULL) {
        cout << "NOT EXIST" << endl;
        return NULL;
    }

    while (node->right != NULL) {
        node = node->right;
    }
    cout << node->data << endl;
    return node;
}

BSTNode* deleteBST(BSTNode* node, int toDel) {
    if (node == NULL) {
        cout << "DOES NOT EXIST" << endl;
        return node;
    }

    if (toDel < node->data) {
        node->left = deleteBST(node->left, toDel);
    } else if (toDel > node->data) {
        node->right = deleteBST(node->right, toDel);
    } else {
        if (node->left == NULL) {
            BSTNode* temp = node->right;
            free(node);
            return temp;
        } else if (node->right == NULL) {
            BSTNode* temp = node->left;
            free(node);
            return temp;
        }

        BSTNode* temp = FindMin(node->right);
        node->data = temp->data;
        node->right = deleteBST(node->right, temp->data);
    }

    return node;
}

int main() {
    BSTNode* Root = NULL;
    int insertValue, searchValue, ch, toDel;

    do {
        cout << "\n1. INSERT\n2. SEARCH\n3. INORDER TRAVERSE\n4. PREORDER TRAVERSE\n5. POST ORDER TRAVERSE\n6. FIND MINIMUM VALUE\n7. FIND MAXIMUM VALUE\n8. DELETE\n0. END \n";
        cout << "Enter your choice: ";
        cin >> ch;

        if (ch == 1) {
            cout << "What value do you want to insert: ";
            cin >> insertValue;
            Root = insert(Root, insertValue);
        } else if (ch == 2) {
            cout << "What value do you want to search: ";
            cin >> searchValue;
            search(Root, searchValue);
        } else if (ch == 3) {
            cout << "In-orderly Traversed Tree: ";
            Inordertrav(Root);
            cout << endl;
        } else if (ch == 4) {
            cout << "Pre-orderly Traversed Tree: ";
            Preordertrav(Root);
            cout << endl;
        } else if (ch == 5) {
            cout << "Post-orderly Traversed Tree: ";
            Postordertrav(Root);
            cout << endl;
        } else if (ch == 6) {
            cout << "Minimum Value is: ";
            FindMin(Root);
        } else if (ch == 7) {
            cout << "Maximum Value is: ";
            FindMax(Root);
        } else if (ch == 8) {
            cout << "What value do you want to delete: ";
            cin >> toDel;
            Root = deleteBST(Root, toDel);
        } else if (ch == 0) {
            cout << "Exiting program..." << endl;
        } else {
            cout << "Invalid choice! Try again." << endl;
        }
    } while (ch != 0);

    return 0;
}