#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node{
	int dat,rank;
	int pri;
	node *l,*r;
}*root;

node *llrot(node *&p){
	node *tmp=p->l;
	p->l=tmp->r;
	tmp->r=p;
	return tmp;
}
node *rrrot(node *&p){
	node *tmp=p->r;
	p->r=tmp->l;
	tmp->l=p;
	return tmp;
}

inline void create(node *&p,int dat){
	p=new node;
	p->dat=dat;
	p->pri=rand()%10086;
	p->l=NULL;
	p->r=NULL;
}
void insert(node *&p,int dat){
	if(p==NULL){
		create(p,dat);
		return;
	}
	if(dat<p->dat){
		insert(p->l,dat);
	}else{
		insert(p->r,dat);
	}
	if(p->l!=NULL&&p->pri>p->l->pri){
		p=llrot(p);
	}else if(p->r!=NULL&&p->pri>p->r->pri){
		p=rrrot(p);
	}
}
node *find(node *&p,int dat){
	if(p==NULL)return NULL;
	if(p->dat==dat)return p;
	if(dat<p->dat){
		return find(p->l,dat);
	}else{
		return find(p->r,dat);
	}
}

void preprint(node *&p,int dep){
	if(p==NULL)return;
	for(int i=0;i<dep;i++)printf("|");
	printf("%d-%d\n",p->dat,p->pri);
	preprint(p->l,dep+1);
	preprint(p->r,dep+1);
}

int main(int argc,char *argv[]){
	srand(time(0));
	int n,tmp;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&tmp);
		insert(root,tmp);
	}
	preprint(root,0);
	return 0;
}