#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
queue<int> q;
int map[101][101],n,m,a,b,c,s,t,v;
int d[101];
bool isinq[101];
int main(int argc,char *argv[]){
	freopen("SFIG-example.dat","r",stdin);
	cin>>n>>m;
	for(int i=1;i<=n;i++)d[i]=1e3;
	for(int i=1;i<=m;i++){
		cin>>a>>b>>c;
		map[a][b]=c;
	}
	cin>>s>>t;
	q.push(s);
	isinq[s]=true;
	d[s]=0;
	while(!q.empty()){
		v=q.front();
		q.pop();
		isinq[v]=false;
		for(int i=1;i<=n;i++){
			if(map[v][i]+d[v]<d[i]){
				d[i]=map[v][i]+d[v];
				if(!isinq[i]){
					isinq[i]=true;
					q.push(i);
				}
			}
		}
	}
	if(d[t]==1e3)cout<<'-1'<<endl;
	else cout<<d[t];
	return 0;
}