#include <stdio.h>
#include <algorithm>
#define ll long long

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
	ll i,j,k,t,n,cnt,size;
	char str[500001];
	ll hash[130];
	t=inp();
	for(i=0;i<130;i++)
		hash[i]=0;
	while(t--){
		//inps(str,'\n');
		scanf("%s",str);
		cnt=0;
		for(i=0;str[i]!='\0';i++){

		}
		size=i;
		if(size>=4)
		for(i=0;str[i+3]!='\0';i++){
			if(str[i]=='c' || str[i]=='h' || str[i]=='e' || str[i]=='f'){
				// printf("%c \n",str[i] );
				hash[str[i]]++;
				hash[str[i+1]]++;
				hash[str[i+2]]++;
				hash[str[i+3]]++;
				// for(j=97;j<=122;j++){
				// 	printf("%lld", hash[j]);
				// }
				// printf("\n");
				if(hash['c']==1 && hash['h']==1 && hash['e']==1 && hash['f']==1){
					cnt++;
					//printf("added\n");
				}
				hash[str[i]]--;
				hash[str[i+1]]--;
				hash[str[i+2]]--;
				hash[str[i+3]]--;
			}
		}
		if(cnt!=0){
			printf("lovely %lld\n", cnt);
		}
		else{
			printf("normal\n");
		}
	}

	return 0;
}
