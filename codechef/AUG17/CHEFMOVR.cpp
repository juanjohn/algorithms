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
 
ll findpl(ll *arr,ll pl,ll n,ll mean){
  ll i;
  for(i=pl+1;i<n;i++){
    if(arr[i]>mean)
      return i;
  }
  return n;
}
 
ll abs(ll a,ll b){
  if(a>b)
    return a-b;
  return b-a;
}
 
ll moves(ll i,ll pl,ll d){
  ll dif=abs(i,pl);
  if(dif%d==0)
    return dif/d;
  return (dif/d)+1;
}
 
int main(){
  ll t,n,d,pl,mean,i,diff;
  ll arr[100000];
  ll sum,oper;
  t=inp();
  while(t--){
    n=inp();
    d=inp();
    oper=0;
    sum=0;
    pl=-1;
    for(i=0;i<n;i++){
      arr[i]=inp();
      sum+=arr[i];
    }
    if(sum%n==0){
      mean=sum/n;      
      pl=findpl(arr,pl,n,mean);
      for(i=0;i<n;){
        if(arr[i]<mean){
          if(abs(arr[pl],mean)>abs(mean,arr[i])){
            diff=abs(mean,arr[i]);
            oper+=diff*moves(i,pl,d);
            //printf("a1 i %lld oper %lld %lld %lld ",i,oper,diff,moves(i,pl,d));
            arr[pl]-=diff;
            arr[i]+=diff;
            //printf("arr[i] %lld pl %lld arr[pl] %lld \n",arr[i],pl,arr[pl]);
            i++;
          }
          else if(abs(arr[pl],mean)<abs(mean,arr[i])){
            diff=abs(arr[pl],mean);
            oper+=diff*moves(i,pl,d);
            //printf("a2 i %lld oper %lld arr[i] %lld arr[pl] %lld",i,oper,arr[i],arr[pl]);
            arr[pl]-=diff;
            arr[i]+=diff;
            //printf("arr[i] %lld pl %lld arr[pl] %lld \n",arr[i],pl,arr[pl]);
            pl=findpl(arr,pl,n,mean);
            continue;
          }
          else{
            diff=abs(arr[pl],mean);
            oper+=abs(mean,arr[i])*moves(i,pl,d);
            //printf("a3 i %lld oper %lld ",i,oper);
            arr[pl]-=diff;
            arr[i]+=diff;
            //printf("arr[i] %lld pl %lld arr[pl] %lld\n",arr[i],pl,arr[pl]);
            pl=findpl(arr,pl,n,mean);
            i++;
          }
        }
        else{
          //printf("b %lld \n",i);
          i++;
        }
      }
      printf("%lld\n",oper);
    }else{
      printf("-1\n");
    }
  }
  return 0;
} 
