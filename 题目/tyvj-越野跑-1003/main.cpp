#include <iostream>
using namespace std;
int m,t,u,f,d,ud;
int tme=0;
char c;
int main(int argc,char *argv[]){
	cin>>m>>t>>u>>f>>d;
	ud=u+d;
	f*=2;
	for(int i=1;i<=t;i++){
		cin>>c;
		if(c=='f'){
			if(tme+f>=m){
				cout<<i-1<<endl;
				return 0;
			}else{
				tme+=f;
			}
		}else{
			if(tme+ud>=m){
				cout<<i-1<<endl;
				return 0;
			}else{
				tme+=ud;
			}
		}
	}
	cout<<t<<endl;
	return 0;
}
