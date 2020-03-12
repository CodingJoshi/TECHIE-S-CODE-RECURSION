#include<iostream>
using namespace std;
int fac(int n){
	//base case:
	if(n==0)return 1;
	// recursive case:
	return n*fac(n-1);
}
int main(){
	int n;
	cin>>n;
	cout<<fac(n)<<endl;
	return 0;

}
