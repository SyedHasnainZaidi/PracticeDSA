#include <iostream>
#include <stdlib.h>
using namespace std; 

const int MAX_SIZE = 100; 

void push(int stack_table[],int val,int capacity,int &top){
	if(top==capacity-1){
		cout<<"stack ovefllow";
		return;
	}
	stack_table[top++]=val;
}
int pop(int stack_table[],int &top){
	if(top==-1){
		cout<<"stack underflow";
	return -1;	
	}
	return stack_table[top--];
}

int main() {
    int top = -1;
    int size;
    cout << "Enter size of array: ";
    cin >> size;
    int stack_table[MAX_SIZE];

    int choice;
    do {
        cout << "\n1. Push\n2. Pop\n3. Exit\nEnter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                int val;
                cout << "Enter value to push: ";
                cin >> val;
                push(stack_table, val, size, top);
                break;
            }
            case 2: {
                int poppedElement = pop(stack_table, top);
                if (poppedElement != -1) {
                    cout << "Popped element: " << poppedElement << endl;
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
