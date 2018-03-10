#include <stdio.h>

int main(){
	char num[100010];
	int arr[10];
	int t,i,a,b;
	scanf("%d",&t);
	while(t--){
		
		scanf("%s",num);

        for(i=0;i<10;i++){
			arr[i]=0;
		}

		for(i=0;num[i]!='\0';i++){
			arr[num[i]-48]++;
		}

		for(i=65;i<=90;i++){
			a=(int)i/10;
			b=i%10;
			if(a==b){
				if(arr[a]>=2)
					printf("%c",i);
			}
			else{
				if(arr[a]>=1 & arr[b]>=1)
					printf("%c",i);
			}
		}
		printf("\n");
	}
	return 0;
}
