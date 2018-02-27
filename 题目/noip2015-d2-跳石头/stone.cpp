#include <iostream>
#include <stdio.h>
#define MAX 50001
using namespace std;
const int MAXL=1e9+1;
int l,m,n;
int dat[MAX],pre[MAX],nex[MAX];
int main(int argc,char *argv[]){
	freopen("testdata.in","r",stdin);
	cin>>l>>n>>m;
	pre[0]=0;
	nex[0]=1;
	dat[0]=MAXL;
	int last=0,now;
	for(int i=1;i<=n;i++){
		cin>>now;
		dat[i]=now-last;
		last=now;
		pre[i]=i-1;
		nex[i]=i+1;
	}
	n++;
	dat[n]=l-dat[n-1];
	nex[n]=-1;
	pre[n]=n-1;
	int min,minpos,lc,rc,miner;
	for(int i=1;i<=m;i++){
		min=MAXL;
		for(int j=1;j!=-1;j=nex[j]){
			if(dat[j]<min){
				min=dat[j];
				minpos=j;
			}
		}
		lc=pre[minpos];
		rc=nex[minpos];
		if(dat[lc]<dat[rc]){
			dat[lc]+=dat[minpos];
			nex[lc]=rc;
			pre[rc]=lc;
		}else{
			dat[minpos]+=dat[rc];
			nex[minpos]=nex[rc];
			pre[nex[minpos]]=minpos;
		}
	}
	min=MAXL;
	for(int j=1;j!=-1;j=nex[j]){
		if(dat[j]<min){
			min=dat[j];
			minpos=j;
		}
	}
	cout<<dat[minpos]<<endl;
	fclose(stdin);
	return 0;
}