/*
	f[i]=min(f[i-1],f[i-1]-v[i]);
	边界f[i-1]-v[i]<0则f[i]=f[i-1]
	方程错误，状态未完全枚举
*/
#include <iostream>
using namespace std;
int v[100],f[100],n,val;
inline int min(int a,int b){return a<b?a:b;}
int main(int argc,char *argv[]){
	cin>>val>>n;
	for(int i=1;i<=n;i++)cin>>v[i];
	f[0]=val;
	for(int i=1;i<=n;i++)
		f[i]=f[i-1]<v[i]?f[i-1]:min(f[i-1],f[i-1]-v[i]);
	cout<<f[n]<<endl;
	return 0;
}
