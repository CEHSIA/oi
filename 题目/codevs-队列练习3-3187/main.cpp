#include <stdio.h>
#define MAXN 100000
int n,head,tail,queue[MAXN]={0},ope,dat;
int main(int argc,char *argv[]){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&ope);
		if(ope==1){
			scanf("%d",&dat);
			head++;
			head=(head==MAXN)?0:head;
			queue[head]=dat;
		}else if(ope==2){
			tail++;
			tail=(tail==MAXN)?0:tail;
		}else{
			printf("%d\n",queue[tail+1]);
		}
	}
	return 0;
}
