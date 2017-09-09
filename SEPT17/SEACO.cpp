#include <stdio.h>
#include <math.h>
#define gc getchar_unlocked
#define MOD 1000000007

#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

#define pb push_back
#define mp make_pair

#define rep(i,n)	for(ll i=0;i<(n);i++)
#define rep1(i,n)	for(ll i=1;i<=(n);i++)

#define maxn 100009

const ll mod = 1e9+7;

//Segment tree
ll A[maxn];

struct segment
{
	ll subtree_size,addition,multiplication,sum_in_subtree,reset;
	bool change;
	segment(ll _subtree_size=0,ll _addition=0 , ll _multiplication=1 , ll _sum_in_subtree=0 , ll _reset=0 , bool _change=false){
		subtree_size = _subtree_size;
		addition = _addition;
		multiplication = _multiplication;
		sum_in_subtree = _sum_in_subtree;
		reset = _reset ;
		change = _change ;
	}
}seg[1<<18];

void merge(ll node)
{
	ll x = node*2;
	ll y = node*2+1;
	seg[node].sum_in_subtree = (seg[x].sum_in_subtree + seg[y].sum_in_subtree)%mod;
}

void init(ll s,ll e,ll node)
{
	if( s==e ){
		seg[node] = segment(1,0,1,A[s],0,false);
		return;
	}
	init(s,(s+e)/2,node*2);
	init((s+e)/2+1,e,node*2+1);
	seg[node] = segment(seg[node*2].subtree_size + seg[node*2+1].subtree_size , 0,1,(seg[node*2].sum_in_subtree + seg[node*2+1].sum_in_subtree)%mod , 0, false ) ;
}

void lazy(ll node)
{
	ll x = node*2;
	ll y = x+1;

	ll add = seg[node].addition;
	ll mul = seg[node].multiplication;
	ll sizex = seg[x].subtree_size;
	ll sizey = seg[y].subtree_size;

	if( seg[node].change ){
		ll change_to = seg[node].reset;
		seg[node] = segment(seg[node].subtree_size , 0 , 1, seg[node].sum_in_subtree , 0,false);
		seg[x] = segment(sizex ,0,1, ((ll)change_to*(ll)sizex)%mod , change_to , true );
		seg[y] = segment(sizey ,0,1, ((ll)change_to*(ll)sizey)%mod , change_to , true );
		return;
	}

	if( seg[node].addition == 0 && seg[node].multiplication == 1 )	return;

	seg[node] = segment(seg[node].subtree_size , 0 , 1, seg[node].sum_in_subtree , 0, false );
	seg[x] = segment ( sizex , ((ll)mul*(ll)seg[x].addition + (ll)add)%mod , ((ll)seg[x].multiplication*(ll)mul)%mod , ((ll)seg[x].sum_in_subtree*(ll)mul + (ll)add*(ll)sizex)%mod ,((ll)seg[x].reset*(ll)mul+(ll)add)%mod , seg[x].change);
	seg[y] = segment ( sizey , ((ll)mul*(ll)seg[y].addition + (ll)add)%mod , ((ll)seg[y].multiplication*(ll)mul)%mod , ((ll)seg[y].sum_in_subtree*(ll)mul + (ll)add*(ll)sizey)%mod ,((ll)seg[y].reset*(ll)mul+(ll)add)%mod , seg[y].change);
}

void Update(ll s,ll e,ll i,ll j,ll node,ll v,ll op)
{
	if( j < s || e < i )	return ;
	if ( i<=s && e<=j ) {
		if (op == 0)	//addition
			seg[node] = segment ( seg[node].subtree_size , (seg[node].addition + v)%mod , seg[node].multiplication , ((ll)seg[node].sum_in_subtree + (ll)v*(ll)seg[node].subtree_size)%mod , ((ll)seg[node].reset + (ll)v)%mod, seg[node].change );
		else if ( op == 1)	// multiplication
			seg[node] = segment ( seg[node].subtree_size , ((ll)seg[node].addition*(ll)v)%mod , ((ll)seg[node].multiplication*(ll)v)%mod , ((ll)seg[node].sum_in_subtree*(ll)v)%mod , ((ll)seg[node].reset*(ll)v)%mod, seg[node].change );
		else if ( op == 2)	//reset Query
			seg[node] = segment(seg[node].subtree_size , 0,1,((ll)v*(ll)seg[node].subtree_size)%mod , v, true);
		return ;
	}
	lazy(node);
	Update(s,(s+e)/2,i,j,node*2,v,op);
	Update((s+e)/2+1,e,i,j,node*2+1,v,op);
	merge(node);
}

ll Query(ll s,ll e,ll i,ll j,ll node)
{
	if( j<s || e<i )	return 0;
	if( i<=s  && e<=j )	return seg[node].sum_in_subtree ;
	lazy(node);
	return (Query(s,(s+e)/2, i, j, node*2) + Query((s+e)/2+1,e, i,j, node*2+1))%mod;	
}


//Fast input
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

//add_mod and mul mod
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

ll div_mod(ll a, ll b){
	ll m=MOD;
	a = a % m;
	ll inv = modInverse(b, m);
	if (inv == -1)
		return -1;
	else
		return (inv*a)%m;
}

ll mul_mod(ll a,ll b){
	return (a*b)%MOD;
}

int main(){
	ll A[100000],T,i,n,m,t;
	ll cmd[3][100000];
	ll nexec[100000];
	T=inp();
	while(T--){
		n=inp();
		m=inp();
		for(i=0;i<m;i++){
			cmd[0][i]=inp();
			cmd[1][i]=inp();
			cmd[1][i]-=1;
			cmd[2][i]=inp();
			cmd[2][i]-=1;
		}

		//initialization

		for(i=0;i<n;i++)
			A[i]=0;

		//ll *st = constructST(nexec, m);
		init(1,m,1);
		Update(1,m, 1,m,1,1, 2); //sets all values to 1
		
		//logic
		for(i=m-1;i>=0;i--){
			if(cmd[0][i]==2){

				ll l=cmd[1][i];
				ll r=cmd[2][i];
				Update(1,m, l+1,r+1,1,Query(1,m,i+1,i+1,1), 0);
				Update(1,m, i+1,i+1,1,0, 2);//reinitialise all values in x to y with v --Update(1,N, x,y,1,v, op);
			}
		}
		for(i=0;i<m;i++){
			nexec[i]=Query(1,m,i+1,i+1,1);
			//printf("%lld \n", nexec[i]);
		}

		init(1,n,1);
		Update(1,n, 1,n,1,0, 2);
		for(i=0;i<m;i++){
			if(cmd[0][i]==1){

				ll l=cmd[1][i];
				ll r=cmd[2][i];
				Update(1,n, l+1,r+1,1,nexec[i], 0);
			}
		}

		for(i=0;i<n;i++){
			printf("%lld ", Query(1,n,i+1,i+1,1)%mod);
		}
		printf("\n");
	}
	return 0;
}
