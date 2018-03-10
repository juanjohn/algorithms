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
	ll i,j,n,t,l,a;
	char two[22]="bbaababbaababbaababba";
	t=inp();
	while(t--){
		n=inp();
		a=inp();
		if(a>2){
			printf("1 ");
			for(i=0;i<n/3;i++)
				printf("abc");
			if(n%3==2)
				printf("ab\n");
			else if(n%3==1)
				printf("a\n");
			else
				printf("\n");
		}else if(a==2){
			if(n==1)
				printf("1 a\n");
			else if(n==2)
				printf("1 ab\n");
			else if(n==3)
				printf("2 aab\n");
			else if(n==4)
				printf("2 aabb\n");
			else if(n==5)
				printf("3 aaabb\n");
			else if(n==6)
				printf("3 aaabbb\n");
			else if(n==7)
				printf("3 aaababb\n");
			else if(n==8)
				printf("3 aaababbb\n");
			else if(n<21){
				//printf("4 aaaababba\n");
				printf("4 ");
				for(i=0;i<n;i++)
					printf("%c",two[i]);
				printf("\n");
			}
			else{
				printf("4 ");
				for(i=0;i<n/12;i++)
					printf("bbaababbaaba");
				for(i=0;i<n%12;i++)
					printf("%c",two[i]);
				printf("\n");
			}
		}else{
			printf("%lld ", n);
			for(i=0;i<n;i++)
				printf("a");
			printf("\n");
		}
	}
	return 0;
}
