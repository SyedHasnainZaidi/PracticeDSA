#include <iostream>
using namespace std;

void linear_search(int hash_table[],int size){
	int tosearch;
	
   	cout<<"what you want to search";
   	cin>>tosearch;
   	int index=tosearch%size;
   	int originalindex=index;
   	while(hash_table[index]!=-1){
	   
   		if(hash_table[index]==tosearch){
   			cout<<"number found ";
   			break;
   		}
		index=(index+1)%size;//or index++
		if(index==originalindex){
   			cout<<"number not found";
   			break;
   		}
   		
	   }
	   
   		cout << "Number not found!" << endl;
	   }
void Quardratic_search(int hash_table[], int size){
	int tosearch;
   	cout<<"what you want to search";
   	cin>>tosearch;
   	int index=tosearch%size;
   	int originalindex=index;
   	int i=1;
   	while(hash_table[index]!=-1){
	   
   		if(hash_table[index]==tosearch){
   			cout<<"number found ";
   			break;
   		}
		index=(index+i*i)%size;
   		i++;
		if(index==originalindex){
   			cout<<"number not found";
   			break;
   		}
	   }
   		cout<<"number not found";
	   }
void linear_insert(int hash_table[],int size){
	int toinsert;
   	cout<<"what you want to insert";
   	cin>>toinsert;
   	int index =toinsert%size;
	int originalindex=index;
   	while(hash_table[index]!=-1){
   		index=(index+1)%size;
   		if(index==originalindex){
   			break;
   		}
	   }
	hash_table[index]=toinsert;
	
}void Quardratic_insert(int hash_table[],int size){
	int toinsert;
	int i=1;
   	cout<<"what you want to insert";
   	cin>>toinsert;
   	int index =toinsert%size;
	int originalindex=index;
   	while(hash_table[index]!=-1){
   		index=(index+i*i)%size;
   		i++;
   		if(index==originalindex){
   			break;
   		}
	   }
	hash_table[index]=toinsert;
	
}

int main(){
	int size;
	int con;
	int sch;
	int ich;
	cout<<"enter the size of array";
	cin>>size;	
	
	int hash_table[size];
	for (int i = 0; i < size; i++) {
        hash_table[i]=-1;
        
    }
    cout<<"for search 1 ,or for insert 2";
    cin>>con;
    if(con==1){
    	cout<<"Type 1 for linear probing Type 2 for Quadratic ";
    	cin>>sch;
    	if (sch==1){
    		linear_search(hash_table,size);
    		
		}else if(sch==2){
			Quardratic_search(hash_table,size);
		}else{
		cout<<"error 402";
	}
    	
	}else if(con==2){
			cout<<"Type 1 for linear insert Type 2 for Quadratic insert ";
    	cin>>ich;
    	if (ich==1){
    		linear_insert(hash_table,size);
    		
		}else if(ich==2){
			Quardratic_insert(hash_table,size);
		}else{
		cout<<"error 403";
	}
	
	}else{
		cout<<"error 404";
	}
return 0;	
	}
	
