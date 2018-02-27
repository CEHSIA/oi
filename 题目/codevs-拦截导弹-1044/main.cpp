#include <stdio.h>
#define MAX 10001
#define MAXS 10001
int a[MAX],stack[MAXS],stackpos[MAXS],pre[MAX],top=0,n,tmp;
bool isdel[MAX]={0};
inline void push(int data){
	stack[++top]=data;
}
inline void clear(){
	top=0;
}
void fr(int x){
	int l=1,r=n,mid=(l+r)>>1;
	while(l+1!=r){
		if(x<stack[mid])r=mid;
		else l=mid;
		mid=(l+r)>>1;
	}
	stack[r]=x;
}
void lis(){
	for(int i=1;i<=n;i++){
		if(isdel[i])continue;
		if(a[i]>stack[top]){
			push(a[i]);
			stackpos[top]=i;
		}else{
			fr(a[i]);
		}
	}
}
int main(int argc,char *argv[]){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	printf("%d\n",top);
	return 0;
}