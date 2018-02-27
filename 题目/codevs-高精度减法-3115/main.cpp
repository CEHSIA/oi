#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
int la,lb,lc;
int a[501],b[501],c[501];
int main(int argc,char *argv[]){
	string s;
	cin>>s;
	la=s.length();
	int j=1;
	for(int i=la;i>0;i--){
		a[j++]=(int)(s[i]-'0');
	}
	for(int i=1;i<=la;i++){
		cout<<a[i];
	}
	cout<<endl;
	return 0;
}
