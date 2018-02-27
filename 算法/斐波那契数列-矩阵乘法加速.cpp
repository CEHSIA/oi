#include <stdio.h>
#include <string.h>
#define MAX 10086
struct matrix{
	int n,m;
	int mat[MAX][MAX];
	inline bool operator =(matrix a){
		n=a.n;
		m=a.m;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				mat[i][j]=a.mat[i][j];
	}
}m1,m2;
inline int read(){
	int ans=0;
	bool flag=false;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')flag=true;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		ans=ans*10+ch-'0';
		ch=getchar();
	}
	ans=flag?-ans:ans;
	return ans;
}
inline void put(int x){
	if(x==0){
		putchar('0');
		return;
	}
	int tmp=x,pos=0;
	char cache[20];
	if(tmp<0){
		tmp=-tmp;
		putchar('-');
	}
	while(tmp!=0){
		cache[pos++]=tmp%10+'0';
		tmp/=10;
	}
	for(pos--;pos>=0;pos--)putchar(cache[pos]);
}
inline void put(matrix m){
	for(int i=1;i<=m.n;i++){
		for(int j=1;j<=m.m;j++){
			put(m.mat[i][j]);
			putchar(' ');
		}
		putchar('\n');
	}
}
matrix operator *(matrix a,matrix b){
	matrix c;
	memset(c.mat,0,sizeof(c.mat));
	for(int k=0;k<a.n;k++){
		for(int i=0;i<a.n;i++){
			if(a.mat[i][k]<=0)continue;
			for(int j=0;j<b.m;j++){
				if(b.mat[k][j]<=0)continue;
				c.mat[i][j]+=a.mat[i][k]*b.mat[k][j];
			}
		}
	}
	return c;
}
int main(int argc,char *argv[]){
	freopen("matx-test.in","r",stdin);
	m1.n=read();
	m1.m=read();
	for(int i=1;i<=m1.n;i++){
		for(int j=1;j<=m1.m;j++){
			m1.mat[i][j]=read();
		}
	}
	m2.n=read();
	m2.m=read();
	for(int i=1;i<=m2.n;i++){
		for(int j=1;j<=m2.m;j++){
			m2.mat[i][j]=read();
		}
	}
	m1=m1*m2;
	put(m1);
	fclose(stdin);
	return 0;
}