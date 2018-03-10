#include <stdio.h>
#define ll long long

ll inp(){
	char c = getchar_unlocked();
	while(c<'0' || c>'9') c = getchar_unlocked();
	ll ret = 0;
	while(c>='0' && c<='9') {
		ret = 10 * ret + c - 48;
		c = getchar_unlocked();
	}
	return ret;
}

ll max(ll a, ll b){
	if(a>b)
		return a;
	return b;
}

ll abs(ll a){
	if(a<0)
		return a-2*a;
	return a;
}

int main(){
	ll t,n,m,min1,max1,min2,max2,i,j,a;
	t=inp();
	while(t--){
		n=inp();
		m=inp();
		min1=min2=10000000;
		max1=max2=0;
		for(j=0;j<m;j++){
			a=inp();
			if(a<min1)
				min1=a;
			if(a>max1)
				max1=a;
		}
		m=inp();
		for(j=0;j<m;j++){
			a=inp();
			if(a<min2)
				min2=a;
			if(a>max2)
				max2=a;
		}
		printf("%lld\n",max(abs(max2-min1),abs(min2-max1)));
	}
}
