#include <stdio.h>
int a[1001],n,p,lc,rc;
inline void swap(int &a,int &b){
	a^=b;
	b^=a;
	a^=b;
}
int main(int argc,char *argv[]){
	freopen("sort-data.in","r",stdin);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		p=i;
		while((p>>1)>=1&&a[p]>a[p>>1]){
			swap(a[p],a[p>>1]);
			p>>=1;
		}
	}
	for(int i=n;i>=2;i++){
		swap(a[1],a[n]);
		p=1;
		lc=p<<1;
		rc=lc+1
		while(p<n){
			if(rc<n){
				
			}else{
				
			}
		}
	}
	return 0;
}
