#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int graph[21][21],n;
char *s[21];

int calc(char *a,char *b){
	int la=strlen(a)-1,lb=strlen(b)-1;
	int j,k;
	for(int i=la-1;i>=0;i--){
		for(j=i,k=0;j<=la-1&&k<=lb-1;j++,k++){
			if(a[j]!=b[k]){
				break;
			}
		}
		if(j==la){
			return la-i+1;
		}
	}
	return 0;
}

int main(int argc,char *argv[]){
	/*scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%s",s[i]);
	}
	*/
	char a[20],b[20];
	scanf("%s%s",a,b);
	printf("%s %s\n%d",a,b,calc(a,b));
	
	/*for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			
		}
	}*/
	return 0;
}
