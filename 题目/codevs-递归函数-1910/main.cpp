#include <stdio.h>
int ans[21][21][21]={0};
int w(int a,int b,int c){
	if(a>20||b>20||c>20)return w(20,20,20);
	if(ans[a][b][c]>0)return ans[a][b][c];
	int tmp;
	if(a<=0||b<=0||c<=0)tmp=1;
	else if(a<b&&b<c)tmp=w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c);
	else tmp=w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1);
	ans[a][b][c]=tmp;
	return tmp;
}
int main(int argc,char *argv[]){
	return 0;
}
