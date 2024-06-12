#include <iostream>
using namespace std;

void selectionsort(int arr[], int size){
	int min;
	for(int i=0;i<=size-2;i++){
		min=i;
		for(int j=i+1;j<=size-1;j++){
			if(arr[j] < arr[min]){
				min=j;	
			}
		}
		if (min != i){
			int t = arr[i];
			arr[i] = arr[min];
			arr[min] = t;
		}
	}
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