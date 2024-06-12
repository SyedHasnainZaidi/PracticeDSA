#include <iostream>
using namespace std;

void bubblesort(int arr[]; int size){
	
	
}

void printarray(int arr[], int size){
	for(int i=0;i<size;i++){
		cout<<arr[i]<<" ";
	}
}

int main(){
	int size;
	cout<<"Enter the size of your array: "; 
	cin>>size;
	
	
	int arr[size]={};
	for(int i=0;i<size;i++){
		cout<<"Enter "<<i+1<<" number: ";
		cin>>arr[i];
}
	selectionsort(arr,size);
	cout<<"Sorted array: ";
	printarray(arr,size);
}