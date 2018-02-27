#include <iostream>
using namespace std;
int sum[1000];
int n,l,r,k;
int main(int argc,char *argv[]){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>sum[i];
		sum[i]+=sum[i-1];
	}
	for(int i=1;i<=k;i++){
		cin>>l>>r;
		cout<<((l<r)?(sum[r]-sum[l-1]):(sum[l]-sum[r-1]))<<endl;
	}
	return 0;
}