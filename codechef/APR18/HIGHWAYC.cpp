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

long double mod(long double a){
	if(a>0)
		return a;
	return a-2*a;
}

int main(){
	ll i,j,k,t,sum,cnt,a,b,c,arr[100000],q,l,r,n,y,s;
	ll V[10],D[10],P[10],C[10];
	long double res,tn,th,pos;
	t=inp();
	while(t--){
		n=inp();//number of lanes
		s=inp();//speed of walking
		y=inp();//lane width
		for(i=0;i<n;i++) V[i]=inp();//car speed
		for(i=0;i<n;i++) D[i]=inp();//car direction
		for(i=0;i<n;i++) P[i]=inp();//car position
		for(i=0;i<n;i++) C[i]=inp();//car length

		res=.0;
		long double err=(long double).000001;
		for(i=0;i<n;i++){
			if(D[i]==0){
				pos=P[i]-(long double)res*V[i];
				tn= (long double)y/s;
				if(pos>0.000000){////
					th= (long double)pos/V[i];
					if((th-tn)<=err){///////////////////////////////
						res+= (long double)(pos+C[i])/V[i]+tn;
					}else{
						res+= (long double)tn;
					}
				}else{
					if(pos+C[i]>0.000000)
						res+= (long double)(pos+C[i])/V[i]+tn;
					else
						res+= (long double)tn;
				}
			}else{
				pos=P[i]+(long double)res*V[i];
				tn= (long double)y/s;
				if(pos<0.000000){
					th= (long double)mod(pos)/V[i];
					if((th-tn)<=err){///////////////////////////////
						res+= (long double)(mod(pos)+C[i])/V[i]+tn;
					}else{
						res+= (long double)tn;
					}
				}else{
					if(pos-C[i]<0.000000)
						res+= (long double)mod(pos-C[i])/V[i]+tn;
					else
						res+= (long double)tn;
				}
			}
		}
		printf("%Lf\n", res);
	}
	return 0;
}
