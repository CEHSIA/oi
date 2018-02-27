#include <iostream>
#include <cmath>
#define MAXN 100001
using namespace std;
//--ln(100001)/ln(2)=16
int st[MAXN][17],n,l,r;
inline int max(int a,int b){
	return a>b?a:b;
}
void buildst(){
	int k=floor(log((double)n)/log(2.0));
	for(int j=1;j<=k;j++)
		for(int i=1;i<=n;i++)
			if(i+(1<<(j-1))<=n)
				st[i][j]=max(st[i][j-1],st[i+(1<<(j-1))][j-1]);
}
inline int rmq(int l,int r){
	int k=floor(log((double)(r-l+1))/log(2.0));
	return max(st[l+(1<<k)-1][k],st[r-(1<<k)+1][k]);
}
int main(int argc,char *argv[]){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>st[i][0];
	buildst();
	cin>>l>>r;
	cout<<rmq(l,r);
	return 0;
}