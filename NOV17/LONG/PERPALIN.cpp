#include <stdio.h>
#include <algorithm>
#define ll long long
using namespace std;

ll inp(){
	char c = getchar_unlocked();
	while(c<'0' || c>'9')c = getchar_unlocked();
	ll ret = 0;
	while(c>='0' && c<='9') {
		ret = 10 * ret + c - 48;
		c = getchar_unlocked();
	}
	return ret;
}

int main(){
	ll i,j,t,n,p;
	char str[100001];
	t=inp();
	while (t--) {
		n=inp();
		p=inp();
		if(p<3)
			printf("impossible\n");
		else{
			if(p%2==1){
				for(i=0;i<p/2;i++)
					str[i]='a';
				str[i++]='b';
				for(;i<p;i++)
					str[i]='a';
				str[i]='\0';
			}
			else{
				for(i=0;i<(p-2)/2;i++)
					str[i]='a';
				str[i++]='b';
				str[i++]='b';
				for(;i<p;i++)
					str[i]='a';
				str[i]='\0';
			}
			for(i=0;i<n/p;i++){
				printf("%s", str);
			}
			printf("\n");
		}
	}
	return 0;
}
