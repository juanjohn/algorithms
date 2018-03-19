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
	ll i,j,k,t,n,p,q,d;
	t=inp();
	long double lost;
	while(t--){
		lost=0.0;
		n=inp();
		while(n--){
			p=inp();
			q=inp();
			d=inp();
			lost+=(long double)q*p/100*d*d/100;
		}
		printf("%Lf\n", lost);
	}
	return 0;
}
