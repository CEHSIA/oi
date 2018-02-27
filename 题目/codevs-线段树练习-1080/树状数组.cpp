#include <stdio.h>
int a[100001],n,tmp,m,ctrl,p,q;
inline int lowbit(int x){
	return x&(-x);
}
void update(int pos,int num){
	for(int i=pos;i<=n;i+=lowbit(i))a[i]+=num;
}
int sum(int pos){
	int s=0;
	for(int i=pos;i>0;i-=lowbit(i))s+=a[i];
	return s;
}
int main(int argc,char *argv[]){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&tmp);
		update(i,tmp);
	}
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%d",&ctrl);
		if(ctrl==1){
			scanf("%d%d",&p,&q);
			update(p,q);
		}else{
			scanf("%d%d",&p,&q);
			printf("%d\n",sum(q)-sum(p-1));
		}
	}
	return 0;
}
