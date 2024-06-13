#include <iostream>
#include <stdlib.h>
using namespace std;

struct Record{
    int Rno;
    float GPA;
    Record* next;
};
Record* head = nullptr;

void insert(){
    char choice;
    do {
        Record* ptr = (Record*)malloc(sizeof(Record));
        cout << "Insert roll number: ";
        cin >> ptr->Rno;
        cout << "Insert GPA: ";
        cin >> ptr->GPA;
        ptr->next = nullptr;
        if(head == nullptr){
            head = ptr;
        }
        else{
            Record* curr = head;
            while(curr->next != nullptr){
                curr = curr->next;
            }
            curr->next = ptr;
        }
        cout << "Do you want to insert another record? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');
}

void search(){
    int tosearch;
    char choice;
    do {
        cout << "Enter student's roll number: ";
        cin >> tosearch;
        Record* curr = head;
        bool found = false;
        while(curr != nullptr){
            if(curr->Rno == tosearch){
                cout << "Roll number: " << curr->Rno << endl;
                cout << "GPA: " << curr->GPA << endl;
                found = true;
                break;
            }
            curr = curr->next;
        }
        if (!found)
            cout << "Record not found!" << endl;
        cout << "Do you want to search for another record? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');
}

void print(){
    Record* curr = head;
    while(curr != nullptr){
        cout << "Roll number: " << curr->Rno << "  GPA: " << curr->GPA << endl;
        curr = curr->next;
    }
}

int main(){
    int choice;
    do{
        cout << "Menu:\n1. Insert record\n2. Search record\n3. Print records\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice){
            case 1:
                insert();
                break;
            case 2:
                search();
                break;
            case 3:
                print();
                break;
            case 4:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while(choice != 4);

    return 0;
}
