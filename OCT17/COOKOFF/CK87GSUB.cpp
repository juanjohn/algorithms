#include <stdio.h>
#include <algorithm>
#define ll long long
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
	ll i,j,sum,cnt,prev,t,preve;
	char A[100001];
	ll hash[130];
	t=inp();
	while(t--){
		sum=0;
		for(i=0;i<130;i++){
			hash[i]=-1;
		}
		scanf("%s",A);
		prev=0;
		hash[A[0]]=0;
		for(i=1;A[i]!='\0';i++){
			if(hash[A[i]]==-1)
				preve=i;
			else
				preve=hash[A[i]];
			cnt=0;
			for(j='a';j<='z';j++){
				if(hash[j]>preve && j!=A[i]){
					cnt++;
				}
				//printf("%lld ",cnt );
			}
			//printf("\n" );
			if(cnt==1)
				sum++;
			if(cnt==0 && hash[A[i]]!=-1){
				sum+=i-prev;
			}
			hash[A[i]]=i;
			if(A[i]!=A[i-1])
				prev=i;

		}
		printf("%lld\n",sum );
	}
	return 0;
}
