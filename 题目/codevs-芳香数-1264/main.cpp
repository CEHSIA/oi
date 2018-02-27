#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int a[21],r[21];

inline int f(char c){
	switch(c){
		case 'I':return 1;
		case 'V':return 5;
		case 'X':return 10;
		case 'L':return 50;
		case 'C':return 100;
		case 'D':return 500;
		case 'M':return 1000;
	}
}

int main(int argc,char *argv[]){
	string s;
	cin>>s;
	for(int i=0;i<=s.length()-1;i+=2){
		a[i]=(int)(s[i]-'0');
		r[i]=f(s[i+1]);
	}
	int ans=a[1]*r[1];
	for(int i=2;i<;i++){
		if(r[i]>r[i-1]){
			ans-=a[i]*r[i];
		}else{
			ans+=a[i]*r[i];
		}
	}
	cout<<ans<<endl;
	return 0;
}
