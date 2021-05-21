#include <iostream>
#include <cstring>
using namespace std;
int main(){
	char *s;
	cin.getline(s,100);
	for(int m=0;m<=strlen(s);m++){
		cout<<*(s+m);
	}
	s=strcat(s," ");
	s=strcat(" ",s);
	int j;
	for(int i=strlen(s)-1;i>=0;i--){
		if(*(s+i)==' '){
			j=i+1;
			while(*(s+j)!=' '){
				cout<<*(s+j);
				j++;
			}
			cout<<' ';
		}
	}
	return 0;
}
