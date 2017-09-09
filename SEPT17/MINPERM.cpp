#include <stdio.h>
#define ll long long
#define gc getchar_unlocked

ll inp(){
	char c = gc();
	while(c<'0' || c>'9') c = gc();
	ll ret = 0;
	while(c>='0' && c<='9') {
		ret = 10 * ret + c - 48;
		c = gc();
	}
	return ret;
}

int main(){
	ll t,n,i;
	t=inp();
	while(t--){
		n=inp();
		for(i=0;i<n/2-1;i++){
			printf("%lld %lld ",2*i+2,2*i+1);
		}
		if(n%2==0){
			printf("%lld %lld\n",n,n-1);
		}
		else
			printf("%lld %lld %lld\n",n-1,n,n-2);
	}
	return 0;
}
