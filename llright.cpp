#include <iostream>
#include <cstdlib>
using namespace std;

struct Record{
	int Rno;
	float gp;
	Record *next;
	
	
};


void insert(Record **head){
	
	Record *ptr;
	ptr=(Record*)malloc(sizeof(Record));
	 
	 cout<<"enter roll no";
	 cin>>ptr->Rno;
	cout<<"enter gp";
	cin>>ptr->gp;
	
	
	
	if(*head==nullptr){
		
		*head=ptr;
		
	}
	else{
		Record *curr=*head;
		
		while(curr->next!=nullptr){
			
			curr=curr->next;
			
		}
		
		curr->next=ptr;
		
	}
	
	
}



void search(Record **head){
    int tosearch;
    cout<<"enter rollno to search";
    cin>>tosearch;
    
    Record *curr=*head;
    
    while(curr!=nullptr){
    if(curr->Rno==tosearch){
    cout<<"value found";
    break;
}
else{
curr=curr->next;

}

}

}

void display(Record **head){
    
    Record *curr=*head;
   
   while(curr!=nullptr){
    
    cout<<curr->Rno <<"\n";
    cout<<curr->gp<<"\n";
    curr=curr->next;
    
    

}
}

int main(){
	
	Record *head=nullptr;
	
	
	int choice;
 cout<< "press 1 for insert,2 for search,3 for print";
	
	cin>>choice;
	
	
	while(choice==1 || choice==2 || choice==3){
	   
	if(choice==1){
		
		insert(&head);
		string c;
	
	cout<<"do you want to continue";
	cin>>c;
	
	while(c=="yes"){
	    insert(&head);
	   cout<<"do you want to continue";
	   cin>>c;
	   
	    	}
	   if(c!="yes"){
	       choice--;
	   } 	
	}
	
	else if(choice==2){
		
		search(&head);
		
	}
	else if(choice==3) {
		
		display(&head);
		
	}
	cout<< "press 1 for insert,2 for search,3 for print";
	
	cin>>choice;
	}
}