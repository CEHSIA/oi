#include <iostream>
using namespace std;
int main(){
	float m,n,c;
	cin>>m>>n;
	if(m<n){
		c=m;
		m=n;
		n=c;
	}
	if(m==n)
		cout<<"yes"<<endl;
	else
		cout<<"no"<<endl;
	if((m-n)<=1e-8){
		cout<<"yes"<<endl;
	}else{
		cout<<"no"<<endl;
	}
	return 0;
}
