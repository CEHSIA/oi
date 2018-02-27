/*
利用稀疏表维护dfs序列中的区间最值和位置
区间最小值的节点极为lca
编程复杂度大，我选择弃坑
*/
#include <iostream>
#include <cmath>
#include <stdio.h>
#define MAX 10086
using namespace std;
int n,a,b;
int dfsp[MAX][30],first[MAX];
int pos[MAX][30];
int total=1;
int tree[MAX][MAX];
int dfs(int u,int depth){
	dfsp[total][0]=depth;
	pos[i][j]
	first[u]=total++;
	for(int i=1;i<=n;i++){
		if(tree[u][i]!=0){
			dfs(i,depth+1);
			dfsp[total++][0]=depth;
		}
	}
}
inline void build(){
	int k=floor(log((double)n)/log(2.0));
	for(int j=1;j<=k;j++)
		for(int i=1;i<=n;i++)
			if(i+(1<<(j-1))<=n)
				
}
int main(int argc,char *argv[]){
	freopen("test.in","r",stdin);
	cin>>n;
	for(int i=1;i<=n-1;i++){
		cin>>a>>b;
		tree[a][b]=1;
	}
	dfs(1,1);
	total--;
	
	fclose(stdin);
	return 0;
}
