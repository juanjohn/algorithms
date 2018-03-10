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
	ll i,j,k,t,n;
	ll arr[100001];
	arr[0]=1;
	arr[1]=1;
	for(i=2;i<100001;i++){
		arr[i]=arr[i-1]+arr[i-2];
	}
	t=inp();
	while(t--){
		n=inp();
		printf("%lld\n", arr[n-1]);
	}
	return 0;
}
