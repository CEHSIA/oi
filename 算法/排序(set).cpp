#include <stdio.h>
#include <set>
using namespace std;
inline int _____(){
	int __=0;
	bool ___=false;
	char _=getchar();
	while(_<'0'||_>'9'){
		if(_=='-')___=true;
		_=getchar();
	}
	while(_>='0'&&_<='9'){
		__=__*10+_-'0';
		_=getchar();
	}
	__=___?-__:__;
	return __;
}
inline void _______(int ____){
	if(____==0){
		putchar('0');
		return;
	}
	int _=____,__=0;
	char ___[20];
	if(_<0){
		_=-_;
		putchar('-');
	}
	while(_!=0){
		___[__++]=_%10+'0';
		_/=10;
	}
	for(__--;__>=0;__--)putchar(___[__]);
}
int _,__;
multiset<int> ___;
int main(int argc,char *argv[]){
	_=_____();
	for(int ____=1;____<=_;____++){
		__=_____();
		___.insert(__);
	}
	for(multiset<int>::iterator ____=___.begin();____!=___.end();____++){
		_______(*____);
		putchar(' ');
	}
	return 0;
}
