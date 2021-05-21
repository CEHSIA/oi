#include <iostream>
#include <string>
using namespace std;
void writer(){
	char n;
	cin>>n;
	if(n!='#'){
		writer();
		cout<<n;
	}
}
int main()
{
	writer();
	return 0;
}
