#include <iostream>
#include <string>
#define MAX 256
using namespace std;
struct queue{
	btnode *data[MAX];
	int head,tail;
};

struct btnode{
	int data;
	btnode *l,*r;
};

int inque(queue *q,int d){
	q->data[q->tail]=d;
	if(q->tail==MAX){
		q->tail=0;
	}else{
		q->tail=q->tail+1;
	}
	return 1;
}

int outque(queue *q){
	int tmp=q->data[q->head];
	if(q->head==MAX){
		q->head=0;
	}else{
		q->head=q->head+1;
	}
	return tmp;
}

int main(){
	string a="";
	queue *q=new queue;
	
	cout<<endl;
	return 0;
}
