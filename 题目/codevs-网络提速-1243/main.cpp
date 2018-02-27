#include <iostream>
#include <queue>
using namespace std;
double path[51];
bool isvisited[51];
int dis[51]={0};
int map[51][51];
int n=0;
struct node{
	int v;
	int edge;
}tmp,tmp2;
bool operator <(const node &a,const node &b){
	return a.edge>b.edge;
}
priority_queue<node> q;
int main(int argc,char *argv[]){
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>map[i][j];
		}
		dis[i]=1<<16;
	}
	tmp.v=1;
	tmp.edge=0;
	q.push(tmp);
	while(!q.empty()){
		tmp=q.top();
		q.pop();
		isvisited[tmp.v]=true;
		for(int i=1;i<=n;i++){
			if(!isvisited[tmp.v]){
				tmp2.v=i;
				tmp2.edge=map[tmp.v][i];
			}
		}
	}
	return 0;
}
