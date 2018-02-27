#include <iostream>
#include <stdio.h>
using namespace std;
int n;
int a[102][102],f[102][102];
inline int max(int a,int b){
	return a>b?a:b;
}
int main(int argc,char *argv[]){
	freopen("test.in","r",stdin);
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			cin>>a[i][j];
		}
	}
	for(int j=n;j>=1;j--){
		for(int i=j;i>=1;i--){
			f[j][i]=max(f[j+1][i],f[j+1][i+1])+a[j][i];
		}
	}
	cout<<f[1][1]<<endl;
	return 0;
}