#include <stdio.h>
#define DEBUG
int a[10000]={0},n,tmp;
inline int lowbit(int x){
	return x&(-x);
}
void update(int x,int num){
	for(int i=x;i<=n;i+=lowbit(i))a[i]+=num;
}
int sum(int x){
	int s=0;
	for(int i=x;i>0;i-=lowbit(i))s+=a[i];
	return s;
}
int main(int argc,char *argv[]){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&tmp);
		update(i,tmp);
	}
	return 0;
}

