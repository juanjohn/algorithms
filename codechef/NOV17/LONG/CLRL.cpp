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
	ll i,j,t,n,max,min,a;
	ll arr[1000000];
	t=inp();
	while(t--){
		max=1000000002;
		min=0;
		n=inp();
		a=inp();
		for(i=0;i<n;i++){
			arr[i]=inp();
		}
		for(i=0;i<n;i++){
			if(arr[i]<max && arr[i]>min){
				if(arr[i]==a)
					printf("YES\n");
				else{
					if(arr[i+1]<arr[i])
						max=arr[i];
					else
						min=arr[i];
				}
			}
			else{
				printf("NO\n");
				break;
			}
		}
	}
	return 0;
}
