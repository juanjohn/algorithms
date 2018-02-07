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

int main(){
	ll t,n,p,i,nc,nd,np;
	t=inp();
	while(t--){
		nc=nd=0;
		n=inp();
		p=inp();
		for(i=0;i<n;i++){
			np=inp();
			if(np>=p/2)
				nc++;
			else if(np<=p/10)
				nd++;
		}
		if(nc==1 && nd==2)
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}
