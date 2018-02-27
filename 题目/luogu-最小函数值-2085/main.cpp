#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;
int n,m,a,b,c,ans;
priority_queue<int,vector<int>,greater<int> > q;
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
int main(int argc,char *argv[]){
	freopen("test.in","r",stdin);
	n=read();m=read();
	for(int i=1;i<=n;i++){
		a=read();b=read();c=read();
		for(int j=1;j<=m;j++){
			ans=a*j*j+b*j+c;
			q.push(ans);
		}
	}
	for(int i=1;i<=m;i++){
		put(q.top());
		putchar(' ');
		q.pop();
	}
	putchar('\n');
	return 0;
}