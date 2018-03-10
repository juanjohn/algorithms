#include <stdio.h>
#define ll long long

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

ll modDivide(ll a, ll b, ll m){
	a = a % m;
	ll inv = modInverse(b, m);
	if (inv == -1)
		return -1;//printf("Division not defined");
	else
		return (inv*a)%m;//printf("Result of division is %lld", (inv * a) % m);
}

int main(){
	ll  a  = 8, b = 3, m = 5,t;
	scanf("%lld",&t);
	while(t--){
		scanf("%lld %lld %lld",&a,&b,&m);
		printf("%lld",modDivide(a, b, m));
	}
	return 0;
}
