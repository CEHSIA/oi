#include <iostream>
using namespace std;
int a[5001],n,f[5001],maxf;
int main(int argc,char *argv[]){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		f[i]=1;
		for(int j=i-1;j>=0;j--){
			if(a[j]<a[i]&&f[j]>=f[i]){
				f[i]=f[j]+1;
			}
		}
		maxf=f[i]>maxf?f[i]:maxf;
	}
	cout<<maxf<<endl;
	return 0;
}

