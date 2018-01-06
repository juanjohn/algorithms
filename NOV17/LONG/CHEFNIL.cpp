#include <stdio.h>
#include <algorithm>
#define ll int
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
	ll i,j,n,m,k,pi,pj,iter,maxi,max,gs;
	ll tmp[5];
	ll arr[50][50];
	n=inp();
	n=50;
	m=inp();
	for(k=0;k<m;k++){
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				arr[i][j]=inp();
			}
		}

		if(m==500){
			iter=k*5;
			pi=(iter)%n;
			pj=(iter)/n;

			max=arr[iter%n][iter/n];
			maxi=0;
			for(i=1;i<5;i++){
				iter++;
				if(arr[iter%n][iter/n]>max){
					max=arr[iter%n][iter/n];
					maxi=i;
				}
			}
			iter=k*5+maxi;
		}else{
			iter=k*50;
			pi=(iter)%n;
			pj=(iter)/n;

			max=arr[iter%n][iter/n];
			maxi=0;
			for(i=1;i<50;i++){
				iter++;
				if(arr[iter%n][iter/n]>max){
					max=arr[iter%n][iter/n];
					maxi=i;
				}
			}
			iter=k*50+maxi;
		}

		pi=(iter)%n;
		pj=(iter)/n;
		printf("%d %d\n",pi+1,pj+1);
	}
	return 0;
}
