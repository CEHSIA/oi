#include <stdio.h>
#define MAX 500000
struct node{
	int t;//目标结点
	int c;//边长
	node *next;//下一条边
}*tree[MAX];
int n,m,u,v,c,t;
//结点深度，结点大小，父节点编号，链顶结点编号，当前结点到根结点距离
int dep[MAX],siz[MAX],pa[MAX],top[MAX],len[MAX];
inline int read(){
	int ans=0;
	char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9'){
		ans=ans*10+c-'0';
		c=getchar();
	}
	return ans;
}
inline void put(int x){
	if(x==0){
		putchar('0');
		return;
	}
	char cache[20];
	int tmp=x,pos=0;
	while(tmp!=0){
		cache[pos++]=tmp%10+'0';
		tmp/=10;
	}
	for(pos--;pos>=0;pos--)putchar(cache[pos]);
}
inline void swap(int &a,int &b){
	a^=b;
	b^=a;
	a^=b;
}
void dfsf(int u,int d){
	dep[u]=d;
	siz[u]=0;
	node *tmp=tree[u];
	while(tmp->next!=NULL){
		tmp=tmp->next;
		len[tmp->t]=len[u]+tmp->c;
		dfsf(tmp->t,d+1);
		siz[u]+=siz[tmp->t]+1;
		pa[tmp->t]=u;
	}
}
void dfss(int u){
	if(siz[u]==0)return;
	int maxsiz=-1,maxc;
	node *tmp=tree[u];
	while(tmp->next!=NULL){
		tmp=tmp->next;
		if(siz[tmp->t]>maxsiz){
			maxsiz=siz[tmp->t];
			maxc=tmp->t;
		}
	}
	top[maxc]=top[u];
	dfss(maxc);
	tmp=tree[u];
	while(tmp->next!=NULL){
		tmp=tmp->next;
		if(tmp->t!=maxc){
			top[tmp->t]=tmp->t;
			dfss(tmp->t);
		}
	}
}
int lca(int a,int b){
	int u=a,v=b;
	while(top[u]!=top[v]){
		if(dep[top[u]]>dep[top[v]]){
			u=pa[top[u]];
		}else{
			v=pa[top[v]];
		}
	}
	return dep[u]<dep[v]?u:v;
}
int main(int argc,char *argv[]){
	freopen("test.in","r",stdin);
	n=read();
	for(int i=1;i<=n;i++){
		tree[i]=new node;
		tree[i]->t=0;
		tree[i]->c=0;
		tree[i]->next=NULL;
	}
	node *tmp;
	for(int i=1;i<=n-1;i++){
		u=read();v=read();c=read();
		u++;v++;
		if(u>v)swap(u,v);
		tmp=tree[u];
		while(tmp->next!=NULL)tmp=tmp->next;
		tmp->next=new node;
		tmp=tmp->next;
		tmp->t=v;
		tmp->c=c;
		tmp->next=NULL;
	}
	len[1]=0;
	top[1]=1;
	pa[1]=1;
	dfsf(1,1);
	dfss(1);
	m=read();
	for(int i=1;i<=m;i++){
		u=read();v=read();
		u++;v++;
		t=lca(u,v);
		if(t==1){
			put(len[u]+len[v]);
			putchar('\n');
		}else{
			put(len[u]+len[v]-(len[t]<<1));
			putchar('\n');
		}
	}
	fclose(stdin);
	return 0;
}