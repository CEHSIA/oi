#include <stdio.h>
#define MAX 10001
typedef long long ll;
int n;
//dis为到1号点的距离前缀和，O(1)时间内求出s到t的距离
//此处为边前缀和，i~j距离为dis[j-1]-dis[i-1]
ll dis[MAX],be[MAX],d;
ll sumd,minans,ans;
inline ll min(ll a,ll b){
	return a<b?a:b;
}
int main(int argc,char *argv[]){
	freopen("test.in","r",stdin);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld%lld",&be[i],&dis[i]);
		dis[i]+=dis[i-1];
	}
	minans=1e8;
	for(int i=1;i<=n;i++){
		ans=0;
		for(int j=1;j<=n;j++){
			if(i==j)continue;
			d=((i<j)?(dis[j-1]-dis[i-1]):(dis[i-1]-dis[j-1]));
			d=min(d,dis[n]-d);
			ans+=d*be[j];
		}
		minans=min(minans,ans);
	}
	printf("%lld\n",minans);
	return 0;
}
