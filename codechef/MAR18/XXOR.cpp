#include <stdio.h>
#include <cmath>
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;

#define CHECK_BIT(var,pos) ((var) & (1<<(pos)))

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

ll ceiling(ll a){
	if(a%2==0)
		return a/2;
	else
		return a/2+1;
}

int main(){
	ll i,j,k,t,n,l,r,num,q;
	ll arr[100000];
	unsigned short int hsh[100000][31];
	ll power[33];
	power[0]=1;
	for(i=1;i<33;i++){
		power[i]=power[i-1]*2;
	}

	n=inp();
	q=inp();
	for(i=0;i<n;i++)
		arr[i]=inp();

	for(i=0;i<n;i++){
		for(j=0;j<31;j++){
			if(CHECK_BIT(arr[i],30-j)==power[30-j]){
				hsh[i][30-j]=1;
			}else
				hsh[i][30-j]=0;
			//printf("%d ",hsh[i][30-j] );
		}
		// printf("\n" );
	}

	// for(i=0;i<31;i++)
	// 	printf("%d ", hsh[0][i]);
	// printf("\n" );
	for(i=1;i<n;i++){
		for(j=0;j<31;j++){
			hsh[i][j]+=hsh[i-1][j];
			// printf("%d ",hsh[i][j] );
		}
		// printf("\n" );
	}

	while(q--){
		l=inp();
		r=inp();
		num=0;
		if(l!=1){
			for(i=0;i<31;i++){
				if((hsh[r-1][i]-hsh[l-2][i])<ceiling(r-l+1))
					num+=power[i];
			}
		}
		else{
			for(i=0;i<31;i++){
				if((hsh[r-1][i])<ceiling(r-l+1))
					num+=power[i];
			}
		}
		//printf("%d\n", num);
		cout<<num<<endl;
	}
	return 0;
}
