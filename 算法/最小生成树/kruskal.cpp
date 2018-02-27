#include <stdio.h>
#include <algorithm>
#define MAXN 50005
#define MAXM 200005
using namespace std;
struct edge{
	int s,t;
	int c;
}e[MAXM];
int n,m,cnt,ans;
int pa[MAXN],siz[MAXN];
inline bool operator <(const edge &a,const edge &b){
	return a.c<b.c;
}
inline int find(int a){
	int ta=a;
	while(pa[ta]!=0)ta=pa[ta];
	return ta;
}
inline void uni(int a,int b){
	int ta=find(a);
	int tb=find(b);
	if(siz[ta]<siz[tb]){
		pa[ta]=tb;
		siz[tb]+=siz[ta]+1;
	}else{
		pa[tb]=ta;
		siz[ta]+=siz[tb]+1;
	}
}
inline bool issame(int a,int b){
	return find(a)==find(b);
}
int main(int argc,char *argv[]){
	freopen("test.in","r",stdin);
	scanf("%d%d",&n,&m);
	int cnt=0;
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&e[i].s,&e[i].t,&e[i].c);
	sort(e+1,e+m+1);
	for(int i=1;i<=m;i++){
		if(cnt>=n-1)continue;
		if(!issame(e[i].s,e[i].t)){
			uni(e[i].s,e[i].t);
			cnt++;
			ans+=e[i].c;
		}
	}
	printf("%d\n",ans);
	return 0;
}