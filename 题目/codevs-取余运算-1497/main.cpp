#include <stdio.h>
typedef long long ll;
ll b,p,k;
ll pow(ll x,ll a){
	if(a==1)return x;
	ll tmp=pow(x,a>>1)%k;
	if(a&1){
		return (tmp*tmp*x)%k;
	}else{
		return (tmp*tmp)%k;
	}
}
ll pow2(ll x,ll a){
	ll tmp=a;
	ll tmp2=x;
	ll ans=1;
	while(tmp!=0){
		if(tmp&1)ans=(ans*tmp2)%k;
		tmp2=(tmp2*tmp2)%k;
		tmp>>=1;
	}
	return ans;
}
int main(int argc,char *argv[]){
	scanf("%lld%lld%lld",&b,&p,&k);
	printf("%lld^%lld mod %lld=%lld\n",b,p,k,pow2(b,p)%k);
	return 0;
}
