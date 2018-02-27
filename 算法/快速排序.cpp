#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int a[1001];
inline void swap(int &a,int &b){
	a^=b;
	b^=a;
	a^=b;
}
void quicksort(int l,int r){
	if(l>=r){
		return;
	}
	int k=a[rand()%(r-l+1)+l];
	int i=l,j=r;
	while(i<j){
		while(i<j&&a[j]>k)j--;
		while(i<j&&a[i]<k)i++;
		if(i<j)swap(a[i],a[j]);
	}
	a[i]=k;
	quicksort(l,i-1);
	quicksort(i+1,r);
}
int main(int argc,char *argv[]){
	int n;
	scanf("%d",&n);
	srand(time(0));
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	quicksort(1,n);
	for(int i=1;i<=n;i++)printf("%d ",a[i]);
	return 0;
}