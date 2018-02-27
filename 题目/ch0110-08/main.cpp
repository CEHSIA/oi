#include <iostream>
#include <string>
using namespace std;
struct people{
	int age,index;
	string id;
};
people *oldman[100],*others[100];
int k;
inline void swap(people *&a,people *&b){
	people *tmp=a;
	a=b;
	b=tmp;
}
int main(int argc,char *argv[]){
	cin>>k;
	int tmpage,m=1,n=1;
	string tmpid;
	for(int i=1;i<=k;i++){
		cin>>tmpid>>tmpage;
		if(tmpage>=60){
			oldman[m]=new people;
			oldman[m]->id=tmpid;
			oldman[m]->age=tmpage;
			oldman[m]->index=i;
			m++;
		}else{
			others[n]=new people;
			others[n]->id=tmpid;
			others[n]->age=tmpage;
			n++;
		}
	}
	m--;
	n--;
	for(int i=1;i<=m-1;i++){
		for(int j=i+1;j<=m;j++){
			if(oldman[i]->age==oldman[j]->age){
				if(oldman[i]->index>oldman[j]->index){
					swap(oldman[i],oldman[j]);
				}
			}else if(oldman[i]->age<oldman[j]->age){
				swap(oldman[i],oldman[j]);
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<oldman[i]->id<<endl;
	}
	for(int i=1;i<=n;i++){
		cout<<others[i]->id<<endl;
	}
	return 0;
}
