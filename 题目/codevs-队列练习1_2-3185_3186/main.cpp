#include <stdio.h>
#define MAXN 100000
int queue[MAXN]={0};
int head=0,tail=0;
int ope=0,dat=0,n;
int main(int argc,char *argv[]){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&ope);
		if(ope==1){
			scanf("%d",&dat);
			head++;
			head=(head==MAXN)?0:head;
			queue[head]=dat;
		}else{
			if(tail==head){
				printf("impossible!\n");
				return 0;
			}
			tail++;
			tail=(tail==MAXN)?0:tail;
		}
	}
	if(tail==head){
		printf("impossible!\n");
	}else{
		printf("%d\n",queue[tail+1]);
	}
	return 0;
}