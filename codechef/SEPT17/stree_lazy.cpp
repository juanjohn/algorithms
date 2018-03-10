#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

#define pb push_back
#define mp make_pair

#define rep(i,n)	for(int i=0;i<(n);i++)
#define rep1(i,n)	for(int i=1;i<=(n);i++)

#define maxn 100009

const int mod = 1e9+7;

int A[maxn];

struct segment
{
	int subtree_size,addition,multiplication,sum_in_subtree,reset;
	bool change;
	segment(int _subtree_size=0,int _addition=0 , int _multiplication=1 , int _sum_in_subtree=0 , int _reset=0 , bool _change=false){
		subtree_size = _subtree_size;
		addition = _addition;
		multiplication = _multiplication;
		sum_in_subtree = _sum_in_subtree;
		reset = _reset ;
		change = _change ;
	}
}seg[1<<18];

void merge(int node)
{
	int x = node*2;
	int y = node*2+1;
	seg[node].sum_in_subtree = (seg[x].sum_in_subtree + seg[y].sum_in_subtree)%mod;
}

void init(int s,int e,int node)
{
	if( s==e ){
		seg[node] = segment(1,0,1,A[s],0,false);
		return;
	}
	init(s,(s+e)/2,node*2);
	init((s+e)/2+1,e,node*2+1);
	seg[node] = segment(seg[node*2].subtree_size + seg[node*2+1].subtree_size , 0,1,(seg[node*2].sum_in_subtree + seg[node*2+1].sum_in_subtree)%mod , 0, false ) ;
}

void lazy(int node)
{
	int x = node*2;
	int y = x+1;

	int add = seg[node].addition;
	int mul = seg[node].multiplication;
	int sizex = seg[x].subtree_size;
	int sizey = seg[y].subtree_size;

	if( seg[node].change ){
		int change_to = seg[node].reset;
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

void Update(int s,int e,int i,int j,int node,int v,int op)
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

int Query(int s,int e,int i,int j,int node)
{
	if( j<s || e<i )	return 0;
	if( i<=s  && e<=j )	return seg[node].sum_in_subtree ;
	lazy(node);
	return (Query(s,(s+e)/2, i, j, node*2) + Query((s+e)/2+1,e, i,j, node*2+1))%mod;	
}

void solve()
{
	int N,Q,op,x,y,v;
	scanf("%d%d",&N,&Q);
	rep1(i,N)	scanf("%d",&A[i]),A[i] %= mod;
	init(1,N,1);
	while(Q--){
		scanf("%d%d%d",&op,&x,&y);
		op--;
		if( op <3 ){
			scanf("%d",&v);
			v %= mod;
			Update(1,N, x,y,1,v, op);
		}
		else if ( op == 3 ){
			printf("%d\n",Query(1,N,x,y,1));
		}
	}
}

int main()
{
	int T=1;
	while(T--){
		solve();
	}
	return 0;
}