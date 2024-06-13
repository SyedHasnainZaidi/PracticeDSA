#include <iostream>
using namespace std;
// class          33333                          333333333                 33333333333333               33333333        
//void swap(int *a ,int *b){
//	int t =*a;
//	*a=*b;
//	*b=t;
//	
//}
void arr_sum(int *arr, int step, int size) {
    for (int i = 0; i < size; i++) {
        *arr += step;
        arr +=i;
    }
}

void printarr(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << *arr << " ";
        arr +=i; 
    
    }
}



int main() {
	int arr[10] = {1, 23, 34, 54, 65, 68, 78, 74, 77, 56};

    arr_sum(arr, 5, 10);
    printarr(arr, 10);

    return 0;
	// int a,*ptr;
// a=56;
// int b=46;
// cout<<&a<<"  \n";
//ptr=&a;
//cout<<*ptr;
//*ptr=b;
//cout<<*ptr;
//cout<< a;
	
	
//	int x=19 ,y=25,*ptr;
//	swap(&x,&y);//& apko var ka memory address nikal k deta ha or * apko us memory address ki value nikal k deta ha 
//	
//	cout<<x<<"\n"<<y;
	
	
	
	
	
	

    return 0;
}
