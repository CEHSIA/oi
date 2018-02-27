#include <stdio.h>
int n=0,k,ans;
int a[10001];
bool is=0;
void swap(int &a,int &b){
	a^=b;
	b^=a;
	a^=b;
}
int main(int argc,char *argv[]){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=k;i++){
		for(int j=i+1;j<=n;j++){
			if(a[j]<a[i])swap(a[i],a[j]);
		}
	}
	ans=a[k];
	for(int i=1;i<=k;i++){
		for(int j=i+1;j<=n;j++){
			if(a[j]>a[i])swap(a[i],a[j]);
		}
	}
	ans=a[k]-ans;
	if(ans<2){
		printf("NO\n");
	}else{
		is=true;
		for(int i=2;i<ans;i++){
			if(ans%i==0){
				is=false;
				break;
			}
		}
		if(is){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}
	printf("%d",ans);
	return 0;
}
