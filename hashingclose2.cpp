#include <iostream>
using namespace std;

void linear_search(int hash_table[], int size) {
    int tosearch;
    cout << "Enter the number you want to search: ";
    cin >> tosearch;
    int index = tosearch % size;
    int originalindex = index;
    while (hash_table[index] != -1) {
        if (hash_table[index] == tosearch) {
            cout << "Number found!" << endl;
            return;
        }
        index = (index + 1) % size; 
        if (index == originalindex) {
            cout << "Number not found!" << endl;
            return;
        }
    }
    cout << "Number not found!" << endl;
}

void quadratic_search(int hash_table[], int size) {
    int tosearch;
    cout << "Enter the number you want to search: ";
    cin >> tosearch;
    int index = tosearch % size;
    int originalindex = index;
    int i = 1;
    while (hash_table[index] != -1) {
        if (hash_table[index] == tosearch) {
            cout << "Number found!" << endl;
            return;
        }
        index = (index + i * i) % size; 
        i++;
        if (index == originalindex) {
            cout << "Number not found!" << endl;
            return;
        }
    }
    cout << "Number not found!" << endl;
}

void linear_insert(int hash_table[], int size) {
	
    int toinsert;
    cout << "Enter the number you want to insert: ";
    cin >> toinsert;
    int index = toinsert % size;
    int originalindex = index;
    while (hash_table[index] != -1) {
        index = (index + 1) % size; 
        if (index == originalindex) {
            cout << "Hash table is full!" << endl;
            return;
        }
    }
    hash_table[index] = toinsert;
    cout << "Number inserted successfully!" << endl;
}

void quadratic_insert(int hash_table[], int size) {
    int toinsert;
    cout << "Enter the number you want to insert: ";
    cin >> toinsert;
    int index = toinsert % size;
    int originalindex = index;
    int i = 1;
    while (hash_table[index] != -1) {
        index = (index + i * i) % size; 
        i++;
        if (index == originalindex) {
            cout << "Hash table is full!" << endl;
            return;
        }
    }
    hash_table[index] = toinsert;
    cout << "Number inserted successfully at index " << index << endl;
}

int main() {
    int size;
    cout << "Enter the size of the hash table: ";
    cin >> size;

    int hash_table[size];
    for (int i = 0; i < size; i++) {
        hash_table[i] = -1;
    }

    int choice;
    cout << "Choose operation: 1 for search, 2 for insert: ";
    cin >> choice;
while(choice!=0){

    if (choice == 1) {
        int search_type;
        cout << "Choose search type: 1 for linear probing, 2 for quadratic probing: ";
        cin >> search_type;

        if (search_type == 1) {
            linear_search(hash_table, size);
        } else if (search_type == 2) {
            quadratic_search(hash_table, size);
        } else {
            cout << "Invalid search type!" << endl;
        }

    } else if (choice == 2) {
        int insert_type;
        cout << "Choose insert type: 1 for linear probing, 2 for quadratic probing: ";
        cin >> insert_type;

        if (insert_type == 1) {
            linear_insert(hash_table, size);
        } else if (insert_type == 2) {
            quadratic_insert(hash_table, size);
        } else {
            cout << "Invalid insert type!" << endl;
        }
    } else {
        cout << "Invalid choice!" << endl;
    }
    cout << "Choose operation: 1 for search, 2 for insert: ";
	cin>>choice;
}

}
//print full array