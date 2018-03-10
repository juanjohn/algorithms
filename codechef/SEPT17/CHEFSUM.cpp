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

	ll t,n,min,min_pos,i;
	ll arr[100000];
	t=inp();
	while(t--){
		n=inp();
		min=INT_MAX;
		min_pos=0;
		
		for(i=0;i<n;i++){
			arr[i]=inp();
			if(arr[i]<min){
				min=arr[i];
				min_pos=i;
			}
		}
		printf("%lld\n",min_pos+1);
	}
	return 0;
}
