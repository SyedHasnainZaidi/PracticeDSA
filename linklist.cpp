#include <iostream>
#include <stdlib.h>
using namespace std;

struct game{
	int data;
	game* next;
};
//void insertatstart(game**head,int value){
//	game* ptr=(game*)malloc(sizeof(game));
//	ptr->data=value;
//	ptr->next=*head;
//	*head=ptr;
//	
//	
//}


void insert(game**head,int value){//**ye jab use kurenge jab hume isko change kurna hoga
	game* ptr=(game*)malloc(sizeof(game));
	ptr->data=value;
	ptr->next=NULL;
	if(*head==NULL){
		*head=ptr;
	}else{
		game* temp=*head;// trmp for triverse the list//*headto change and access head
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next=ptr;
	}

	
}
void tosearch(game*head,int value){
	game*temp=head;
	if(head==NULL){
		cout<<"list is empty";
		return;
	}
	while(temp!=NULL){
		if(temp->data==value){
			cout<<"value found"<<temp->data<<"\n";
			return;
		}
		temp=temp->next;
		if(temp==NULL) {
			cout<<"value not found";
		}
	}
}
void todel(game**head,int val){
	
	game*curr=*head;
	if(*head==NULL){
		cout<<"list is empty";
		return;
	}
	if(val==curr->data){
		*head=(*head)->next;
		free(curr);
	}else{
		game*pre=*head;
		curr=(*head)->next;
		while(curr!=NULL){
			if (val==curr->data){
				pre->next=curr->next;
				free(curr);
				break;
			}
			curr=curr->next;
			pre=pre->next;
		}
		
		
	}
}
void delall(game**head){
	if(*head==NULL){
		cout<<"list is empty";
		return;
	}
	game*curr=*head;
	while(curr!=NULL){
		*head=curr->next;
		free(curr);
		curr=*head;
	}
	
}
void print (game*head){//**ye jab use kurenge jab hume isko sirf print kurna hoga
	game* temp=head;
	while(temp!=NULL){
		cout<<temp->data<<" ->";
	temp=temp->next;
	}
	cout<<"NULL";
}
int main() {
    game* head = NULL;
    int n;
    do {
        cout << "Enter 1 to Insert data" << endl
             << "Enter 2 to Search data" << endl
             << "Enter 3 to Print all Records" << endl
             << "Enter 4 to Delete a record" << endl
             << "Enter 5 to Delete all records" << endl
             << "Enter 6 to Quit" << endl;
        cin >> n;
        switch (n) {
            case 1:
                int value;
                cout << "Enter the value to insert: ";
                cin >> value;
                insert(&head, value);
                break;
            case 2:
                cout << "Enter the value to search: ";
                cin >> value;
                tosearch(head, value);
                break;
            case 3:
                print(head);
                break;
            case 4:
                cout << "Enter the value to delete: ";
                cin >> value;
                todel(&head, value);
                break;
            case 5:
                delall(&head);
                break;
            case 6:
                break;
            default:
                cout << "Invalid input. Please enter a number between 1 and 6." << endl;
        }
    } while (n != 6);

    return 0;
}
