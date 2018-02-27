#include <iostream>
#include <algorithm>
#define MAX 50001
using namespace std;
struct node{
	int v;
	int pos;
}r[MAX];
int a[MAX];
inline int lowbit(int x){
	return x&(-x);
}
inline int sum(int x){
	int sum=0;
	for(int i=x;i>=1;i-=lowbit(i))
		sum+=a[i];
	return sum;
}
inline void upd(int x,int d){
	for(int i=x;i<=n;i+=lowbit(i))
		a[i]+=d;
}
int main(int argc,char *argv[]){
	cin>>n;
	for(int i=1;i<=n;i++){
		
	}
	return 0;
}
