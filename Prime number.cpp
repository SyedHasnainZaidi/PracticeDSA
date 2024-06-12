#include<iostream>
using namespace std;

int main(){
	int a;
	cout<<"Enter your number: ";
	cin>>a;
	
	for (int i=2;i<=a;i++){
		if(a%i==0){
			cout<<"It is a prime number";
		}
		else{
			cout<<"It is not a prime number";
		}
}
}
		
		
		