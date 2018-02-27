#include <stdio.h>
#include <string.h>
#include <queue>
#define MAX 2001
#define MAXT 50001
using namespace std;

int n,m,u,v,c,mans;
int map[MAX][MAX];
queue<int> q;
int ans[MAX],dis[MAX],lnk[MAX];
int sor[MAX],cnt;
int sorc[MAX];
bool isinq[MAX];

inline int read(){
	int ans=0;
	char ch=getchar();
	bool flag=false;
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

void spfa(int u,int s){
	memset(isinq,0,sizeof(isinq));
	for(int i=1;i<=n;i++)dis[i]=MAXT;
	dis[u]=s;
	q.push(u);
	isinq[u]=true;
	int t;
	while(!q.empty()){
		t=q.front();
		q.pop();
		isinq[t]=false;
		for(int i=1;i<=n;i++){
			if(!map[t][i])continue;
			if(dis[t]+map[t][i]<dis[i]){
				dis[i]=dis[t]+map[t][i];
				if(dis[i]<ans[i]){
					ans[i]=dis[i];
					lnk[i]=t;
				}
				if(!isinq[i]){
					isinq[i]=true;
					q.push(i);
				}
			}
		}
	}
}

int main(int argc,char *argv[]){
	n=read();
	m=read();
	for(int i=1;i<=m;i++){
		u=read();
		v=read();
		c=read();
		if(u==v){
			sor[cnt]=u;
			sorc[cnt++]=c;
			lnk[u]=u;
		}
		map[u][v]=c;
		map[v][u]=c;
	}
	for(int i=1;i<=n;i++)ans[i]=MAXT;
	for(cnt--;cnt>=0;cnt--){
		spfa(sor[cnt],sorc[cnt]);
	}
	for(int i=1;i<=n;i++)mans+=map[i][lnk[i]];
	printf("%d\n",mans);
	return 0;
}