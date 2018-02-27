#include <iostream>
#include <stdio.h>
#define MAX 28
using namespace std;
int map[MAX][MAX];
int n,r,c,x,y;
int main(int argc,char *argv[]){
	freopen("test.in","r",stdin);
	cin>>r>>c>>n;
	for(int i=1;i<=n;i++){
		cin>>x>>y;
		map[x][y]=-1;
	}
	map[1][1]=1;
	for(int i=1;i<=r;i++){
		for(int j=1;j<=c;j++){
			if(map[i][j]==-1)continue;
			if(map[i][j-1]!=-1)map[i][j]+=map[i][j-1];
			if(map[i-1][j]!=-1)map[i][j]+=map[i-1][j];
		}
	}
	cout<<map[r][c]<<endl;
	fclose(stdin);
	return 0;
}