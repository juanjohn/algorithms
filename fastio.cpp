#include <stdio.h>
#define ll int

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

void inps(char *str, char delim){
	register char c = 0;
	register int i = 0;
	while (c < 33) c=getchar_unlocked();
 	while (c != delim) {
		str[i] = c;
		c=getchar_unlocked();
 		i++;
	}
 	str[i] = '\0';
}


int main(){
	ll n,k,x,cnt;
	cnt=0;
	n=inp();
	k=inp();
	while(n--){
		x=inp();
		if(x%k==0)
			cnt++;
	}
	printf("%d\n",cnt);
	return 0;
}
