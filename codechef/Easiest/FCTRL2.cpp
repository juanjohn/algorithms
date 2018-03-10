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
	int i,j,t,n,sum;
	t=inp();
	while(t--){
		n=inp();
		sum=1;
		for(i=2;i<=n;i++)
			sum*=i;
		printf("%d\n", sum );
	}
	return 0;
}
