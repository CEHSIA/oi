#include <iostream>
#include <stdio.h>
#define MAX 10086
using namespace std;
int tree[MAX][MAX],dep[MAX],siz[MAX],top[MAX],pa[MAX];
int n,k,u,v;
inline void trace(int a[],int l,int r){
	for(int i=l;i<=r;i++)cout<<a[i]<<' ';
	cout<<endl;
}
void dfsf(int u,int d){
	dep[u]=d;
	for(int i=1;i<=n;i++){
		if(tree[u][i]==0)continue;
		dfsf(i,d+1);
		siz[u]+=siz[i]+1;
		pa[i]=u;
	}
}
void dfss(int u){
	if(siz[u]==0)return;
	int maxsiz=-100,maxc=u;
	for(int i=1;i<=n;i++){
		if(tree[u][i]==0)continue;
		if(siz[i]>maxsiz){
			maxsiz=siz[i];
			maxc=i;
		}
	}
	top[maxc]=top[u];
	dfss(maxc);
	for(int i=1;i<=n;i++){
		if(tree[u][i]==0||i==maxc)continue;
		top[i]=i;
		dfss(i);
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
	cin>>n;
	pa[1]=1;
	top[1]=1;
	for(int i=1;i<=n-1;i++){
		cin>>u>>v;
		tree[u][v]=1;
	}
	dfsf(1,1);
	dfss(1);
	//trace(dep,1,n);
	//trace(siz,1,n);
	//trace(top,1,n);
	//trace(pa,1,n);
	cin>>k;
	for(int i=1;i<=k;i++){
		cin>>u>>v;
		cout<<lca(u,v)<<endl;
	}
	return 0;
}
