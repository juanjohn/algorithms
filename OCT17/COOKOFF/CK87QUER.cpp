#include <stdio.h>
#include <algorithm>
#include <math.h>
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
	ll i,j,n,b,a,t,y,a2,sum,bmax;
	bmax=700;
	t=inp();
	while(t--){
		sum=0;
		y=inp();
		for(b=1;b<=min(bmax,y);b++){
			a2=y-b;
			a2=sqrt(y-b);
			sum+=a2;
		}
		printf("%lld\n",sum );
	}
	return 0;
}
