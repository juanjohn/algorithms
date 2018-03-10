#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

long long inp(){
	char c = getchar_unlocked();
	while(c<'0' || c>'9')c = getchar_unlocked();
	long long ret = 0;
	while(c>='0' && c<='9') {
		ret = 10 * ret + c - 48;
		c = getchar_unlocked();
	}
	return ret;
}

int main() {
	int N, i, arr[500000], Q, x, y, operation,eari,res,L,R,las;
	N=inp();
	Q=inp();
	L=inp();
	R=inp();
	for (i = 0; i < N; ++i){
		arr[i]=0;
	}

	while(Q--){
		operation=inp();
		x=inp();
		y=inp();
    	if (operation == 1)
    		arr[x-1]=y;
    	else{
			eari=x-1;
			las=-1;
			res=0;
			for(i=x-1;i<=y-1;i++){
    			if(arr[i]<=R && arr[i]>=L){
					res+=i-eari+1;
					las=i;
				}else if(arr[i]<L){
					if(las>-1){
						res+=las-eari+1;
					}
				}else{
					eari=i+1;
					las=-1;
				}
			}
			printf("%lld\n",res );
		}
  }

  return 0;
}
