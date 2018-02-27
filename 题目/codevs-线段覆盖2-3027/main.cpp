/*状态转移方程
  f[i]=max(f[j])+v[i]
*/
#include <stdio.h>
#include <algorithm>
using namespace std;

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

int n,ans;
int f[1005];
struct line{
	int l,r;
	int v;
}lines[1005];
bool cmp(line a,line b){
	if(a.l==b.l){
		return a.r<b.r;
	}else{
		return a.l<b.l;
	}
}
bool isIn(int x,int l,int r){
	return (x>l)&&(x<r);
}
bool isUnion(line &a,line &b){
	return isIn(a.l,b.l,b.r)||isIn(a.r,b.l,b.r)||isIn(b.l,a.l,a.r)||isIn(b.r,a.l,a.r);
}
int search(int i){
	if(f[i]!=0)return f[i];
	int maxn=0;
	for(int j=i+1;j<=n;j++){
		if(isUnion(lines[i],lines[j]))continue;
		maxn=max(maxn,search(j));
	}
	f[i]=maxn+lines[i].v;
	return f[i];
}
int main(int argc,char *argv[]){
	freopen("data.in","r",stdin);
	n=read();
	for(int i=1;i<=n;i++){
		lines[i].l=read();
		lines[i].r=read();
		lines[i].v=read();
	}
	sort(lines+1,lines+n+1,cmp);
	/*for(int i=1;i<=n;i++){
		put(lines[i].l);
		putchar(' ');
	}
	putchar('\n');
	for(int i=1;i<=n;i++){
		put(lines[i].r);
		putchar(' ');
	}*/
	for(int i=1;i<=n;i++){
		ans=max(ans,search(i));
	}
	put(ans);
	putchar('\n');
	fclose(stdin);
	return 0;
}