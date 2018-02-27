#include <stdio.h>
#include <string.h>

char s[21][10],max[211]="",tmp[211];
bool isused[21]={0};
int n=0;

void dict(int index,char tmp[]){
	char t[211];
	strcpy(t,tmp);
	if(index==n){
		if(strcmp(max,"")==0)strcpy(max,tmp);
		if(strcmp(max,tmp)<0)strcpy(max,tmp);
		return;
	}
	for(int i=1;i<=n;i++){
		if(!isused[i]){
			strcat(tmp,s[i]);
			isused[i]=true;
			dict(index+1,tmp);
			isused[i]=false;
			strcpy(tmp,t);
		}
	}
}

int main(int argc,char *argv[]){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%s",s[i]);
	}
	dict(0,tmp);
	printf("%s\n",max);
	return 0;
}
