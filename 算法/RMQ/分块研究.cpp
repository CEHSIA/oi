#include <stdio.h>
#include <math.h>
#define MAX 100000
int block,num,n,m;
int a[MAX],belong[MAX],bl[MAX],br[MAX],bsum[MAX];
void build(){
	block=sqrt(n);
	num=n/block;
	if(n%block)num++;
	for(int i=1;i<=num;i++){
		bl[i]=(i-1)*block+1;
		br[i]=bl[i]+block-1;
	}
	br[num]=n;
	for(int i=1;i<=num;i++)
		for(int j=bl[i];j<=br[i];j++){
			belong[j]=i;
			bsum[i]+=a[j];
		}
}
inline void editp(int x,int dat){
	a[x]+=dat;
	bsum[belong[x]]+=dat;
}
int getsum(int l,int r){
	int ans=0;
	if(belong[l]==belong[r]){
		for(int i=l;i<=r;i++)
			ans+=a[i];
		return ans;
	}
	for(int i=l;i<=br[belong[l]];i++)
		ans+=a[i];
	for(int i=bl[belong[r]];i<=r;i++)
		ans+=a[i];
	for(int i=belong[l]+1;i<=belong[r]-1;i++)
		ans+=bsum[i];
	return ans;
}
int main(int argc,char *argv[]){
	//freopen("lt-test.in","r",stdin);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	build();
	scanf("%d",&m);
	int o,p,q;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&o,&p,&q);
		if(o==1){
			editp(p,q);
		}else{
			printf("%d\n",getsum(p,q));
		}
	}
	return 0;
}
