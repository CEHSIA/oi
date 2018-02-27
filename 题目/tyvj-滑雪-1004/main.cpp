/*
	状态转移方程:
	f[i][j]=max(f[i][j]，f[i+dx][j+dy]+1);
	{1<=i+dx<=n，1<=j+dy<=m}
	{map[i][j]>map[i+dx][j+dy]}
*/
#include <stdio.h>
int n,m,maxn=0,tmp;
int map[101][101],f[101][101];
const int dx[4]={1,-1,0,0};
const int dy[4]={0,0,1,-1};
inline int max(int a,int b){
	return a>b?a:b;
}
int search(int i,int j){
	if(f[i][j]!=-1)return f[i][j];
	int x,y;
	f[i][j]=0;
	for(int k=0;k<4;k++){
		x=i+dx[k];
		y=j+dy[k];
		if(x>=1&&x<=n&&y>=1&&y<=m&&map[i][j]>map[x][y]){
			f[i][j]=max(f[i][j],search(x,y)+1);
		}
	}
	return f[i][j];
}
int main(int argc,char *argv[]) {
	freopen("test.in","r",stdin);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			scanf("%d",&map[i][j]);
			f[i][j]=-1;
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			tmp=search(i,j);
			if(tmp>maxn)maxn=tmp;
		}
	printf("%d\n",maxn+1);
	return 0;
}
