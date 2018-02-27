#include <stdio.h>
#define MAXN 1000001
struct node{
	bool lazy;
	int d;
	int max,sum,min;
	int l,r;
	node *lc,*rc;
}*root;
int a[MAXN],n,m;

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
inline int min(int a,int b){
	return a<b?a:b;
}

inline void create(node *&p,int l,int r){
	p=new node;
	p->l=l;
	p->r=r;
	p->max=0;
	p->min=0;
	p->sum=0;
	p->d=0;
	p->lazy=false;
}
void build(node *&p,int l,int r){
	if(p==NULL)create(p,l,r);
	if(l==r){
		p->max=a[l];
		p->min=a[l];
		p->sum=a[l];
		return;
	}
	int mid=(l+r)>>1;
	build(p->lc,l,mid);
	build(p->rc,mid+1,r);
	p->max=max(p->lc->max,p->rc->max);
	p->min=min(p->lc->min,p->rc->min);
	p->sum=p->lc->sum+p->rc->sum;
}
int getsum(node *&p,int l,int r){
	if(p->l==l&&p->r==r)return p->sum;
	int mid=(p->l+p->r)>>1;
	if(r<=mid){
		return getsum(p->lc,l,r);
	}else if(l>mid){
		return getsum(p->rc,l,r);
	}else{
		return getsum(p->lc,l,mid)+getsum(p->rc,mid+1,r);
	}
}
int getmax(node *&p,int l,int r){
	if(p->l==l&&p->r==r)return p->max;
	int mid=(p->l+p->r)>>1;
	if(r<=mid){
		return getmax(p->lc,l,r);
	}else if(l>mid){
		return getmax(p->rc,l,r);
	}else{
		return max(getmax(p->lc,l,mid),getmax(p->rc,mid+1,r));
	}
}
int getmin(node *&p,int l,int r){
	if(p->l==l&&p->r==r)return p->min;
	int mid=(p->l+p->r)>>1;
	if(r<=mid){
		return getmin(p->lc,l,r);
	}else if(l>mid){
		return getmin(p->rc,l,r);
	}else{
		return min(getmin(p->lc,l,mid),getmin(p->rc,mid+1,r));
	}
}
void editp(node *&p,int x,int dat){
	if(p->l==x&&p->r==x){
		p->sum+=dat;
		p->max=p->sum;
		p->min=p->sum;
		return;
	}
	int mid=(p->l+p->r)>>1;
	if(x<=mid){
		editp(p->lc,x,dat);
	}else{
		editp(p->rc,x,dat);
	}
	p->max=max(p->lc->max,p->rc->max);
	p->min=min(p->lc->min,p->rc->min);
	p->sum=p->lc->sum+p->rc->sum;
}
void editr(node *&p,int l,int r,int dat){
	if(p->l==l&&p->r==r){
		p->lazy=true;
		p->d+=dat;
		return;
	}
	
	int mid;
}

int main(int argc,char *argv[]){
	freopen("lt-test.in","r",stdin);
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	build(root,1,n);
	m=read();
	int o,l,r;
	for(int i=1;i<=m;i++){
		o=read();
		l=read();
		r=read();
		if(o==1){
			editp(root,l,r);
		}else{
			put(getsum(root,l,r));
			putchar('\n');
		}
	}
	fclose(stdin);
	return 0;
}
