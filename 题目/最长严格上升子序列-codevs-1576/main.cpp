#include <iostream>
using namespace std;
long long last,now;
int main(int argc,char *argv[]){
	long long n,sum=1;
	cin>>n>>last;
	for(int i=1;i<n;i++){
		cin>>now;
		if(now>last)sum++;
		last=now;
	}
	cout<<sum;
	return 0;
}
