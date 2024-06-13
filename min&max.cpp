#include <iostream>
using namespace std;

void minHeapify(int *arr, int size, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && arr[left] < arr[smallest])//ye check kurega hum array se bahir to nahi ja rahe 
        smallest = left;

    if (right < size && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i) {//
        int temp = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = temp;
        
        minHeapify(arr, size, smallest);//jis ke child ko swap kia he us ke neche dekhenge ke heap tree he
    }
}

void maxHeapify(int *arr, int size, int i) {
    int  largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && arr[left] > arr[largest])
        largest = left;

    if (right < size && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        
        maxHeapify(arr, size, largest);
    }
}

void buildMinHeap(int *arr, int size) {
    for (int i = size / 2 - 1; i >= 0; i--) {
        minHeapify(arr, size, i);
    }
}

void buildMaxHeap(int *arr, int size) {
    for (int i = size / 2 - 1; i >= 0; i--) {
        maxHeapify(arr, size, i);
    }
}

void printArr(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << ' ';
    }
    cout << endl;
}
void heapsort(int* arr, int size){
	if(size<=0){
		return;
	}
		buildMaxHeap(arr, size);
		int temp= arr[0];
		arr[0]=arr[size-1];
		arr[size-1]=temp;
		
		heapsort(arr,size-1);
	
}

int main() {
    char repeat;
    do {
        string answer;
        cout << "Type 'min' for Min Heap, 'max' for Max Heap";
        cin >> answer;

        int size;
        cout << "Enter the number of elements you want to input: ";
        cin >> size;

        int arr[size];
        for (int i = 0; i < size; i++) {
            cout << "Enter element " << i + 1 << ": ";
            cin >> arr[i];
        }

        if (answer == "min") {
            buildMinHeap(arr, size);
        } else if (answer == "max") {
            buildMaxHeap(arr, size);
        }  else {
            cout << "Invalid input. Please type 'min', 'max', or 'heapsort'." << endl;
            continue;
        }

        cout << "Result: ";
        printArr(arr, size);
        cout<<"Sorted array by using heapsort ";
        heapsort(arr, size);
         printArr(arr, size);
        cout << "Do you want to enter another array? (y/n): ";
        cin >> repeat;

    } while (repeat == 'y' || repeat == 'Y');

    return 0;
}