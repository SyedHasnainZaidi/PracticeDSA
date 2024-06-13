#include <iostream>
using namespace std;

void heapify(int heapTree[], int heapSize, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < heapSize && heapTree[l] > heapTree[largest])
        largest = l;

    if (r < heapSize && heapTree[r] > heapTree[largest])
        largest = r;

    if (largest != i) {
        swap(heapTree[i], heapTree[largest]);
        heapify(heapTree, heapSize, largest);
    }
}

void insert(int heapTree[], int& heapSize, int newNum) {
    int index = heapSize;
    heapSize++;
    heapTree[index] = newNum;

    while (index > 0 && heapTree[index] > heapTree[(index - 1) / 2]) {
        swap(heapTree[index], heapTree[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

void deleteNode(int heapTree[], int& heapSize, int num) {
    int i;
    for (i = 0; i < heapSize; i++) {
        if (num == heapTree[i])
            break;
    }

    if (i == heapSize) {
        cout << "Element not found in heap!" << endl;
        return;
    }

    swap(heapTree[i], heapTree[heapSize - 1]);
    heapSize--;

    for (int i = heapSize / 2 - 1; i >= 0; i--) {
        heapify(heapTree, heapSize, i);
    }
}

void printArray(int heapTree[], int heapSize) {
    cout << "Max-Heap array: ";
    for (int i = 0; i < heapSize; ++i)
        cout << heapTree[i] << " ";
    cout << "\n";
}

int main() {
    int size, ch, todel, insertVal;

    cout << "Enter the size of the max heap: ";
    cin >> size;
    if (size <= 0) {
        cout << "Invalid size! Exiting..." << endl;
        return 1;
    }

    int heapTree[size];
    int heapSize = 0;

    do {
        cout << "1. Insert\n2. Delete\n3. Max-Heap Array\n4. End\n";
        cin >> ch;
        if (ch == 1) {
            cout << "Enter the value you want to insert: ";
            cin >> insertVal;
            insert(heapTree, heapSize, insertVal);
        }
        else if (ch == 2) {
            cout << "Enter value you want to delete: ";
            cin >> todel;
            deleteNode(heapTree, heapSize, todel);
            cout << "After deleting an element: ";
            printArray(heapTree, heapSize);
        }
        else if (ch == 3) {
            printArray(heapTree, heapSize);
        }
        else if (ch != 4) {
            cout << "Invalid choice! Please enter again." << endl;
        }
    } while (ch != 4);

    return 0;
}
