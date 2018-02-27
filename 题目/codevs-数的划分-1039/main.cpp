//状态转移方程
//f[n][k]=f[n-k][k]+f[n-1][k-1];
#include <iostream>
using namespace std;
int f[201][7];
int n,k;
int main(int argc,char *argv[]){
	cin>>n>>k;
	f[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i&&j<=k;j++){
			f[i][j]=f[i-j][j]+f[i-1][j-1];
		}
	}
	cout<<f[n][k]<<endl;
	return 0;
}