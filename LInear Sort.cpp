#include <iostream>
using namespace std;

int main(){
	
	int num[]= {2,6,98,66,57};
	
	int x;
	cin >> x;
	
	bool flag = 0;
	
	for (int i=0; i < 5; i++){
		if (num[i] == x){
			cout<<"Number found";
			flag = 1;	
			break;	
		}
	}
		if (flag == 0){
			cout<<"Number not found";
		}
	}