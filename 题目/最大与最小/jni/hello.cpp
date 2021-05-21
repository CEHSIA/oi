#include <iostream>
using namespace std;

int main(){
	long max,min,n,m;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m;
		if(i==1){
			min=m;
			max=m;
		}else{
			if(m>max){
				max=m;
			}
			if(m<min){
				min=m;
			}
		}
	}
	cout<<min<<" "<<max<<endl;
	return 0;
}
