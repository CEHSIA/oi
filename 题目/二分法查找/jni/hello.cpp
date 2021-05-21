#include <iostream>
using namespace std;
int a[11]={1,1,2,3,5,8,13,21,34,55,89};
int find(int l,int r,int key){
	int m=(l+r)/2;
	if(key>a[m]){
		find(m+1,r,key);
	}else if(key<a[m]){
		find(l,m-1,key);
	}else if(key==a[m]){
		return m;
	}else{
		return 123;
	}
}
int main()
{
	int a;
	cin>>a;
	cout<<find(0,11,a)+1;
}
