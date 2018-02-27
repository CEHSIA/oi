#include <iostream>
#include <string>
using namespace std;
//substr test
//use c replace b in a
string a,b,c,target;
int pos,lena,lenb;
int main(int argc,char *argv[]){
	a="abcdefg";
	b="cde";
	c="h";
	pos=a.find(b);
	lena=a.length();
	lenb=b.length();
	target.clear();
	target+=a.substr(0,pos);
	target+=c;
	target+=a.substr(pos+lenb,lena-pos-lenb);
	cout<<target<<endl;
	return 0;
}