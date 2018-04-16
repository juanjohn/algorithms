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
	ll i,j,k,sum,res,cnt,a,b,c,q,l,r,n,op;
	long double t,arr[100000],prod;
	n=inp();
	q=inp();
	for(i=0;i<n;i++){
		scanf("%Lf", &arr[i]);
	}
	while(q--){
		op=inp();
		l=inp();
		r=inp();
		prod=1;
		if(op){
			scanf("%Lf",&t );
			for(i=l-1;i<=r-1;i++){
				arr[i]*=t;
			}
		}else{
			for(i=l-1;i<=r-1;i++){
				prod*=(1-arr[i]);
			}
			printf("%Lf\n", prod);
		}
	}
	return 0;
}
