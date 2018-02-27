#include <stdio.h>
struct node{
	int dat;
	node *l,*r;
}*heap[1001]={NULL},*root;
int lh=0,n=0,tmp=0;
bool operator <(node *a,node *b){
	return a->dat<b->dat;
}
void insert(node *&d){
	int pos=++lh;
	while((pos>>1)>=1&&d<heap[pos>>1]){
		heap[pos]=heap[pos>>1];
		pos>>=1;
	}
	heap[pos]=d;
}
node *delmin(){
	node *ans=heap[1];
	int pos=1,next=pos<<1;
	while(next<=lh){
		next=(next+1)<=lh?(next+1):next;
		if(heap[lh]>heap[next]){
			heap[pos]=heap[next];
			pos=next;
			next=pos<<1;
		}else{
			break;
		}
	}
	heap[pos]=heap[lh];
	delete heap[lh--];
	return ans;
}
void pf(node *&p){
	if(p==NULL){
		return;
	}
	printf("%d ",p->dat);
	pf(p->l);
	pf(p->r);
}
void pm(node *&p){
	if(p==NULL){
		return;
	}
	pf(p->l);
	printf("%d ",p->dat);
	pf(p->r);
}
int main(int argc,char *argv[]){
	node *t,*t1,*t2,*t3;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&tmp);
		t=new node;
		t->l=NULL;
		t->r=NULL;
		t->dat=tmp;
		insert(t);
	}
	//build the huffman tree
	while(lh!=1){
		t1=delmin();
		t2=delmin();
		t3=new node;
		t3->l=t1;
		t3->r=t2;
		t3->dat=t1->dat+t2->dat;
		insert(t3);
	}
	root=delmin();
	pf(root);
	printf("\n");
	pm(root);
	return 0;
}
for(int k=1;k<=n;k++){
	for(int i=1;i<=n;i++){
		for(int j=1)j<=n;j++){
			if(g[i,j]>g[i,k]+g[k,j]){
				g[i,j]=g[i,k]+g[k,j];
			}
		}
	}
}
