#include <iostream>
#include <stdlib.h>
using namespace std;

Record *ptr;
struct Record{
	int Rno;
	float GPA;
	Record*next;
};
Record*head=nullptr;
void insert(){
	Record *ptr(Record*)malloc(sizeof(Record));
	cout<<"insert roll number";
	cin>>ptr->Rno;
	cout<<"insert GPA";
	cin>>ptr->GPA;
	ptr->next=null;
	if(*head==null){
		*head=ptr;
	}
	else{
		REcord*curr=*head;
		while(cur->next!=null){
			curr=curr->next;
		}
		curr->next=ptr;
	}
	
}
void search(Record**head){
	int tosearch;
	cout<<"Enter students rollnumber"
	cin>>tosearch;
	Record*curr=head;
	while(curr!=null){
		if(curr->Rno==tosearch){
			cout<<curr->Rno;
			break;
		}else{
			curr=curr->next;	
		}
	}
}
void print(){
	Record*curr=*head;
	while(curr!=null){
		cout<<"Roll number"<<curr->Rno<<"  GPA"<<curr->GPA <<end1;
		curr=curr->next;
	}
}







