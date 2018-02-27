#include <stdio.h>
#define MAXN 10086
//dfs序由线段树维护，重链在dfs序中为一段连续的区间
struct node{
	int sum;
	int l,r;
	node *lc,*rc;
}*root;
int tree[MAXN][MAXM];//邻接矩阵储存树
//tot:为dfs计数
//dfsn:为dfs序
//siz:子树大小(计算自己)
//pa:父结点
int tot,dfsn[MAXN],siz[MAXN],pa[MAXN];
//top:重链起点
int top[MAXN];
void dfsf(int x){
	siz[x]=1;
	for(int u=1;u<=n;u++){
		if(tree[x][u]!=0){
			dfs(u);
			siz[x]+=siz[u];
			pa[u]=x;
		}
	}
}
void dfss(int x){
	tot++;
	int wchild,maxsiz=0;//重边查找,重边优先dfs以形成重链
	for(int u=1;u<=n;u++){
		if(tree[x][u]!=0&&siz[u]>maxsiz){
				maxsiz=siz[u];
				wchild=u;
		}
	}
	dfs(wchild);//进入重边
	for(int u=1;u<=n;u++){//遍历轻边
		if(u!=wchild&&tree[x][u]!=0)dfs(u);
	}
}
int build(node *&p,int l,int r){
	if(p==NULL){
		p=new node;
		p->l=l;
		p->r=r;
		p->lc=NULL;
		p->rc=NULL;
		p->sum=0;
	}
	if(l==r){
		p->sum=dat[l];
		return dat[l];
	}
	int mid=(l+r)>>1;
	return build(p->lc,l,mid)+build(p->rc,mid+1,r);
}
int sum(node *&p,int l,int r){
	if(p->l==l&&p->r==r){
		return p->sum;
	}
	int mid=(p->l+p->r)>>1;
	if(r<mid){
		return sum(p->lc,l,r);
	}else if(l>=mid){
		return sum(p->rc,l,c);
	}else{
		return sum(p->lc,l,mid)+sum(p->rc,mid+1,r);
	}
}

int main(int argc,char *argv[]){
	
	return 0;
}
