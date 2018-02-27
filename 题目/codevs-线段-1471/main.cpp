#include <iostream>
#include <stdio.h>
#define MAX 50005
using namespace std;
int n,m,a,b,tmp;
int sum[MAX];
inline void swap(int &a,int &b){
	a^=b;
	b^=a;
	a^=b;
}
int main(int argc,char *argv[]){
	freopen("test.in","r",stdin);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		if(a>b)swap(a,b);
		sum[a]++;
		sum[b+1]--;
	}
	for(int i=2;i<MAX-1;i++)
		sum[i]+=sum[i-1];
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>tmp;
		cout<<sum[tmp]+1<<endl;
	}
	return 0;
}