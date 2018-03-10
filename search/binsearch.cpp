#include <stdio.h>
#include <algorithm>
#include <limits.h>
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

ll ceil(ll a, ll d){
	if(a%2==1)
		return a/d+1;
	return a/d;
}

ll binsearch(ll *arr, ll a, ll n, ll k){
	if(n==1){
		if(arr[a]==k)
			return a;
		else
			return -1;
	}
	else if(n==0){
		return -1;
	}
	else{
		if(k<arr[a+n/2])
			return binsearch(arr, a, n/2, k);
		else
			return binsearch(arr, a+n/2, ceil(n,2), k);
	}
}

ll binlarger(ll *arr,ll a, ll n, ll k ){
	if(n==1){
		if(arr[a]>k)
			return a;
		else
			return a+1;
	}else if(n==0){
		return a+1;
	}else{
		if(k<arr[a+n/2])
			return binlarger(arr, a, n/2, k);
		else
			return binlarger(arr, a+n/2, ceil(n,2), k);
	}
}

ll binsmaller(ll *arr,ll a, ll n, ll k ){
	if(n==1){
		if(arr[a]<k)
			return a;
		else
			return a-1;
	}else if(n==0){
		return a-1;
	}else{
		if(k<arr[a+n/2])
			return binsmaller(arr, a, n/2, k);
		else
			return binsmaller(arr, a+n/2, ceil(n,2), k);
	}
}

int main(){
	ll i,j,k,t,n;
	ll arr[100];
	t=inp();
	while(t--){
		n=inp();
		k=inp();
		for(i=0;i<n;i++){
			arr[i]=inp();
		}
		sort(arr,arr+n);
		printf("%lld %lld\n", binsmaller(arr,0,n,k), binlarger(arr,0,n,k));
	}
	return 0;
}
