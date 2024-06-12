#include <iostream>
using namespace std;

int main(){
	int a;
	cout<<"Enter you number: ";
	cin>>a;
	
	if (a==0){
		cout<<"Number is zero";
	}
	else if(a>0){
		cout<<"Number is positive";
	}
	else{
		cout<<"Number is negative";
	}
}