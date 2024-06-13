#include <iostream>
#include <stdlib.h>
using namespace std;

struct BSTNode{
	int data;
	BSTNode*left;
	BSTNode*right;
};

BSTNode*insert(BSTNode*node,int insertvalue){
	if(node == NULL){
		node = (BSTNode*)malloc(sizeof(BSTNode));
		node->data = insertvalue;
		node->left = node->right = NULL;
		return node;
	}
	if(insertvalue<node->data){
		node->left = insert(node->left,insertvalue);
	}
	else{
		node->right = insert(node->right,insertvalue);
	}
	return node;
}
void search(BSTNode*node,int searchvalue){
	if(node==NULL){
		cout<<"Value not found";
		return ;
	}
	if(searchvalue==node->data){
		cout<<"Value Found";
		return ;		
	}
	if(searchvalue<node->data){
		search(node->left,searchvalue);
	}
	else{
		search(node->right,searchvalue);
	}
		
	}  
	
void Inordertrav(BSTNode*node){
	if(node!=NULL){
		Inordertrav(node->left);
		cout<<node->data;
		Inordertrav(node->right);
	}
}

void Preordertrav(BSTNode*node){
	if(node!=NULL){
		cout<<node->data;
		Inordertrav(node->left);
		Inordertrav(node->right);
	}
}

void Postordertrav(BSTNode*node){
	if(node!=NULL){
		Inordertrav(node->left);
		Inordertrav(node->right);
		cout<<node->data;
	}
}

BSTNode*FindMin(BSTNode*node){
	if(node == NULL){
		cout<<"NOT EXIST";
		return 0;
	}
	while(node->left != NULL){
		node = node->left;
	}
	cout<<node->data;
	return node;
}

BSTNode*FindMax(BSTNode*node){
	if(node == NULL){
		cout<<"NOT EXIST";
		return 0;
	}
	while(node->right != NULL){
		node = node->right;
	}
	cout<<node->data;
	return node;
}

BSTNode*deleteBST(BSTNode*node,int toDel){
	if(node == NULL){
		cout<<"DOES NOT EXIST";
		return node;
	}
	if(toDel < node->data){
		node->left = deleteBST(node->left,toDel);
	}
	else if(toDel > node->data){
		node->right = deleteBST(node->right,toDel);
	}
	else{
		if(node->left == NULL){
			BSTNode*temp = node->right;
			free(node);
			return temp;
		}
		else if(node->right == NULL){
			BSTNode*temp = node->left;
			free(node);
			return temp;
		}
		BSTNode*temp = FindMin(node->right);
		node->data = temp->data;
		node->right = deleteBST(node->right,temp->data);
		return node;
	}
return node;	
}
void Display(BSTNode* Root) {
    if (Root == NULL) {
        return;
    }
    
    cout << "Value: " << Root->data ;
    
    if (Root->left != NULL) {
        Display(Root->left);
    }
    
    if (Root->right != NULL) {
        Display(Root->right);
    }
}

                                                                
	
int main(){
	BSTNode*Root = NULL;
	int insertvalue,searchvalue,ch,toDel;
	
	
	while(true){
		cout<<"\n1. INSERT\n2. SEARCH\n3. INORDER TRAVERSE\n4. PREORDER TRAVERSE\n5. POST ORDER TRAVERSE\n6. FIND MINIMUM VALUE\n7. FIND MAXIMUM VALUE\n8. DELETE\n9. Display\n0. End \n";
		cin>>ch;
		if(ch == 1){
			cout<<"What value do you want to insert: ";
			cin>>insertvalue;
			Root = insert(Root,insertvalue);
		}
		else if(ch == 2){
			cout<<"What value do you want to search: ";
			cin>>searchvalue;
			search(Root,searchvalue);
		}
		else if(ch == 3){
			cout<<"In-orderly Traversed Tree: ";
			Inordertrav(Root);
		}
		else if(ch == 4){
			cout<<"Pre-orderly Traversed Tree: ";
			Preordertrav(Root);
		}
		else if(ch == 5){
			cout<<"Post-orderly Traversed Tree: ";
			Postordertrav(Root);
		}
		else if(ch == 6){
			cout<<"Minimum Value is: ";
			FindMin(Root);
		}
		else if(ch == 7){
			cout<<"Maximum Value is: ";
			FindMax(Root);
		}
		else if(ch == 8){
			cout<<"What value do you want to delete: ";
			cin>>toDel;
			Root = deleteBST(Root,toDel);
		}else if(ch == 9){
			Display(Root);
		}else{
			return false;
		}
	}
	return 0;
}