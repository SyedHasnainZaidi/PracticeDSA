#include <iostream>
#include <stdlib.h>
using namespace std;

struct game{
	int data;
	game* next;
};



void insert(game**head,int value,bool atStart){//**ye jab use kurenge jab hume isko change kurna hoga
	game* ptr=(game*)malloc(sizeof(game));
	ptr->data=value;
	if(*head==NULL){
		*head=ptr;
		ptr->next=*head;
	}
	game* temp=*head;
	while(temp->next!=*head){
		temp=temp->next;
	}
	temp->next=ptr;
	ptr->next=*head;
	if(atStart){//start me isert ke lie agur phle se list ho
		*head=ptr;	
	}
	
	}

  void todell(game** head, int val) {
    game* curr = *head;
    game* pre = NULL;
    if (*head == NULL) {
        cout << "array is empty";
    }
    while (curr->next != *head && curr->data != val) {
        pre = curr;
        curr = curr->next;
    }
    if (curr->data == val || (curr->next == *head && curr->data == val))
{
        if (pre == NULL) { // yani first hi element he list me
            curr = (*head)->next;
        }
        if (pre != NULL) { // middle
            pre->next = curr->next;
        }
        if (curr->next == *head && pre != NULL) { // for del last element
            pre->next = *head;
        }
        free(curr);
    } else {
        cout << "value not found";
    }
}

void search(game*head,int val){
	if(head==NULL){
		cout<<"list is empty";
	}
	int count=0;
	game* temp=head;
	do{
		if(temp->data==val){
			cout<<temp->data<<"found";
			count++;
		}
		temp=temp->next;	
	}while(temp!=head);//isme while lagayenge to temp to pehle se hi head he to ye loop me nahi ayega
	if(count!=1){
		cout<<"number not in the list";
	}
}
void print (game*head){//**ye jab use kurenge jab hume isko sirf print kurna hoga
	game* temp=head;
	if(head==NULL){
		cout<<"list is empty";
	}
	do{// we can also use while instead of this
		cout<<temp->data<<"->";
		temp=temp->next;
	}while(temp!=head);//while is waja se nahi lagya q ke ye last value pe nahi jata
	//while (temp != head) {
//        cout << temp->data << "->";
//        temp = temp->next;
//    }
	cout<<"head";
}
int main(){
	game *head=NULL;
    int n;
    do {
        cout << "Enter 1 to Insert data at the start" << endl
             << "Enter 2 to Insert data at the end" << endl
             << "Enter 3 to Search data" << endl
             << "Enter 4 to Print all Records" << endl
             << "Enter 5 to Delete a record" << endl
             << "Enter 6 to Quit" << endl;

        cin >> n;

        switch (n) {
            case 1: {
                int value;
                cout << "Enter value to insert at the start: ";
                cin >> value;
                insert(&head, value, true); // Insert at the start
                break;
            }
            case 2: {
                int value;
                cout << "Enter value to insert at the end: ";
                cin >> value;
                insert(&head, value, false); // Insert at the end
                break;
            }
            case 3: {
                int searchVal;
                cout << "Enter value to search: ";
                cin >> searchVal;
                search(head, searchVal);
                break;
            }
            case 4:
                print(head);
                break;
            case 5: {
                int delVal;
                cout << "Enter value to delete: ";
                cin >> delVal;
                todell(&head, delVal);
                break;
            }
            default:
                if (n != 6)
                    cout << "Invalid input. Please enter a number between 1 and 6." << endl;
                break;
        }
    } while (n != 6);

    return 0;

	
}