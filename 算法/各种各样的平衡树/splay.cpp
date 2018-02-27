#include <iostream>
#include <stdio.h>
using namespace std;

struct node{
	int data;
	node *l,*r,*pa;
}*root;
//root->pa==root;

void lr(node *&p){
	
}
void rr(node *&p){
	node *pr=p->r;
	
	node *pparent=p->pa;
	p->pa=pparent->pa;
	if(p->pa->l==pparent){
		p->pa->l=p;
	}else if(p->pa->r==pparent){
		p->pa->r=p;
	}
	pparent->pa=p;
	pr->pa=pparent;
	
	pparent->l=pr;
	p->r=pparent;
}
inline void create( node *&p,
					int dat,
					node *left,
					node *right,
					node *parent){
	p=new node;
	p->dat=dat;
	
	p->l=left;
	p->r=right;
	p->pa=parent;
}

void splay(node *&p){
	
}
 
int main(int argc,char *argv[]){
	return 0;
}
