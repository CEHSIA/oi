#include <iostream>
#include <fstream>
using namespace std;
//将n个盘子从x借助y移到z上
int num=0;
//ofstream f;
void move(int n,char x,char y,char z){
	if(n==1){
		cout<<x<<" --> "<<z<<endl;
		cout<<x<<" --> "<<z<<endl;
	}else{
		move(n-1,x,z,y);
		cout<<x<<" --> "<<z<<endl;
		cout<<x<<" --> "<<z<<endl;
		move(n-1,y,x,z);
	}
	num++;
}
int main(){
	int a;
	cin>>a;
	move(a,'A','B','C');
	cout<<num<<endl;
	/*long t=1;
	for(int i=1;i<=a;i++){
		t=t*2;
	}
	cout<<t-1<<endl;*/
	return 0;
}

