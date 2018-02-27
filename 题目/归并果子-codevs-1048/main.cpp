#include <stdio.h>
#define lh heap[0]
#define DEBUG
int heap[10001]={0};
long long n,t,tmp,t1,t2;
void ins(int x){
	int pos=++lh;
	while((pos>>1)>=1&&x<heap[pos>>1]){
		heap[pos]=heap[pos>>1];
		pos>>=1;
	}
	heap[pos]=x;
}
int delmin(){
	int ans=heap[1],last=heap[lh--];
	int pos=1,next=pos<<1;
	while(next<=lh){
		if(next+1<=lh&&heap[next+1]<heap[next]){
			next++;
		}
		if(last>heap[next]){
			heap[pos]=heap[next];
		}else{
			break;
		}
		pos=next;
		next=pos<<1;
	}
	heap[pos]=last;
	return ans;
}
int main(int argc,char *argv[]){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&tmp);
		ins(tmp);
	}
	tmp=0;
	t=0;
	while(lh!=1){
		t1=delmin();
		t2=delmin();
		t+=t1+t2;
		tmp=t1+t2;
		ins(tmp);
	}
	printf("%ld\n",t);
	return 0;
}
