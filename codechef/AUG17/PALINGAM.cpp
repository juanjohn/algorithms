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
  ll t,i,size,cnt2,cnt1;
  bool flag,flag2;
  char as[501],at[501];
  int arrs[26],arrt[26];
  t=inp();
  while(t--){
    for(i=0;i<26;i++){
      arrs[i]=arrt[i]=0;
    }
    flag=false;
    cnt2=0;
    cnt1=0;
    flag2=false;
    scanf("%s",as);
    scanf("%s",at);
    for(i=0;as[i]!='\0';i++){
      arrs[as[i]-97]++;
      arrt[at[i]-97]++;
    }
    size=i;

    if(size==1)
      printf("B\n");
    else if(size==2){
      if(as[0]==as[1] && at[0]==at[1] && as[0]!=at[0])
	printf("A\n");
      else if(at[0]==at[1] && (at[0]==as[0] || at[0]==as[1]) && as[0]!=as[1])
	printf("A\n");
      else
	printf("B\n");
    }
    else{
      for(i=0;i<26;i++){
	if(arrs[i]>=2 && arrt[i]==0)
	  flag=true;
	//if(arrt[i]==size && arrs[i]>=1 && arrs[i]!=size)
	//flag=true;
	if(arrt[i]==0 && arrs[i]>=1)
	  cnt1++;
      }
      for(i=0;i<size;i++){
	if(arrs[at[i]-97]>=1)
	  cnt2++;
      }
      //      printf("%lld %lld",cnt1,cnt2);
      if(cnt1>=1 && cnt2==size )
	flag=true;
      if(flag)
	printf("A\n");
      else
	printf("B\n");
    }
  }
  return 0;
}
