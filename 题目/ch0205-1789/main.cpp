#include <stdio.h>

int a[101][5];
bool isVisited[5];

bool isOkay(int pos){
	
}

int main(int argc,char *argv[]){
	int i;
	for(i=1;i<=4;i++){
		scanf("%d",a[1][i]);
	}
	i=1;
	while(a[i][1]!=0&&a[i][2]!=0&&a[i][3]!=0&&a[i][4]!=0){
		for(int j=1;j<=n;j++){
			isVisited[j]=false;
		}
		if(!isOkay(i)){
			printf("No\n");
		}
		i++;
		for(int j=1;j<=4;j++){
			scanf("%d",a[i][j]);
		}
	}
	return 0;
}
