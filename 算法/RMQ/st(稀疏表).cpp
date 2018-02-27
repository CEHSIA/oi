/*
	dp[i][j]=max(dp[i][j-1],dp[i+2^j-1][j-1]);
	理解:
	i表示开始的位置
	j表示往后数2^j个数的最大值
	 a b c d e f g h i j k l n=12 a~l表示12个数字
	|-|-|-|-|-|-|-|-|-|-|-|-|  j=0时i管辖区间
	|---|---|---|---|---|---|
	  |---|---|---|---|---|--  j=1时i管辖区间
	|-------|-------|-------|
	  |-------|-------|------
	    |-------|-------|----
		  |-------|-------|--  j=2时i管辖区间
	|---------------|--------
	  |---------------|------
	    |---------------|----
		  |---------------|--
		    |---------------|
			  |--------------
			    |------------
				  |----------
				    |--------
					  |------
					    |----
						  |--  j=3时i管辖区间
	可以看出j每增加1，管辖区间由两个j-1区间合并而成
	
	还有另一种dp方程
	dp[i][j]=max(dp[i][j-1],dp[i+2^(j-1)][j-1])
	RMQ(l,r)时
	  找到最大的k使得l+2^k<r+1
	  移项得2^k<r-l+1
	  ∴k=[ln(r-l+1)/ln(2)]向下取整
	  求得k之后有
	  RMQ(l,r)
	    =max(st[l][l+2^k-1],st[r-2^k+1][r])
*/
#include <iostream>
#include <cmath>
#define MAX 10086
using namespace std;

int a[MAX],n;
int st[MAX][MAX],pos[MAX][MAX];
int q,l,r;

int main(int argc,char *argv[]){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		st[i][0]=a[i];
		pos[i][0]=i;
	}
	//建表，O(nlogn)
	for(int j=1;(1<<j)<=n;j++){
		for(int i=1;i<=n;i++){
			st[i][j]=st[i][j-1];
			pos[i][j]=pos[i][j-1];
			if((i+(1<<j)-1)<=n&&st[i+(1<<j)-1][j-1]>st[i][j]){
				st[i][j]=st[i+(1<<j)-1][j-1];
				pos[i][j]=pos[i+(1<<j)-1][j-1];
			}
		}
	}
	//查询RMQ(l,r)  O(1)/O(logn)
	cin>>q;
	int k;
	int maxn,maxpos;
	for(int i=1;i<=q;i++){
		cin>>l>>r;
		k=floor(log((double)(r-l+1))/log(2.0));
		maxn=st[l][k];
		maxpos=pos[l][k];
		if(maxn<st[r-(1<<k)+1][k]){
			maxn=st[r-(1<<k)+1][k];
			maxpos=pos[r-(1<<k)+1][k];
		}
		cout<<maxn<<" "<<maxpos<<endl;
	}
	return 0;
}
