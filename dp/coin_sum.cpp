/* Find the minimum number of coins required to form the sum S. Also display the coins that give the result.
Max denomination and no of denominations allowed - 1000
S <=1000
Queries can be to value of 1000
*/

#include <stdio.h>
#include <algorithm>
#include <limits.h>
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

void inps(char *str, char delim){
	register char c = 0;
	register int i = 0;
	while (c < 33) c=getchar_unlocked();
 	while (c != delim) {
		str[i] = c;
		c=getchar_unlocked();
 		i++;
	}
 	str[i] = '\0';
}

int main(){
	ll i,j,k,t,n,q;
	ll den[1000];
	ll res[2001]; //max S + max denomination allowed
	ll res2[2001];
	n=inp();
	for (i=0;i<n;i++){
		den[i]=inp();
	}
	//sort(den,n);
	for(i=0;i<=2000;i++)
		res[i]=INT_MAX;
	res[0]=0;
	res2[0]=0;
	for(j=0;j<=1000;j++){
		for(i=0;i<n;i++){
			if(res[j]+1<res[j+den[i]]){
				res[j+den[i]]=res[j]+1;
				res2[j+den[i]]=den[i];
			}
		}
	}

	t=inp();
	while(t--){
		q=inp();
		printf("%lld\n", res[q]);
		i=q;
		while(i>=1){
			printf("%lld, ", res2[i]);
			i-=res2[i];
		}
		printf("\n" );
	}
	return 0;
}
