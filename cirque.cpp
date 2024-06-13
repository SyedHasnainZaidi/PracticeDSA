
#include <iostream>
#include <stdlib.h>
using namespace std;
struct node {
   int data;
    node *next;
};
node* front = NULL;
node* rear = NULL;
 node* temp;
void Insert() {
   int val;
   cout<<"Insert the element in queue : "<<endl;
   cin>>val;
   if (rear == NULL) {
      rear = ( node *)malloc(sizeof(node));
      rear->next = rear;
      rear->data = val;
      front = rear;
   } else {
      temp=(node *)malloc(sizeof( node));
      temp->data = val;
      rear->next = temp;
      temp->next = front;
      rear = temp;
   }
}
void Delete() {
   temp = front;
   if (front == NULL) {
      cout<<"Underflow"<<endl;
      return;
   }
   else{
   
   if (temp->next != front) {//ye check kurega ek hi element to nahi he que me
      temp = temp->next;
      cout<<"Element deleted from queue is : "<<front->data<<endl;
      free(front);
      front = temp;
      rear->next=front;
   } else {
      cout<<"Element deleted from queue is : "<<front->data<<endl;
      free(front);
      front = NULL;
      rear = NULL;
   }
   
   }
}
void Display() {
   temp = front;
   if ((front == NULL) && (rear == NULL)) {
      cout<<"Queue is empty"<<endl;
      return;
   }
   cout<<"Queue elements are: ";
   while (temp != rear){
   	cout<<temp->data<<" ";
      temp = temp->next;
   }
   cout<<temp->data<<"-> front";
}
int main() {
   int ch;
   cout<<"1) Insert element to queue"<<endl;
   cout<<"2) Delete element from queue"<<endl;
   cout<<"3) Display all the elements of queue"<<endl;
   cout<<"4) Exit"<<endl;
   do {
      cout<<"Enter your choice : "<<endl;
      cin>>ch;
      switch (ch) {
         case 1: Insert();
         break;
         case 2: Delete();
         break;
         case 3: Display();
         break;
         case 4: cout<<"Exit"<<endl;
         break;
         default: cout<<"Invalid choice"<<endl;
      }
   } while(ch!=4);
   return 0;
}