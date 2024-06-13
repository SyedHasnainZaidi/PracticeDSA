#include <iostream>
#include <stdlib.h>
using namespace std;
struct BSTNode{
	int data;
	BSTNode*left;
	BSTNode*right;
};
//BSTNode* node = NULL;
BSTNode* insert(BSTNode*node,int value){
	if(node==NULL){
		node = ( BSTNode *)malloc(sizeof(BSTNode));
		node->data=value;
		node->left=node->right=NULL;
		return node;
	}
	if(value<node->data){
		node->left=insert(node->left,value);
	}else{
		node->right=insert(node->right,value);
	}
	
}
void search(BSTNode*node,int tosearch ){
	if(node==NULL){
		cout<<"number not found";
		return ;
	}if(tosearch==node->data){
		cout<<"number found ";
		return;
	}if(tosearch<node->data){
		search(node->left,tosearch);
	}else{
		search(node->right,tosearch);
	}
	
}

int main(){
	BSTNode*Root=NULL;
	int value,ch,tosearch;
	cout<<" 1 for Insert ,2 for search";
	cin>>ch;
	while(ch!=0){
	
	if(ch==1){
		cout<<" what value you want to insert :";
		cin>>value;
		Root =insert(Root,value);
	}else if(ch==2){
		cout<<" what value you want to search :";
		cin>>tosearch;
		search(Root,tosearch);
	}else{
		cout<<"ENTER THE RIGHT CHOICE";
	}
	cout <<"to continue enter your choice again:";
	cin>>ch;
	}
	return 0;
	
}