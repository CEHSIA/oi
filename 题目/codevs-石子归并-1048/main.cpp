#include <stdio.h>
int f[101][101],sum[101],n;
int min(int a,int b){
	return a<b?a:b;
}
int search(int i,int j){
	if(f[i][j]!=-1)return f[i][j];
	if(i==j){
		f[i][j]=0;
		return 0;
	}
	f[i][j]=1e7;
	for(int k=i;k<j;k++){
		f[i][j]=min(f[i][j],search(i,k)+search(k+1,j)+sum[j]-sum[i-1]);
	}
	return f[i][j];
}
int main(int argc,char *argv[]){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)f[i][j]=-1;
		scanf("%d",&sum[i]);
		sum[i]+=sum[i-1];
	}
	
	printf("%d",search(1,n));
	return 0;
}
