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

ll min(ll a, ll b){
	if(a>b)
		return b;
	return a;
}

ll mod(ll a){
	if(a>0)
		return a;
	return a-2*a;
}

int main(){
	ll i,j,k,t,sum,res,cnt,a,b,c,arr[100000],q,l,r,n,na,nb,dif,size,x;
	char s[1001];
	t=inp();
	while(t--){
		scanf("%s\n", s);
		n=inp();
		na=nb=0;
		for(i=0;s[i]!='\0';i++){
			if(s[i]=='a')
				na++;
			else
				nb++;
			arr[i]=na-nb;
		}
		size=i;
		sum=0;
		dif=na-nb;
		for(i=0;i<size;i++){
			if(dif>0){
				if(arr[i]>0){
					sum+=n;
				}else if(arr[i]==0){
					sum+=n-1;
				}else{
					if((mod(arr[i])/dif+1) <n){
						sum+=n-(mod(arr[i])/dif+1);
					}
				}
			}else if(dif==0){
				if(arr[i]>0)
					sum+=n;
			}else{
				if(arr[i]>0){
					x=arr[i]/mod(dif);
					if(arr[i]%mod(dif)!=0)
						x+=1;
					sum+=min(x,n);
				}
			}
		}
		printf("%lld\n",sum );
	}
	return 0;
}
