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
	ll i,j,k,t,sum,res,cnt,a,b,c,arr[100000],q,l,r,n;
	n=inp();
	while(n--){
		cnt=0;
		for(i=0;i<5;i++){
			res=inp();
			if(res)
				cnt++;
		}
		if(cnt==0)
			printf("Beginner\n");
		else if(cnt==1)
			printf("Junior Developer\n");
		else if(cnt==2)
			printf("Middle Developer\n");
		else if(cnt==3)
			printf("Senior Developer\n");
		else if(cnt==4)
			printf("Hacker\n");
		else
			printf("Jeff Dean\n");
	}
	return 0;
}
