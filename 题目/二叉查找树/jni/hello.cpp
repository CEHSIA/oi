#include <iostream>

using namespace std;

struct tree{
	int data;
	tree *l;
	tree *r;
};

tree *create(){
	tree *t=new tree;
	return t;
}

int del(tree *t){
	
}

tree *insert(tree *t,int elem){
	if(t==NULL){
		t=new tree;
		t->data=elem;
		return t;
	}else if(elem<(t->data)){
		return insert(t->l,elem);
	}else if(elem>(t->data)){
		return insert(t->r,elem);
	}else{
		return NULL;
	}
}

tree *find(tree *t,int elem){
	if(t==NULL){
		return NULL;
	}else if(elem==(t->data)){
		return t;
	}else if(elem<(t->data)){
		return find(t->left,elem);
	}else if(elem>(t->data)){
		return find(t->right,elem);
	}
}

int main(){
	
	return 0;
}
