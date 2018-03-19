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

ll max(ll a,ll b){
	if(a<b)
		return b;
	return a;
}

int main(){
	ll i,j,k,t,sum,res,m,cnt,a,b,c,arr[100][100],q,l,r,n;
	t=inp();
	while(t--){
		n=inp();
		m=inp();
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				arr[i][j]=inp();
			}
		}
		if(arr[0][0]==-1)
			arr[0][0]=1;
		i=0;
		for(j=0;j<m-1;j++){
			if(arr[i][j+1]==-1)
				arr[i][j+1]=arr[i][j];
		}
		j=0;
		for(i=0;i<n-1;i++){
			if(arr[i+1][j]==-1)
				arr[i+1][j]=arr[i][j];
		}
		for(i=1;i<n;i++){
			for(j=1;j<m;j++){
				if(arr[i][j]==-1){
					arr[i][j]=max(arr[i-1][j],arr[i][j-1]);
				}
			}
		}
		//checking
		bool flag=true;
		i=0;
		for(j=1;j<m;j++){
			if(arr[i][j]<arr[i][j-1]){
				flag=false;
			}
		}
		j=0;
		for(i=1;i<n;i++){
			if(arr[i][j]<arr[i-1][j]){
				flag=false;
			}
		}
		for(i=1;i<n;i++){
			for(j=1;j<m;j++){
				if(arr[i][j]<arr[i][j-1] || arr[i][j]<arr[i-1][j] || arr[i][j]>2000000000){
					flag=false;
					break;
				}
			}
		}
		if(flag){
			for(i=0;i<n;i++){
				for(j=0;j<m;j++){
					printf("%lld ", arr[i][j]);
				}
				printf("\n");
			}
		}else{
			printf("-1\n");
		}
	}
	return 0;
}
