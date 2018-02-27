/*
  f[v]为v结点子树的子树的最大值
  对每个子树遍历求f[u]
  若满足f[v]+f[u]>f[v]则f[v]=f[v]+f[u]
  简写为f[v]+=f[u]对条件化简不等式得f[u]>0
  答案为树的起点f[x](search(x))
  最优性证明:
  	子树最大可得当前结点最大
	若子树权值小于0则会导致当前结点最大值减小
	无法达到最优解
	所以f[x]最优为子树最优
*/
#include <stdio.h>
#define MAX 16001
struct node{
	int t;
	node *next;
}*tree[MAX],*tmp;
int n,f[MAX],u,v;
bool isvis;
inline int read(){
	int ans=0;
	bool flag=false;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')flag=true;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		ans=ans*10+ch-'0';
		ch=getchar();
	}
	ans=flag?-ans:ans;
	return ans;
}
int dfs(int u){
	if(isvis[u])return f[u];
	isvis=true;
	node *tmp=tree[u];
	while(tmp->next!=NULL){
		tmp=tmp->next;
		
	}
}
int main(int argc,char *argv[]){
	n=read();
	for(int i=1;i<=n;i++){
		f[i]=read();
		tree[i]=new node;
		tree[i]->t=0;
		tree[i]->next=NULL;
	}
	for(int i=1;i<=n-1;i++){
		u=read();
		v=read();
		
		tmp=tree[u];
		while(tmp->next!=NULL)tmp=tmp->next;
		tmp->next=new node;
		tmp=tmp->next;
		tmp->t=v;
		tmp->next=NULL;
		
		tmp=tree[v];
		while(tmp->next!=NULL)tmp=tmp->next;
		tmp->next=new node;
		tmp=tmp->next;
		tmp->t=u;
		tmp->next=NULL;
	}
	dfs
	return 0;
}
