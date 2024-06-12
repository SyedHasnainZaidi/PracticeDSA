#include <iostream>
using namespace std;

void SelectionSort(int arr[], int n){
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(arr[i]>arr[j]){
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

void BubbleSort(int arr[], int n){
	int counter = 1;
	while(counter<n-1){
		for(int i=0;i<n-1;i++){
			if(arr[i]>arr[i+1]){
				int temp = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = temp;
			}
		}
		counter ++;
	}
}

void InsertionSort(int arr[], int n){
	for(int i=1;i<n;i++){
		int current = arr[i];
		int j = i-1;
		while(arr[j]>current){
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = current;
	}
}

void PrintArray(int arr[], int n){
	for(int i=0; i<n;i++){
		cout<<arr[i]<<" ";
	}
}

int main(){
	int n;
	cout<<"Enter size of your array: ";
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	InsertionSort(arr,n);
	PrintArray(arr,n);	
}