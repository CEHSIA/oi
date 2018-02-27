/*
	i,j,k,l表示1，2，3，4步的卡片剩余数
	f[i,j,k,l]表示当前最大分值
	状态转移方程
		f[i][j][k][l]=max(f[i|i-1][j|j-1][k|k-1][l|l-1])
			i,j,k,l>=0;
*/
#include <stdio.h>

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
inline int max(int a,int b){
	return a>b?a:b;
}

int n,m;
int a,b,c,d,t;
int map[355];
int f[40][40][40][40];

int search(int i,int j,int k,int l){
	if(f[i][j][k][l]!=0)return f[i][j][k][l];
	if(i==0&&j==0&&k==0&&l==0){
		f[0][0][0][0]=map[n];
	}else{
		int maxn=0;
		if(i!=0)maxn=max(maxn,search(i-1,j,k,l));
		if(j!=0)maxn=max(maxn,search(i,j-1,k,l));
		if(k!=0)maxn=max(maxn,search(i,j,k-1,l));
		if(l!=0)maxn=max(maxn,search(i,j,k,l-1));
		f[i][j][k][l]=maxn+map[(a-i)+(b-j)*2+(c-k)*3+(d-l)*4+1];
	}
	return f[i][j][k][l];
}

int main(int argc,char *argv[]){
	n=read();m=read();
	for(int i=1;i<=n;i++){
		map[i]=read();
	}
	for(int i=1;i<=m;i++){
		t=read();
		switch(t){
			case 1:{
				a++;
				break;
			}
			case 2:{
				b++;
				break;
			}
			case 3:{
				c++;
				break;
			}
			case 4:{
				d++;
				break;
			}
		}
	}
	put(search(a,b,c,d));
	putchar('\n');
	return 0;
}
