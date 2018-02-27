#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct treap{
	int data;
	int pri;
	treap *left,*right;
};

treap *root;

treap *llrotation(treap *p){
	treap *tmp=p->left;
	p->left=tmp->right;
	tmp->right=p;
	return tmp;
}
treap *rrrotation(treap *p){
	treap *tmp=p->right;
	p->right=tmp->left;
	tmp->left=p;
	return tmp;
}

void insert(treap *p,int data){
	if(p==NULL){
		p=new treap;
		p->data=data;
		//srand((unsigned)time(NULL));
		p->pri=rand()%100;
		return;
	}
	if(data<p->data){
		insert(p->left,data);
		if((p->pri)<(p->left->pri)){
			p=llrotation(p->left);
		}
	}else{
		insert(p->right,data);
		if((p->pri)<(p->right->pri)){
			p=rrrotation(p->right);
		}
	}
}
treap *find(treap *p,int data){
	if(p==NULL||p->data==data){
		return p;
	}
	if(data<p->data){
		return find(p->left,data);
	}else{
		return find(p->right,data);
	}
}

int main(int argc,char *argv[]){
	int n,tmp;
	for(int i=0;i<n;i++){
		cin>>tmp;
		insert(root,tmp);
	}
	cin>>tmp;
	if(find(root,tmp)!=NULL){
		cout<<"found";
	}else{
		cout<<"nope";
	}
	cout<<endl;
	return 0;
}
