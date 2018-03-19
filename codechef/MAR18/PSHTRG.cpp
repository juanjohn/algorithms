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

struct node{
	ll val;
	ll pos;
};

bool comp (node i,node j) { return (i.val<j.val); }

int main(){
	ll i,j,k,n,q,t,l,r,a,b,c,max;
	node tmp;
	n=inp();
	q=inp();
	node arr[100000];
	for(i=0;i<n;i++){
		arr[i].val=inp();
		arr[i].pos=i;
	}
	sort(arr,arr+n,comp);
	while(q--){
		t=inp();
		l=inp();
		r=inp();
		if(t==1){
			for(i=0;i<n;i++){
				if(arr[i].pos==l-1){
					arr[i].val=r;
					break;
				}
			}
			for(i=0;i<n-1;i++){
				if(arr[i].val>arr[i+1].val){
					tmp=arr[i+1];
					arr[i+1]=arr[i];
					arr[i]=tmp;
				}
			}

			for(i=n-1;i>=1;i--){
				if(arr[i].val<arr[i-1].val){
					tmp=arr[i-1];
					arr[i-1]=arr[i];
					arr[i]=tmp;
				}
			}
		}
		else{
			r=r-1;
			l=l-1;
			a=0;b=0;c=0;max=0;
			for(i=r;i>=l+2;i--){
				c=arr[i].val;
				b=arr[i-1].val;
				for(j=0;j<=n;j++){
					if(arr[j].val+b>c && arr[j].val<b){
						a=arr[j].val;
					}
				}
				if(a==0)
					b=c=0;
				if(a+b+c>max)
					max=a+b+c;
			}
			if(max==0)
				printf("0\n" );
			else
				printf("%lld\n",max );
		}
		// for(i=0;i<n;i++)
		// 	printf("%lld", arr[i].val);
		// printf("\n" );
	}
	return 0;
}
