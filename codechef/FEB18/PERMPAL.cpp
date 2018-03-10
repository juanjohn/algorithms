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

struct node{
	char c;
	int p;
};

int compare(const void *s1, const void *s2)
{
  struct node *e1 = (struct node *)s1;
  struct node *e2 = (struct node *)s2;
  if (e1->c < e2->c)
        return -1;
    else if (e1->c > e2->c)
        return +1;
    else
        return 0;
}

int main(){
	ll i,j,k,t,n,cnt,m,u;
	ll mid;
	ll lhash[26];
	ll rev[100001];
	char s[100001];
	struct node ss[100001];
	t=inp();
	while(t--){
		cnt=0;
		for(i=0;i<26;i++)
			lhash[i]=0;
		scanf("%s",s);
		for(i=0;s[i]!='\0';i++){
			ss[i].c= s[i];
			ss[i].p= i+1;
			lhash[ss[i].c-97]++;
		}
		n=i;
		for(i=0;i<26;i++){
			if(lhash[i]%2==1){
				cnt++;
			}
		}
		qsort(ss, n, sizeof(struct node), compare);

		if(cnt>1){
			printf("-1\n");
		}else{
			j=0;m=0;
			for(i=0;i<n;){
				if(lhash[ss[i].c-97]%2==0){
					k=i;
					u=lhash[ss[i].c-97];
					for(;i<k+u/2;i++){
						printf("%d ",ss[i].p);
					}
					for(;i<k+u;i++)
						rev[j++]=ss[i].p;
				}else{
					k=i;
					u=lhash[ss[i].c-97];
					for(;i<k+u/2;i++){
						printf("%d ",ss[i].p);
					}
					mid=ss[i].p;i++;
					for(;i<k+u;i++)
						rev[j++]=ss[i].p;
				}
			}
			if(cnt==1){
				printf("%lld ", mid);
			}
			for(i=j-1;i>=0;i--){
				if(i==0)
				printf("%lld\n",rev[i]);
				else
				printf("%lld ",rev[i]);
			}

		}
	}
	return 0;
}
