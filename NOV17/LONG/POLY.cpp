#include <limits.h>
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
	ll i,j,t,T,n,q,a1[100000],a2[100000],a3[100000],a0[100000],min,tmp;
	T=inp();
	while(T--){
		n=inp();
		for(i=0;i<n;i++){
			a0[i]=inp();a1[i]=inp();a2[i]=inp();a3[i]=inp();
		}
		q=inp();
		for(i=0;i<q;i++){
			t=inp();
			min=a0[0]+a1[0]*t+a2[0]*t*t+a3[0]*t*t*t;
			for(j=1;j<n;j++){
				tmp=a0[j]+a1[j]*t+a2[j]*t*t+a3[j]*t*t*t;
				if(tmp<min)
					min=tmp;
			}
			printf("%lld\n", min);
		}
	}
	return 0;
}
