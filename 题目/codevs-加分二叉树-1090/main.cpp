/*状态转移方程
  f[i][j]=max(f[i][j],f[i][k-1]*f[k+1]+val[k])
  i<=k<=j
  ps:第一次自己写出来的>_<(it's true,i ACed it) 
  pss:题意-->子树为空时不考虑
  psss:记忆化搜索函数内对k的遍历应考虑k+1<=j，k-1>=i
  采用后驱模式储存树，即储存节点的根
  suf[i][j]表示i~j的区间的根
  f[i][j]初始化为0*/
#include <stdio.h>
int f[31][31],val[31],suf[31][31];
int tmp,n;
void preprint(int l,int r){
	if(suf[l][r]==0)return;
	printf("%d ",suf[l][r]);
	preprint(l,suf[l][r]-1);
	preprint(suf[l][r]+1,r);
}
int search(int i,int j){
	if(f[i][j]!=0)return f[i][j];
	int l,r,tmp;
	for(int k=i;k<=j;k++){
		if(k==i){
			l=1;
			r=search(k+1,j);
		}else if(k==j){
			l=search(i,k-1);
			r=1;
		}else{
			l=search(i,k-1);
			r=search(k+1,j);
		}
		tmp=l*r+val[k];
		if(tmp>f[i][j]){
			f[i][j]=tmp;
			suf[i][j]=k;
		}
	}
	return f[i][j];
}
int main(int argc,char *argv[]){
	freopen("test.in","r",stdin);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&val[i]);
	printf("%d\n",search(1,n));
	preprint(1,n);
	return 0;
}
