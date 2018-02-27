#include <stdio.h>
#define DEBUG
int n,a[1001],f[1001]={0};
int max=-10;
int main(int argc,char *argv[]){
	#ifdef DEBUG
	freopen("test.in","r",stdin);
	#endif
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		f[i]=1;
		for(int j=1;j<=i;j++){
			if(a[i]>a[j]){
				if(f[j]>=f[i]){
					f[i]=f[j]+1;
				}
			}
		}
		max=max>f[i]?max:f[i];
	}
	printf("%d",max);
	return 0;
}
