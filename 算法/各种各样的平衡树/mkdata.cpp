#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 20
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
int getrand(){
	int ans=0;
	//int len=rand()%MAX+1;
	for(int i=1;i<=MAX;i++){
		ans|=rand()&1;
		ans<<=1;
	}
	return ans;
}
int main(int argc,char *argv[]){
	freopen("treap-data.in","w",stdout);
	int n=1<<(MAX-1);
	put(n);
	putchar('\n');
	for(int i=1;i<=n;i++){
		put(getrand());
		putchar(' ');
	}
	putchar('\n');
	//printf("done");
	fclose(stdout);
	return 0;
}