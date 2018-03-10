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

ll absa(ll a){
	if(a>0)
		return a;
	return -1*a;
}

int main(){
	ll i,j,n,max,win;
	n=inp();
	max=0;
	while(n--){
		i=inp();
		j=inp();
		if(absa(j-i)>max){
			win=i>j?1:2;
			max=absa(j-i);
		}
		//printf("%lld %lld\n", win, max );
		//max=absa(i-j)>max?((win=i>j?1:2;),absa(i-j)):max;
	}
	printf("%lld %lld\n",win,max );
	return 0;
}
