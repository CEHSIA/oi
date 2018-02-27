#include <iostream>
#define MAX 65536
using namespace std;

int w[31],f[31][20001];

inline int max(int a,int b){
	return a>b?a:b;
}

int main(int argc,char *argv[]){
	int V,n;
	cin>>V>>n;
	for(int i=1;i<=n;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		for(int v=1;v<=V;v++){
			if(v>=w[i]){
				f[i][v]=max(f[i-1][v-w[i]]+w[i],f[i-1][v]);
			}else{
				f[i][v]=f[i-1][v];
			}
		}
	}
	cout<<V-f[n][V]<<endl;
	return 0;
}
