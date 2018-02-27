#include <stdio.h>
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
	int n=read();
	put(n);
	return 0;
}