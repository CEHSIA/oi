#include <stdio.h>
#include <algorithm>
#define MAX 100005
using namespace std;
int n,m,a,b,c,ans;
int t[MAX];
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

inline void put(int x){
	if(x==0){
		putchar('0');
		return;
	}
	int tmp=x,pos=0;
	char cache[20];
	if(tmp<0){
		tmp=-tmp;
		putchar('-');
	}
	while(tmp!=0){
		cache[pos++]=tmp%10+'0';
		tmp/=10;
	}
	for(pos--;pos>=0;pos--)putchar(cache[pos]);
}
int findpos(int x){
	int l,r;
}
int main(int argc,char *argv[]){
	freopen("test.in","r",stdin);
	n=read();m=read();
	a=read();b=read();c=read();
	for(int j=1;j<=m;j++){
		ans=a*j*j+b*j+c;
		t[i]=ans;
	}
	sort(t+1,t+n+1);
	for(int i=2;i<=n;i++){
		a=read();b=read();c=read();
		findpos()
	}
	for(int i=1;i<=m;i++){
		put(q.top());
		putchar(' ');
		q.pop();
	}
	putchar('\n');
	return 0;
}
