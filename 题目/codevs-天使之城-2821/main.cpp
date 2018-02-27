#include <stdio.h>
int n,stack[6],top,arr[35],count=1,j=1;
char ope;
int main(int argc,char *argv[]){
	scanf("%d",&n);
	scanf("%c",&ope);
	for(int i=1;i<=n;i++){
		scanf("%c",&ope);
		switch(ope){
			case 'A':{
				arr[j++]=count++;
				break;
			};
			case 'B':{
				if(top==5){
					printf("No\n");
					return 0;
				}
				stack[++top]=count++;
				break;
			}
			case 'C':{
				if(top==0){
					printf("No\n");
					return 0;
				}
				arr[j++]=stack[top--];
				break;
			}
		}
	}
	printf("Yes\n");
	for(int i=1;i<j;i++){
		printf("%d\n",arr[i]);
	}
	return 0;
}