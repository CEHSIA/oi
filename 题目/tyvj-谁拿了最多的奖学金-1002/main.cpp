#include <stdio.h>
#include <string.h>
#define DEBUG
char name[30],maxn[30];
int qm,pj,lw,total;
bool isXB,isGB;
char m,n;
int l,maxtotal=0,TOTAL=0;
int main(int argc,char *argv[]){
	scanf("%d",&l);
	for(int i=1;i<=l;i++){
		scanf("%s %d %d %c %c %d",name,&qm,&pj,&m,&n,&lw);
		isGB=(m=='Y')?true:false;
		isXB=(n=='Y')?true:false;
		total=0;
		if(qm>80&&lw>=1)total+=8000;
		if(qm>85&&pj>80)total+=4000;
		if(qm>90)total+=2000;
		if(qm>85&&isXB)total+=1000;
		if(pj>80&&isGB)total+=850;
		TOTAL+=total;
		if(total>maxtotal){
			strcpy(maxn,name);
			maxtotal=total;
		}
	}
	printf("%s\n%d\n%d\n",maxn,maxtotal,TOTAL);
	return 0;
}
