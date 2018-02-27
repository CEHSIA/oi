#include <stdio.h>
#include <math.h>
#define DEBUG
#define MAXN 5000001

bool isprime[MAXN];
int n,k,a[21],count,used;

void prime(){
	for(int i=0;i<MAXN;i++)isprime[i]=true;
	for(int i=2;i<=sqrt(MAXN);i++){
		if(!isprime[i])continue;
		for(int j=i<<1;j<MAXN;j+=i)isprime[j]=false;
	}
}
void allpl(){
	for(used=1;used<=MAXZ;used++){
		
	}
}
int main(int argc,char *argv[]){
	freopen("test.in","r",stdin);
	scanf("%d%d",&n,&k);
	MAXZ=1<<n;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	prime();
	allpl();
	printf("%d\n",count);
	return 0;
}
