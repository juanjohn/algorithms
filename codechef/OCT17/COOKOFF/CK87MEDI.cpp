#include <stdio.h>
#include <algorithm>
#define ll long long
using namespace std;

ll inp(){
	char c = getchar_unlocked();
	while(c<'0' || c>'9')c = getchar_unlocked();
	ll ret = 0;
	while(c>='0' && c<='9') {
		ret = 10 * ret + c - 48;
		c = getchar_unlocked();
	}
	return ret;
}

int main(){
	ll i,j,n,t,k,arr[100];
	t=inp();
	while (t--) {
		n=inp();
		k=inp();
		for(i=0;i<n;i++){
			arr[i]=inp();
		}
		sort(arr,arr+n);
		printf("%lld\n", arr[(n+k-1)/2]);
	}
	return 0;
}
