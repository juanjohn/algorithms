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

int main(){
	ll i,j,k,t,n,m,x,ko,ke,cnt,tmp;
	char S[1000001];
	t=inp();
	while(t--){
		ko=ke=0;
		n=inp();
		m=inp();
		x=inp();
		k=inp();
		//inps(S,'\n');
		scanf("%s",S);
		cnt=0;
		for(i=0;S[i]!='\0';i++){
			if(S[i]=='E')
				ke++;
			else
				ko++;
		}
		for(i=1;i<=m;i++){
			if(i%2==1){
				tmp=min(x,ko);
				cnt+=tmp;
				ko-=tmp;
				//printf("month %lld worked %lld\n", i, tmp);
			}else{
				tmp=min(x,ke);
				cnt+=tmp;
				ke-=tmp;
				//printf("month %lld worked %lld\n", i, tmp);
			}
		}
		if(cnt>=n)
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}
