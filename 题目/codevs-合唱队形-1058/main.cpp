#include <iostream>
#include <stdio.h>
#include <cstring>
#define MAX 105
using namespace std;
int a[MAX],n,ans;
int lisf[MAX],ldsf[MAX],maxlis,maxlds;
inline int max(int a,int b){
	return a>b?a:b;
}
int main(int argc,char *argv[]){
	freopen("test.in","r",stdin);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int k=1;k<=n+1;k++){
		memset(lisf,0,sizeof(lisf));
		memset(ldsf,0,sizeof(ldsf));
		maxlis=0;
		for(int i=1;i<=k-1;i++){
			lisf[i]=1;
			for(int j=1;j<i;j++){
				if(a[i]>a[j])
					lisf[i]=max(lisf[i],lisf[j]+1);
				maxlis=max(maxlis,lisf[i]);
			}
					
		}
		maxlds=0;
		for(int i=k+1;i<=n;i++){
			ldsf[i]=1;
			for(int j=k+1;j<i;j++){
				if(a[i]<a[j])
					ldsf[i]=max(ldsf[i],ldsf[j]+1);
				maxlds=max(maxlds,ldsf[i]);
			}
		}
		ans=max(ans,maxlis+maxlds);
	}
	cout<<n-ans<<endl;
	return 0;
}