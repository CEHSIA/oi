#include <iostream>
#include <string>
using namespace std;
int find(string s,string p){
	bool isQuit;
	for(int i=0;i<=s.length()-p.length();i++){
		isQuit=true;
		cout<<"now is matching:"<<s[i]<<endl;
		for(int j=0;j<=p.length();j++){
			if(s[i]!=p[j]){
				cout<<"now is unmatching"<<p[j]<<endl;
				isQuit=false;
				break;
			}
		}
		if(isQuit){
			return i;
		}
	}
	return -1;
}
int main(int argc,char *argv[]){
	string a,b;
	cin>>a>>b;
	//cout<<"a,b are:"<<a<<' '<<b<<endl;
	cout<<find(a,b)<<endl;
	return 0;
}
