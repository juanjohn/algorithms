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
	ll i,j,k,t,n,cnt;
	ll arr[100000];
	t=inp();
	while(t--){
		n=inp();
		for(i=0;i<n;i++){
			arr[i]=inp();
		}
		sort(arr,arr+n);
		cnt=0;
		for(i=1;i<n;i++){
			if(arr[i]==arr[i-1])
				cnt++;
		}
		printf("%lld\n",cnt );
	}
	return 0;
}
