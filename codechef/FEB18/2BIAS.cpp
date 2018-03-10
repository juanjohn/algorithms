#include <stdio.h>
#include <algorithm>
#define ll long long
using namespace std;
#include <stdlib.h>
#include <random>

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
	ll i,j,k,t,n,tmp,m;
	ll marr[2][1000];
	t=inp();
	srand (time(NULL));
	while(t--){
		n=inp();
		m=inp();
		for(i=0;i<m;i++){
			marr[0][i]=inp();
			marr[1][i]=inp();
		}
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				tmp=inp();
			}
		}
		for(i=0;i<m;i++){
			printf("%lld ", rand()%(marr[1][i]-marr[0][i])+marr[0][i]);
		}
		printf("\n");
	}
	return 0;
}
