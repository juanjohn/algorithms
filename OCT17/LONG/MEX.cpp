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

	ll t,n,i,num,k;
	ll arr[300002];
	bool flag;
	t=inp();
	while(t--){
		flag=false;
		n=inp();
		k=inp();
		for(i=0;i<300002;i++){
			arr[i]=0;
		}

		for(i=0;i<n;i++){
			num=inp();
			arr[num]=1;
		}
		/*for(i=0;i<n;i++){
			if(arr[i]==0 && k>0){
				arr[i]=1;
				k--;
			}else if(arr[i]==0 && k==0){
				printf("%lld\n",i);
				flag=true;
				break;
			}
			}*/
		for(i=0;i<300002;i++){
			if(arr[i]==0 && k>0){
				arr[i]=1;
				k--;
			}else if(arr[i]==0 && k==0){
				printf("%lld\n",i);
				flag=true;
				break;
			}
		}
		//printf("%lld\n",min_pos+1);
	}
	return 0;
}
