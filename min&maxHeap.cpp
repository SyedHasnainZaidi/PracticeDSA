#include <iostream>
using namespace std;


void minHeapify(int *arr, int i) {
	int parent = (i - 1) / 2;
	if (arr[parent] > arr[i]) {
		int temp = arr[i];
		arr[i] = arr[parent];
		arr[parent] = temp;
		minHeapify(arr, parent);
	}
}

void maxHeapify(int *arr, int i) {
	int parent = (i - 1) / 2;
	if (arr[parent] < arr[i]) {
		int temp = arr[i];
		arr[i] = arr[parent];
		arr[parent] = temp;	
		maxHeapify(arr, parent);
	}
}

void minHeap(int *arr, int size) {
	for (int i = 1; i < size; i++) {
		minHeapify(arr, i);
	}
}

void maxHeap(int *arr, int size) {
	for (int i = 0; i < size; i++) {
		maxHeapify(arr, i);
	}
}

void printArr(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << ' ';
	}
	cout << endl;
}

int main() {
	string answer;
	cout << "Type 'min' for Min Heap or 'max' for Max Heap: ";
	cin >> answer;
	
	int size;
	cout << "Enter the number of elements you want to input: ";
	cin >> size;
	
	int arr[size];
	
	for (int i = 0; i < size; i++) {
		cout << "Enter element " << i << ": ";
		cin >> arr[i];
	}
	
	if (answer == "min") {
		minHeap(arr, size);
		printArr(arr, size);
	} else {
		maxHeap(arr, size);
		printArr(arr, size);
	}
	
	return 0;
}