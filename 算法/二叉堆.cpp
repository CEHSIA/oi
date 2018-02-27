#include <stdio.h>

int heap[1000];
int lh=0;

void insert(int tmp){
	lh++;
	int pos=lh;
	while((pos>>1)>=1&&(heap[pos>>1]>tmp)){
		heap[pos]=heap[pos>>1];
		pos>>=1;
	}
	heap[pos]=tmp;
}

int main(int argc,char *argv[]){
	int n,tmp;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&tmp);
		insert(tmp);
	}
	for(int i=1;i<=lh;i++){
		printf("%d ",heap[i]);
	}
	printf("\n");
	return 0;
}
