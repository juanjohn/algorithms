#include <stdio.h>
#include <algorithm>
#define ll long long
using namespace std;

ll inp(){
	register ll c = getchar_unlocked();
	ll neg=0;
	ll ret=0;
	for(; ((c<48 || c>57) && c!='-'); c = getchar_unlocked());
	if(c=='-') {
    	neg=1;c=getchar_unlocked();
    }
	for(; c>47 && c<58 ; c = getchar_unlocked()) {
		ret = 10 * ret + c - 48;
	}
	if(neg)
		ret=-ret;
	return ret;
}

int main(){
	ll i,j,k,t,res,cnt,a,b,c,arr[100000],q,l,r,n,tsum,sum[100000];
	ll mod=1000000007;
	//mod=100;
	n=inp();
	k=inp();
	a=inp();
	b=inp();
	q=inp();
	arr[0]=0;
	arr[1]=k%mod;
	for(i=2;i<=n;i++){
		tsum=0;
		for(j=1;j<=(i)/2;j++){
			tsum+=((2*arr[j])%mod*arr[i-j])%mod;
		}
		if(i%2==0)
			tsum-=(arr[i/2]*arr[i/2])%mod;
			tsum%=mod;
		arr[i]=((a*arr[i-1])%mod+(b*tsum)%mod)%mod;
	}
	sum[0]=arr[0];

	for(i=1;i<n+1;i++){
		sum[i]=(sum[i-1]+(arr[i]*arr[i])%mod)%mod;
	}
	while(q--){
		l=inp();
		r=inp();
		printf("%lld\n", ((sum[r]-sum[l-1]+mod)%mod));
	}
	return 0;
}
