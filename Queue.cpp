#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

void enQue(int queue_table[], int val, int &front, int &back, int capacity) {
    if (back == capacity - 1) {
        cout << "Overflow\n";
        return;
    }
    if (front == -1 && back == -1) {
        front++;
        back++;
        queue_table[back] = val;
    } else {
        back++;
        queue_table[back] = val;
    }
}

int deque(int queue_table[], int &front, int &back) {
    if (front == -1 || front > back) {
        cout << "Underflow\n";
        return -1;
    } else {
        int frontValue = queue_table[front];
        front++;
        return frontValue;
    }
}

int main() {
    int front = -1;
    int back = -1;
    int queue_table[MAX_SIZE];
    int size;

    cout << "Enter size of array: ";
    cin >> size;

    int choice;
    do {
        cout << "\n1. Enqueue\n2. Dequeue\n3. Exit\nEnter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                int val;
                cout << "Enter value to enqueue: ";
                cin >> val;
                enQue(queue_table, val, front, back, size);
                break;
            }
            case 2: {
                int dequeuedValue = deque(queue_table, front, back);
                if (dequeuedValue != -1) {
                    cout << "Dequeued value: " << dequeuedValue << endl;
                }
                break;
            }
            case 3:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice" << endl;
        }
    } while (choice != 3);

    return 0;
}
