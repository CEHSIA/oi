#include <iostream>
using namespace std;

int main(int argc,char *argv[]){
	long i,j,d,ir,f;
	bool *root,*a;
	cin>>d>>ir;
	f=(1<<d)-1;
	for(i=1;i<=ir;i++){
		j=1;
		a=root;
		while(j<=f){
			a+=j-1;
			if(a==NULL){
				a=new bool;
				*a=false;
			}
			cout<<j<<(*a)<<' ';
			if(*a){
				*a=false;
				j=(j<<1)+1;
			}else{
				*a=true;
				j=j<<1;
			}
		}
		cout<<endl;
	}
	cout<<(j>>1)<<endl;
	return 0;
}
