#include "heap.h"

int length(heap *&p){
	return p->data[0];
}
int getmin(heap *&p){
	return p->data[1];
}
void insert(heap *&p,int d){
	p->data[0]+=1;
	p->data[p->data[0]]=d;
	int pos=p->data[0];
	while((pos>>1)>1||(p->data[pos>>1]>d)){
		p->data[pos]=p->data[pos>>1];
		p>>=1;
	}
	p->data[pos]=d;
}
