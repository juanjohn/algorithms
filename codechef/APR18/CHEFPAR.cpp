#include <stdio.h>
#include <algorithm>
#include <random>

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
	ll i,j,k,t,sum,res,cnt,a,b,c,arr[100000],q,l,r,n,m,tmp;
	ll p[100000];
	n=inp();
	m=inp();
	k=inp();
	bool flag;

	srand (time(NULL));

	// std::random_device rd; // obtain a random number from hardware
    // std::mt19937 eng(rd()); // seed the generator
    //std::uniform_int_distribution<> distr(1, k); // define the range
	// distr(eng)

	for(i=0;i<n;i++){
		arr[i]=inp();
	}
	for(i=0;i<m;i++){
		p[i]=inp();
	}

	for(i=0;i<n-1;i++){
		res=arr[i]+rand()%(k)+1;
		// tmp=5;
		// while(tmp--){
		// 	flag=false;
		// 	for(j=i;j<i+35;j++){
		// 		if(res%p[j%m]==0){
		// 			flag=true;
		// 			break;
		// 		}
		// 	}
		// 	if(flag){
		// 		res=arr[i]+rand()%(k)+1;
		// 	}else{
		// 		break;
		// 	}
		// }
		printf("%lld ", res);
	}
	printf("%lld\n", arr[i]+rand()%(k)+1);
	return 0;
}
