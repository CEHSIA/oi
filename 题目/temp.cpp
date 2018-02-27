#include <stdio.h>
#include <string.h>

struct stu{
	char id[50];
	float point;
}*s[101];

int n,k;

void swap(stu *&a,stu *&b){
	stu *tmp=a;
	a=b;
	b=tmp;
}

int main(int argc,char *argv[]){
	scanf("%d%d",&n,&k);
	float tmpf;
	char tmps[50];
	for(int i=1;i<=n;i++){
		scanf("%s%f",tmps,&tmpf);
		s[i]=new stu;
		strcpy(s[i]->id,tmps);
		s[i]->point=tmpf;
	}
	for(int i=1;i<=k;i++){
		for(int j=i+1;j<=n;j++){
			if(s[j]->point>s[i]->point){
				swap(s[i],s[j]);
			}
		}
	}
	printf("%s %g",s[k]->id,s[k]->point);
	return 0;
}
