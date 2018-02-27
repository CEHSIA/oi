#include <stdio.h>
//#define DEBUG
int n,m,x[20001],k[20001],tmp[20001]={0};
bool isused[11];
int a[11],b[11];
void dfs(int pos,int index){
	isused[pos]=true;
	b[index]=a[pos];
	if(index==n){
		int t=0;
		for(int i=1;i<=n;i++){
			t=10*t+b[i];
		}
		for(int i=1;i<=m;i++){
			if(tmp[i]==0){
				tmp[i]=(t+x[i])%k[i]==0?t:0;
			}
		}
		isused[pos]=false;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!isused[i]){
			dfs(i,index+1);
		}
	}
	isused[pos]=false;
}
int main(int argc,char *argv[]){
	/*#ifdef DEBUG
		fre~("example.in","r",stdin);
	#endif*/
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		isused[i]=false;
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n-1;i++){
		for(int j=i+1;j<=n;j++){
			if(a[j]<a[i]){
				a[i]^=a[j];
				a[j]^=a[i];
				a[i]^=a[j];
			}
		}
	}
	for(int i=1;i<=m;i++){
		scanf("%d%d",&x[i],&k[i]);
	}
	dfs(0,0);
	for(int i=1;i<=m;i++){
		if(tmp[i]!=0){
			printf("%d\n",tmp[i]);
		}else{
			printf("None\n");
		}
	}
	return 0;
}
