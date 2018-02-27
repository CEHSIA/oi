#include <stdio.h>
inline int read(){
	int ans=0;
	char c=getchar();
	bool flag=false;
	while(c<'0'||c>'9'){
		if(c=='-')flag=true;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		ans=ans*10+c-'0';
		c=getchar();
	}
	ans=flag?-ans:ans;
	return ans;
}
inline void put(int x){
	if(x==0){
		putchar('0');
		return;
	}
	int tmp=x;
	if(tmp<0){
		putchar('-');
		tmp=-tmp;
	}
	char cache[20];
	int pos=0;
	while(tmp!=0){
		cache[pos++]=tmp%10+'0';
		tmp/=10;
	}
	for(pos--;pos>=0;pos--)putchar(cache[pos]);
}
int t[120]={0};
int f(int x){
	if(x>=101)return x-10;
	if(t[x]!=0)return t[x];
	t[x]=f(f(x+11));
	return t[x];
}
int main(int argc,char *argv[]){
	int tmp=read();
	while(tmp!=0){
		put(f(tmp));
		putchar('\n');
		tmp=read();
	}
	return 0;
}