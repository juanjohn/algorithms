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

ll fib[100000];

ll fibo(ll n){
	ll a,b;
	if(fib[n-1]!=-1)
		return fib[n-1];
	else
		return fib[n-1]=fibo(n-1)+fibo(n-2);

	// if(fib[n-2]!=-1)
	// 	a=fib[n-2];
	// else
	// 	a=fibo(n-1);
    //
	// if(fib[n-3]!=-1)
	// 	b=fib[n-3];
	// else
	// 	b=fibo(n-2);
    //
	// return fib[n-1]=a+b;
}

int main(){
	ll i,j,k,t,sum,res,cnt,a,b,c,arr[100000],q,l,r,n;
	for(i=0;i<100000;i++)
		fib[i]=-1;
	fib[0]=0;
	fib[1]=1;
	t=inp();
	while(t--){
		n=inp();
		if(n>2)
		res= fibo(n);
		else
		res= fib[n-1];
		printf("%lld\n", res);
	}
	return 0;
}
