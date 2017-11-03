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
	ll i,j,n,t,sa,sb,tmp,las;
	char arr[100001];
	t=inp();
	while(t--){
		scanf("%s",arr);
		las=-1;
		tmp=0;
		sa=sb=0;
		for(i=0;arr[i]!='\0';i++){
			if(arr[i]=='A'){
				sa++;
				if(las==0){
					sa+=tmp;
				}
				las=0;
				tmp=0;
			}else if(arr[i]=='B') {
				sb++;
				if(las==1){
					sb+=tmp;
				}
				las=1;
				tmp=0;
			}else{
				tmp++;
			}
		}
		printf("%lld %lld\n",sa,sb );
	}
	return 0;
}
