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
	ll i,j,k,t,sum,res,cnt,a,b,c,arr[100000],q,l,r,n,m;
	ll arr2[100001];
	ll arr1[100001];
	int o;
	t=inp();
	while(t--){
		n=inp();
		m=inp();
		k=inp();
		for(i=0;i<n;i++){
			arr[i]=inp();
		}
		for(i=0;i<n;i++){
			arr1[i]=arr2[i]=0;
		}
		while(m--){
			o = getchar();
			l=inp();
			r=inp();
			if(o=='I'){
				arr1[l]=1;
				arr1[r]=-1;
			}
			else{
				arr2[l]=1;
				arr2[r]=-1;
			}
		}
		for(i=1;i<n;i++){
			arr1[i]=arr1[i-1]+arr1[i];
			arr2[i]=arr2[i-1]+arr2[i];
		}
		arr1[n]=arr2[n]=0;
		for(i=1;i<n;i++){
			if(arr1[i]!=0)
				arr1[i]=1;
			if(arr2[i]!=0)
				arr2[i]=-1;
		}
		for(i=1;i<n;i++){
			if(arr1[i]==1){
				arr1[i]=arr1[i-1]+1;
			}
		}
		arr2[n]=0;
		arr1[n]=0;
		for(j=n-1;j>=0;j--){
			if(arr2[j]==-1){
				arr2[j]=arr2[j+1]+1;
			}
		}

		//add one more element
		// for(i=0;i<n-1;i++){
		// 	if(arr2[i]==0 && arr2[i+1]!=0){
		// 		arr2[i]=arr2[i+1]+1;
		// 	}
		// }
		// for(i=0;i<n;i++){
		// 	if(i+1<n && arr1[i]==0 && arr1[i+1]!=0){
		// 		arr1[i]=1;
		// 	}else if(arr1[i]!=0){
		// 		arr1[i]++;
		// 	}
		// }


		for(i=0;i<n;i++){
			printf("%lld ", arr1[i]);
		}
		printf("\n");
		for(i=0;i<n;i++){
			printf("%lld ", arr2[i]);
		}
		printf("\n");

		bool flag=true;
		for(i=0;i<n;i++){
			if(arr1[i]!=0 && arr2[i]!=0)
				flag=false;
		}
		if(flag){
			sum=0;
			for(i=0;i<n;i++){
				if(arr1[i]!=0){
					if(i==n-1 || arr1[i+1]==0){
						sum+=k-arr1[i]+1;
					}
				}else if(arr2[i]!=0){

				}else if(i+1<n && arr1[i+1]!=0 || arr2[i+1]!=0){
					sum+=k;
				}else if(i==n-1){
					sum+=k;
				}
				sum%=1000000007;
			}
			//restriction k
		}else{
			printf("0\n" );
		}
	}
	return 0;
}
