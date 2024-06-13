#include<iostream>
#include<stdlib.h>
using namespace std;
struct Record {
    int rollNo;
    float CGPA;
    Record* next;
};

// Insert function
void insert (Record** head){
    Record* ptr = (Record*)malloc(sizeof(Record));
    cout << "Enter roll no of Student : ";
    cin >> ptr->rollNo;
    cout << "Enter CGPA of Student : ";
    cin >> ptr->CGPA;
    ptr->next = NULL;
    if (*head == NULL){
        *head = ptr;
        return;
    }
    Record* curr = *head;
    while (curr->next != NULL){
        curr = curr->next;
    }
    curr->next = ptr;
}
// Search function
void search(Record** head){
    if (*head == NULL){
        cout << "List is Empty "<< endl;
        return;
    }
    cout << "Enter roll no which you want to search : ";
    int toSearch;
    cin >> toSearch;
    Record* curr = *head;
    while (curr != NULL){
        if (curr->rollNo == toSearch){
            cout << "CGPA of Student is : "<< curr->CGPA <<endl;
            return;
        }
        curr = curr->next;
    }
    if (curr == NULL){
        cout << "Roll no not Found "<< endl;
    }
    
}
// print function
void print (Record** head){
    if (*head == NULL){
        cout << "List is empty "<< endl;
        return;
    }
    Record* curr = *head;
    while (curr != NULL){
        cout << "CGPA of Roll no "<<curr->rollNo<< " is "<<curr->CGPA<< endl;
        curr = curr->next;
    }
}

void del(Record** head){
	if (*head == NULL){
        cout << "List is empty "<< endl;
        return;
    }
	Record *cur=*head;
	int todel;
	cout<<"which number you want to delete";
	cin>>todel;
	if(todel==cur->rollNo){
		*head=(*head)->next;
		free(cur);
	}else{
		Record*prev=*head;
		cur=(*head)->next;
		while(cur!=NULL){
			if(cur->rollNo==todel){
				prev->next=cur->next;
				free(cur);
				break;
				
		}
		cur=cur->next;
		prev=prev->next;
	}
	
	}
}
void delete_all(Record**head){
	 if (*head == NULL){
        cout << "List is empty "<< endl;
        return;
    }
    Record* cur = *head;
    while(cur!=NULL){
    	*head=(*head)->next;
    	free(cur);
    	cur=*head;
	}
}
int main (){
    Record* head = NULL;
    int n;
    do {
        cout << "Enter 1 to Insert data " << endl << "Enter 2 to search data " << endl << "Enter 3 to print all Record" << endl << "Enter 4 to delete a record" << endl<< "Enter 5 to delete all" << endl<< endl << "Enter 6 to Quit " << endl;
        cin >> n;
        if (n == 1){
            insert (&head);
        } else if (n == 2){
            search (&head);
        } else if (n == 3){
            print(&head);
        } else if(n==4){
        	del(&head);
		}else if(n==5){
			delete_all(&head);
		}

    } while (n != 6 );
}