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
	ll i,j,k,n,q,t,l,r,a,b,c,max,size;
	n=inp();
	q=inp();
	ll arr[100000];
	ll arr2[100000];
	for(i=0;i<n;i++){
		arr[i]=inp();
	}
	while(q--){
		t=inp();
		l=inp();
		r=inp();
		if(t==1){
			arr[l-1]=r;
		}
		else{
			l-=1;
			r-=1;
			for(i=l;i<=r;i++){
				arr2[i-l]=arr[i];
			}
			size=r-l+1;
			a=b=c=max=0;
			sort(arr2,arr2+size);
			// for(i=0;i<size;i++)
			// 	printf("%lld ",arr2[i] );
			// printf("\n" );
			for(i=size-1;i>=2;i--){
				c=arr2[i];
				b=arr2[i-1];
				for(j=i-2;j>=0;j--){
					if(arr2[j]+b>c){
						a=arr2[j];
						break;
					}
				}
				if(a==0)
					b=c=0;
				if(a+b+c>max)
					max=a+b+c;
			}
			printf("%lld\n",max );
		}
	}
	return 0;
}
