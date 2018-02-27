#include <iostream>
using namespace std;
int a[20001];
/*void swap(int &a,int &b){
	a=a^b;
	b=a^b;
	a=a^b;
}*/
void swap(int &a,int &b){
	int c=a;
	a=b;
	b=c;
}
void quicksort(int l,int r){
	if(l>r){
		return;
	}
	int i=l,j=r,k=a[l];
	while(i!=j){
		while(i<j&&a[j]>=k)j--;
		while(i<j&&a[i]<=k)i++;
		if(i<j)swap(a[i],a[j]);
	}
	a[l]=a[i];
	a[i]=k;
	quicksort(l,i-1);
	quicksort(i+1,r);
}
int main(int argc,char *argv[]){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	quicksort(1,n);
	for(int i=1;i<=n;i++){
		cout<<a[i]<<' ';
	}
	cout<<endl;
	return 0;
}
