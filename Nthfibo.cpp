#include<iostream>
using namespace std;
int Fibo(int n){
	//Base Case:
	if(n<=1)return n;
	///Recursive Caseb
	return Fibo(n-1)+Fibo(n-2);
}
int main(){
	#ifndef Techies
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
		int n;
		cin>>n;
		cout<<Fibo(n);
	return 0;
}
