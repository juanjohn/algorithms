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

ll ceil(ll a, ll d){
	if(a%2==1)
		return a/d+1;
	return a/d;
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
	ll i,j,k,t,n,sum;
	ll arr[100000],sarr[100000],A[100001];
	t=inp();
	while(t--){
		n=inp();
		arr[0]=sarr[0]=inp();
		for(i=1;i<n;i++){
			arr[i]=inp();
			sarr[i]=arr[i]+sarr[i-1];
		}
		for(i=0;i<n;i++){
			A[i]=0;
		}
		for(i=0;i<n;i++){
			A[binsmaller(sarr,0,n,sarr[i]-2*arr[i])+1]+=1;
			A[binlarger(sarr,0,n,sarr[i]+arr[i])+1]-=1;
			//printf("%lld %lld\n", binsmaller(sarr,0,n,sarr[i]-2*arr[i]), binlarger(sarr,0,n,sarr[i]+arr[i]) );
		}
		sum=0;
		for(i=0;i<n-1;i++){
			sum+=A[i];
			printf("%lld ", sum-1);
		}
		sum+=A[i];
		printf("%lld\n",sum-1);
	}
	return 0;
}
