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

ll mod(ll a, ll b){
	if(a>b)
		return a-b;
	return b-a;
}

int main(){
	ll i,j,k,t,sum,res,cnt,a,b,c,arr[100000],q,l,r,n,x;
	t=inp();
	arr[0]=0;
	for(i=1;;i++){
		arr[i]=arr[i-1]+i;
		if(arr[i]>2000000001){
			break;
		}
	}
	n=i;
	while(t--){
		x=inp();
		for(i=0;i<n;i++){
			if(x<=arr[i]){
				printf("%lld\n", min(i-1+mod(arr[i-1],x),i+mod(x,arr[i])));
				break;
			}
		}
	}
	return 0;
}
