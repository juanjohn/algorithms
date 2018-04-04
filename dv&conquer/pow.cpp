//finding power in log n 

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

ll power( ll x ,ll n){
	if(n==0)
		return 1;
	else{
		ll tmp = power(x,n/2);
		if(n%2==1){

			return tmp*tmp*x;
		}
		else{
			return tmp*tmp;
		}
	}
}

int main(){
	ll i,j,k,t,sum,res,cnt,a,b,c,arr[100000],q,l,r,n,x;
	t=inp();
	while(t--){
		x=inp();
		n=inp();
		printf("%lld\n", power(x,n));
	}
	return 0;
}
