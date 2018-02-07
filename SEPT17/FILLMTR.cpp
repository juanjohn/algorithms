#include <stdio.h>
#include <limits.h>
#define ll long long
#define gc getchar_unlocked

ll inp(){
	char c = gc();
	while(c<'0' || c>'9') c = gc();
	ll ret = 0;
	while(c>='0' && c<='9') {
		ret = 10 * ret + c - 48;
		c = gc();
	}
	return ret;
}

void swap(ll *a, ll *b){
	ll *temp=b;
	b=a;
	a=temp;
}

int main(){
	ll t,n,q,i,l1,l2,a,b,val;
	bool flag;
	t=inp();
	while(t--){
		flag=true;
		n=inp();
		q=inp();
		while(q--){
			l1=n;
			l2=n;
			a=inp();
			b=inp();
			val=inp();
			a-=1;
			b-=1;
			
			if(a>b){
				swap(&a,&b);
			}
			if(a==b && val!=0)
				flag=false;
		}
	}
	return 0;
}
