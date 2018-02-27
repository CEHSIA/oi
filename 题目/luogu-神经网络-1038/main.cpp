#include <stdio.h>
#define MAXQ 10001
int w[101][101],c[101],u[101],n,p,t1,t2,t3;
bool isused[101],isend;
int a[101],pos;
int front,rear;
int queue[MAXQ];
inline void push(int d){
	queue[rear]=d;
	rear=(rear+1)%MAXQ;
}
inline int pop(){
	int tmp=queue[front];
	front=(front+1)%MAXQ;
	return tmp;
}
inline bool isempty(){
	return front==rear;
}
inline void swap(int &a,int &b){
	a^=b;
	b^=a;
	a^=b;
}
void quicksort(int l,int r){
	if(l>=r)return;
	int k=a[l],i=l,j=r;
	while(i<j){
		while(i<j&&a[j]>k)j--;
		while(i<j&&a[i]<k)i++;
		if(i<j)swap(a[i],a[j]);
	}
	a[i]=k;
	quicksort(l,i-1);
	quicksort(i+1,r);
}
int main(int argc,char *argv[]){
	freopen("test2.in","r",stdin);
	scanf("%d%d",&n,&p);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&c[i],&u[i]);
		if(c[i]!=0){
			push(i);
			isused[i]=true;
		}
	}
	for(int i=1;i<=p;i++){
		scanf("%d%d%d",&t1,&t2,&t3);
		w[t1][t2]=t3;
	}
	while(!isempty()){
		t1=pop();
		c[t1]-=u[t1];
		if(c[t1]<0)c[t1]=0;
		isend=true;
		for(int i=1;i<=n;i++){
			if(w[t1][i]!=0){
				isend=false;
				c[i]+=w[t1][i]*c[t1];
				if(!isused[i]){
					push(i);
					isused[i]=true;
				}
			}
		}
		if(isend&&c[t1]>0)a[pos++]=t1;
	}
	if(pos==0){
		printf("NULL\n");
		return 0;
	}
	quicksort(0,pos-1);
	for(int i=0;i<pos;i++){
		printf("%d %d\n",a[i],c[a[i]]);
	}
	return 0;
}