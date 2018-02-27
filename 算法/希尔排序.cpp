#include <iostream>
using namespace std;
int a[1000];
void swap(int &a,int &b){
	int tmp=a;
	a=b;
	b=tmp;
}
void shellsort(int n){
	for(int inc=n>>1;inc>=1;inc>>=1)
		for(int i=1;(i+inc)<=n;i++)
			if(a[i]>a[i+inc])
				swap(a[i],a[i+inc]);
}
int main(int argc,char *argv[]){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	shellsort(n);
	for(int i=1;i<=n;i++){
		cout<<a[i]<<' ';
	}
	cout<<endl;
	return 0;
}
/*1 2 3 4 5 6 7 8 9
3 9 4 2 1 5 7 6 8
3         5
  7         9
    4         6
	  2         8
3 7 4 2 1 5 9 6 8
3   4
  2   7
    1   4
	  5   7
	    4   9
		  6   7
		    8   9
3 2 1 5 4 6 8 7 9
2 3
  1 3*/