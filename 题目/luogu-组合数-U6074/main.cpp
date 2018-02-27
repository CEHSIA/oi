#include <stdio.h>
typedef long long ll;
const int k=6662333;
ll n;
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
	scanf("%lld",&n);
	printf("%lld",pow2(2,n-1)%k);
	return 0;
}
