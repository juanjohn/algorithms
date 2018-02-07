#include <limits.h>
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
	ll i,j,k,t,n,max,c,d,s;
	ll time[100000];
	t=inp();
	while(t--){
		n=inp();
		max=INT_MIN;
		for(i=0;i<n;i++){
			time[i]=inp();
			if(time[i]>max)
				max=time[i];
		}
		c=inp();
		d=inp();
		s=inp();
		printf("%lld.000000000\n", max*(c-1));
	}
	return 0;
}
