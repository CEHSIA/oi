#include <stdio.h>
double sn;
int n=1,k;
int main(int argc,char *argv[]){
	scanf("%d",&k);
	sn=0;
	while(sn<=k){
		sn+=1.0/n;
		n++;
	}
	printf("%d",n-1);
	return 0;
}
