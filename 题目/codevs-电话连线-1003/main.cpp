#include<stdio.h>
#define DEBUG
int g[101][101];
int n,count=0,minstart[101],minend[101],min,c=0;
bool isknown[101]={0};
int main(int argc,char *argv[]){
	#ifdef DEBUG
		freopen("example.in","r",stdin);
	#endif
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&g[i][j]);
		}
	}
	count=0;
	isknown[1]=true;
	c=1;
	for(int k=1;k<=n-1;k++){
		min=10001;
		for(int i=1;i<=n;i++){
			if(isknown[i]){
				for(int j=1;j<=n;j++){
					if(i!=j&&!isknown[j]){
						if(g[i][j]<min){
							min=g[i][j];
							if(i<j){
								minstart[c]=i;
								minend[c]=j;
							}else{
								minstart[c]=j;
								minend[c]=i;
							}
						}
					}
				}
			}
		}
		isknown[minend[c]]=true;
		if(min!=0){
			c++;
		}
		count+=min;
	}
	printf("%d\n",c-1);
	for(int i=1;i<c;i++){
		printf("%d %d\n",minstart[i],minend[i]);
	}
	printf("%d",count);
	return 0;
}