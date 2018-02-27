/*
差分前缀和+二分答案
(not ACed) ACed script in luogu
*/
#include <stdio.h>
#include <string.h>

const int MAX=1e6+1;

int n,s[MAX],t[MAX],r[MAX];
int l,r,mid;

inline int read(){
	int ans=0;
	bool flag=false;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')flag=true;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		ans=ans*10+ch-'0';
		ch=getchar();
	}
	ans=flag?-ans:ans;
	return ans;
}
int check(int x){
	int sum[MAX];
	memset(sum,0,sizeof(sum));
	for(int i=1;i<=x;i++){
		sum[s[i]]+=d[i];
		sum[t[i]+1]-=d[i];
	}
	for(int i=1;i<=n;i++){
		if(r[i]-sum<=0){
			return false;
		}
	}
	return true;
}

int main(int argc,char *argv[]){
	freopen("test.in","r",stdin);
	n=read();m=read();
	for(int i=1;i<=n;i++)r[i]=read();
	for(int i=1;i<=m;i++){
		d[i]=read();
		s[i]=read();
		t[i]=read();
	}
	r=n;l=1;
	while(l<r){
		mid=(l+r)>>1;
		if(!check(mid))r=mid;
		else l=mid;
	}
	printf("%d\n",l);
	return 0;
}
