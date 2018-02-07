#include <cstdlib>
#include <stdio.h>
#include <unordered_map>
#include <map>
#define ll long long
#define gc getchar_unlocked

using namespace std;

int inp(){
	char c = gc();
	while(c<'0' || c>'9') c = gc();
	int ret = 0;
	while(c>='0' && c<='9') {
		ret = 10 * ret + c - 48;
		c = gc();
	}
	return ret;
}

void swap(int &a, int &b){
	ll temp=b;
	b=a;
	a=temp;
}

int main(){
	int t,n,q,i,l1,l2,a,b,val;

	map<pair<int,int>,int> B;
	bool flag;
	t=inp();
	while(t--){
		flag=true;
		n=inp();
		q=inp();
		while(q--){
			l1=n;
			l2=n;
			a=inp();
			b=inp();
			val=inp();
			a-=1;
			b-=1;
			
			if(a>b){
				swap(a,b);
			}
			B[make_pair(a,b)]=val;
			
			if(a==b && val!=0)
				flag=false;
		}
	}
	return 0;
}
