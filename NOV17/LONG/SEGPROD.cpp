#include <stdio.h>
#include <algorithm>
#define ll long long
using namespace std;

int inp(){
	char c = getchar_unlocked();
	while(c<'0' || c>'9')c = getchar_unlocked();
	int ret = 0;
	while(c>='0' && c<='9') {
		ret = 10 * ret + c - 48;
		c = getchar_unlocked();
	}
	return ret;
}

ll gcdExtended(ll a, ll b, ll *x, ll *y){
	if (a == 0){
		*x = 0, *y = 1;
		return b;
	}
	ll x1, y1;
	ll gcd = gcdExtended(b%a, a, &x1, &y1);
	*x = y1 - (b/a) * x1;
	*y = x1;
	return gcd;
}

ll modInverse(ll b, ll m){
	ll x, y;
	ll g = gcdExtended(b, m, &x, &y);
	if (g != 1)
		return -1;
	return (x%m + m) % m;
}

int div(ll a, ll b, ll m){
	a = a % m;
	ll inv = modInverse(b, m);
	if (inv == -1)
		return -1;//printf("Division not defined");
	else
		return (inv*a)%m;//printf("Result of division is %lld", (inv * a) % m);
}

int mul(ll a,ll b, ll m){
	a=a%m;
	b=b%m;
	return (a*b)%m;
}

void swap(int *l,int *r){
	int temp=*l;
	*l=*r;
	*r=temp;
}

int main(){
	int i,j,t,n,p,q,bn;
	int L,R,x,Lp,Rp;
	int arr[1000000];
	int parr[1000000];
	t=inp();
	while(t--){
		n=inp(),p=inp(),q=inp();
		arr[0]=inp();
		parr[0]=mul(arr[0],1,p);
		for(i=1;i<n;i++){
			arr[i]=inp();
			parr[i]=mul(arr[i],parr[i-1],p);
		}
		bn=n/64+2;
		int B[bn];
		for(i=0;i<bn;i++){
			B[i]=inp();
		}

		x=-1;
		printf("%d\n",div(parr[4],parr[4],p) );
		printf("%d\n",div(parr[4],parr[4],p) );
		printf("%d\n",div(parr[4],parr[3],p) );
		printf("%d\n",div(parr[4],parr[2],p) );
		printf("%d\n",div(parr[4],parr[1],p) );
		printf("%d\n",div(parr[4],parr[0],p) );
		printf("%d\n",parr[4] );
/*
		for (size_t i = 0; i < n; i++) {
			printf("%d ", parr[i]);
		}
		printf("\n");
*/
		for(i=0;i<q;i++){
			x=(x+1)%p;
			if(i%64==0){
				printf("partA\n");
				L=(B[i/64]+x)%n;
				R=(B[i/64+1]+x)%n;
				printf("%d %d\n",L,R);
			}else{
				printf("partB\n" );
				L=(L+x)%n;
				R=(R+x)%n;
				printf("%d %d\n",L,R);
			}
			if(L>R)
				swap(&L,&R);

			if(L!=0){
				x=div(parr[R],parr[L],p);
				printf("%d %d %d\n",parr[R],parr[L], x);
			}else{
				x=mul(parr[R],1,p);
				printf("%d %d\n",parr[R], x);
			}
		}
		printf("%d\n",mul(x,1,p));
	}
	return 0;
}
