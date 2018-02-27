#include <stdio.h>

char sa[505],sb[505],c;
int la,lb,l;
int a[505],b[505],ans[505];

bool isNum(char c){
	return (c>='0'&&c<='9');
}
void swap(int &a,int &b){
	a^=b;
	b^=a;
	a^=b;
}

int main(int argc,char *argv[]){
	la=0;
	c=getchar();
	while(!isNum(c))c=getchar();
	while(isNum(c)){
		sa[la++]=c;
		c=getchar();
	}
	la--;
	lb=0;
	c=getchar();
	while(!isNum(c))c=getchar();
	while(isNum(c)){
		sb[lb++]=c;
		c=getchar();
	}
	lb--;
	for(int i=la,j=0;i>=0;i--,j++)
		a[j]=sa[i]-'0';
	for(int i=lb,j=0;i>=0;i--,j++)
		b[j]=sb[i]-'0';
	l=la>lb?la:lb;
	if(la<lb){
		for(int i=0;i<=l;i++)
			swap(a[i],b[i]);
		putchar('-');
	}else if(la==lb){
		bool isBigger=true;
		for(int i=0;i<=l;i++){
			if(a[i]<b[i]){
				isBigger=false;
				break;
			}
		}
		if(!isBigger){
			for(int i=0;i<=l;i++)
				swap(a[i],b[i]);
			putchar('-');
		}
	}
	for(int i=0;i<=l;i++){
		if(a[i]<b[i]){
			a[i+1]--;
			ans[i]=10-b[i]+a[i];
		}else{
			ans[i]=a[i]-b[i];
		}
	}
	for(int i=l;i>=0;i--){
		putchar(ans[i]+'0');
	}
	return 0;
}