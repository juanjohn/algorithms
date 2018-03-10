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
	ll i,j,k,t,n,q,m,cnt,tmp;
	ll arr[2][400];
	ll ma[300];
	t=inp();
	while(t--){
		n=inp();
		for(i=0;i<n;i++){
			arr[0][i]=inp();
			arr[1][i]=inp();
		}
		q=inp();
		while(q--){
			m=inp();
			for(i=0;i<m;i++){
				ma[i]=inp();
			}
			cnt=0;
			for(i=0;i<n;i++){
				//printf("%lld %lld\n", arr[0][i], arr[1][i]);
				tmp=0;
				for(j=0;j<m;j++){
					if(ma[j]>=arr[0][i] && ma[j]<=arr[1][i])
						tmp++;
				}
				if(tmp%2==1)
					cnt++;
			}
			printf("%lld\n",cnt );
		}
	}

	return 0;
}
