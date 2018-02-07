#include <stdio.h>
#define ll long long
#define gc getchar_unlocked

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

int main(){
  ll t,i,n,mid;
  ll flag;
  ll arr[100];
  ll hash[10];
  t=inp();
  while(t--){
    flag=0;
    n=inp();
    for(i=0;i<n;i++){
      arr[i]=inp();
      //      printf("%lld ",arr[i]);
    }
    if(n%2==0)
      mid=n/2;
    else
      mid=n/2+1;
    if(arr[0]!=1)
      flag=1;

    for(i=0;i<n;i++){
      //    printf("%lld ",arr[i]);
    }
    //printf("%lld",mid);
    for(i=0;i<mid;i++){
      if(arr[i]!=arr[n-i-1]){
	flag=2;
	//printf(" %lld %lld ass\n",arr[i],arr[n-i-1]);
      }
      if(arr[i]>7)
	flag=3;
      if(i!=0){
	if(arr[i]!=(arr[i-1]+1) && arr[i]!=arr[i-1])
	  flag=4;
      }
      //printf("%lld\n",flag);
    }
    if(arr[mid-1]!=7)
      flag=5;
    //printf("%lld",flag);
    if(flag==0)
      printf("yes\n");
    else
      printf("no\n");
  }
  return 0;
}
