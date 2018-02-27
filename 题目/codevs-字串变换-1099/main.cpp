#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <stdio.h>
#define DEBUG
using namespace std;
struct qdata{
	string data;
	short step;
}qtmp,qtmp2;
queue<qdata> q;
set<string> table;
string sa,sb,ax[7],bx[7],stmp;
int n,lena,lenb,pos;
int main(int argc,char *argv[]){
	cin>>sa>>sb;
	qtmp.data=sa;
	qtmp.step=0;
	q.push(qtmp);
	n=1;
	while(cin>>ax[n]>>bx[n])n++;
	n--;
	while(!q.empty()){
		qtmp=q.front();
		qtmp2=qtmp;
		qtmp2.step++;
		q.pop();
		if(qtmp.step>10){
			continue;
		}
		if(table.count(qtmp.data)==0){
			table.insert(qtmp.data);
		}else{
			continue;
		}
		if(qtmp.data==sb){
			cout<<qtmp.step<<endl;
			return 0;
		}
		lena=qtmp.data.length();
		for(int i=1;i<=n;i++){
			lenb=ax[i].length();
			pos=qtmp.data.find(ax[i],0);
			while(pos!=-1){
				stmp.clear();
				stmp+=qtmp.data.substr(0,pos);
				stmp+=bx[i];
				stmp+=qtmp.data.substr(pos+lenb,lena-pos-lenb);
				qtmp2.data=stmp;
				q.push(qtmp2);
				pos=qtmp.data.find(ax[i],pos+1);
			}
		}
	}
	cout<<"NO ANSWER!"<<endl;
	return 0;
}
