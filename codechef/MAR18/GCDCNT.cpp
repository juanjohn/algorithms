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

ll gcd(ll a, ll b){
	if(b<=1)
		return b;
	else
		return gcd(b,a%b);
}

int main(){
	ll i,j,k,t,sum,res,cnt,a,b,g,c,arr[100000],q,l,r,n;
	n=inp();
	for(i=0;i<n;i++){
		arr[i]=inp();
	}
	q=inp();
	while(q--){
		t=inp();
		l=inp();
		r=inp();
		if(t==1)
			arr[l-1]=r;
		else{
			cnt=0;
			g=inp();
			l-=1;
			r-=1;
			for(i=l;i<=r;i++){
				if(gcd(arr[i],g)==1)
				cnt++;
			}
			printf("%lld\n", cnt);
		}
	}
	return 0;
}
