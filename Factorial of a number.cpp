#include <iostream>
using namespace std;
	
int main(){
	long long int a;
	
	cout<<"Enter your number: ";
	cin>>a;
	
	for(int i=a;i>1;i--){
		a = a*(i-1);
	}
	cout<<a;
}
