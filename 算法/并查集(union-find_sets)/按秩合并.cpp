#include <iostream>
#include <cstring>
#define MAX 123456
using namespace std;

int n;
int dat[MAX],pre[MAX],rank[MAX];

inline int find(int x){
	int tmp=x;
	while(pre[tmp]!=0)tmp=pre[tmp];
	return tmp;
}
inline void uni(int x,int y){
	int tmpx=find(x),tmpy=find(y);
	if(tmpx==tmpy)return;
	if(rank[tmpx]>rank[tmpy]){
		pre[tmpy]=tmpx;
	}else{
		pre[tmpx]=tmpy;
		if(rank[tmpx]==rank[tmpy])rank[tmpy]++;
	}
}

int main(int argc,char *argv[]){
	memset(pre,0,sizeof(pre));
	cin>>n;
	int ope
	int m,n;
	for(int i=1;i<=n;i++){
		cin>>ope;
		cin>>m>>n;
		if()
	}
	return 0;
}
