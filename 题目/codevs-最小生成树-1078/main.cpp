#include <stdio.h>
#include <limits.h>
struct ve{
	int dis;
	int v;
};
int lh=0;
ve *heap[1001];
int g[1001][1001],tmp,min=INT_MAX;
bool operator <(ve *a,ve *b){
	if(a->dis<b->dis){
		return true;
	}else{
		return false;
	}
}
void insert(ve *x){
	int pos=++lh;
	while((pos>>1)>=1||x<heap[pos>>1]){
		heap[pos]=heap[pos>>1];
		pos>>=1;
	}
	heap[pos]=x;
}
void delmin(){
	ve *mine=heap[1],*last=heap[lh--];
	int i,child;
	for(i=1;(i<<1)<=lh;i=child){
		child=i<<1;
		if(child!=lh&&heap[child+1]<heap[child]){
			child++;
		}
		if(heap[child]<last){
			heap[i]=heap[child]
		}else{
			break;
		}
	}
	heap[i]=last;
}
int prim(int s){
	int length=0;
	int ss=s;
	bool isv[1001]={0};
	isv[ss]=true;
	for(int i=1;i<=n-1;i++){
		for(int j=1;j<=n;j++){
			
		}
	}
}
int main(int argc,char *argv[]){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&tmp);
			g[i][j]=tmp;
		}
	}
	for(int i=1;i<=n;i++){
		tmp=prim(i);
		min=tmp<min?tmp:min;
	}
	printf("%d\n",min);
	return 0;
}
