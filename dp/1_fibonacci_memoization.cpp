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

ll arr[100000],res;

ll fib_memoization(ll a){
	if(arr[a]!='\0')
		res=arr[a];
	else if(a<=2){
		res= 1;
	}
	else{
		res=fib_memoization(a-1)+fib_memoization(a-2);
	}
	arr[a]=res;
	return res;

}

int main(){
	ll i,j,k,t,n;
	t=inp();
	while(t--){
		n=inp();
		printf("%lld\n", fib_memoization(n));
	}

	return 0;
}
