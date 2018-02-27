#include <stdio.h>
int n,a[101],l,r;
inline void swap(int &a,int &b){
	a^=b;
	b^=a;
	a^=b;
}
int main(int argc,char *argv[]){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	l=1;r=n;
	while(l<=r){
		for(int i=l;i<=r;i++){
			if(a[i]<a[l])swap(a[l],a[i]);
			else if(a[i]>a[r])swap(a[r],a[i]);
		}
		l++;r--;
	}
	for(int i=1;i<=n;i++)printf("%d ",a[i]);
	return 0;
}