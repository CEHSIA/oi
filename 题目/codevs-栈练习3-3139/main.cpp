#include <stdio.h>
#define MAX 100005
int stack[MAX],n,top,dat,ope;
int main(int argc,char *argv[]){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&ope);
		if(ope==1){
			scanf("%d",&dat);
			top++;
			stack[top]=dat;
		}else if(ope==2){
			top--;
		}else{
			printf("%d\n",stack[top]);
		}
	}
	return 0;
}
