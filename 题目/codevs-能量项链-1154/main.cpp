/*状态转移方程
  f[i][j]=max(f[i][j],f[i][k]+f[k+1][j]+v[i]*v[k+1]*v[j+1])
*/
#include <stdio.h>
int f[101][101],v[102];
int n;
int search(int i,int j){
	if(f[i][j]!=0)return f[i][j];
	if(i==j){
		f[i][j]=0;
		return 0;
	}
	int tmp;
	for(int k=i;k<j;k++){
		tmp=f[i][k]+f[k+1][j]+v[i]*v[k+1]*v[j+1];
		if(tmp>f[i][j])f[i][j]=tmp;
	}
	return f[i][j];
}
int main(int argc,char *argv[]){
	freopen("test.in","r",stdin);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&v[i]);
	v[n+1]=v[1];
	printf("%d\n",search(1,n));
	return 0;
}