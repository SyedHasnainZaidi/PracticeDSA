#include <iostream>
#include <stdlib.h>
using namespace std;

struct Record{
	int data;
	Record* pre;
	Record* next;
};

void insert(Record**head,int val,bool atStart){ 	//for start insert both if null or not null
	Record*ptr=(Record*)malloc(sizeof(Record));
	ptr->data=val;
	Record*temp=*head;
	if(atStart){ //for start insert both if null or not null
		ptr->next=*head;
		if(*head!=NULL){//ye jab lagega jab koi value nahi hogi
			(*head)->pre=ptr;
		}
		*head=ptr;
	}else{
		while(temp->next!=NULL){//at end     temp!=NULL agur hum ye use kurrenge to temp null ho gaya phir value kahan add hogi
		temp=temp->next;
	}
	temp->next=ptr;
	ptr->pre=temp;
	}
	
}
void del(Record**head,int val){
	Record*temp=*head;
	if(temp!=NULL&&temp->data==val){//agur pehla hoga or koi value hogi koi value nahi bhi hogi to yehi use hoga
		*head=(*head)->next;
		if(head!=NULL){
				(*head)->pre=NULL;
		}
		free(temp);
		return;
	}
	while(temp!=NULL){//for middle nd last
		if(temp->data==val){
			if(temp->pre!=NULL){
				temp->pre->next=temp->next;
			}
			if(temp->next!=NULL){// for midd
			temp->next->pre=temp->pre;//agur temp ke age lsit khatum ho gayi to
			}
			free(temp);
		}
		temp=temp->next;//isme temp ko update bad me kur rahe hen is waja se != null likha hw warna ->next null likhte or ye last number tak nahi jayega agur ye kurenge to ->next nul
		
	}
	
	
}
void search(Record*head,int val){
	Record*temp=head;
	int count=0;
	while(temp!=NULL){//jab huminsert kurenge to hi sirf ek pehle rukenge
		if(temp->data==val){
			cout<<"number found";
			count++;
			break;
		}
		temp=temp->next;
		if(count!=1){
			cout<<"number not in the list";
		}
	}
}
void print(Record*head){
	Record*temp=head;
	while(temp!=NULL){
		cout<<temp->data<<"->";
		temp=temp->next;
		
		}
		cout<<"NULL";
}
int main() {
    Record* head = NULL; 

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
                insert(&head, value, true); 
                break;
            }
            case 2: {
                int value;
                cout << "Enter value to insert at the end: ";
                cin >> value;
                insert(&head, value, false); 
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
                del(&head, delVal); 
                break;
            }
            case 6:
                cout << "Exiting..." << endl; 
                break;
            default:
                cout << "Invalid input. Please enter a number between 1 and 6." << endl;
                break;
        }
    } while (n != 6); 

    return 0;
}
