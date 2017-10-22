#include <stdio.h>
#include <limits.h>
#define ll long long
#define gc getchar_unlocked
#include <math.h>

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

ll min(ll a,ll b){
	if(a>b)
		return b;
	return a;
}

int main(){
	ll ng,nl,t,x,y,k,i,j,nbg,nbl,nrg,nrl;
	ll rem=0;//remaining elements of a type
	bool swap;
	char s[100001];
	t=inp();
	while(t--){
		swap=false;ng=0;nl=0;
		scanf("%s",s);
		x=inp();
		y=inp();
		for(i=0;s[i]!='\0';i++){
			if(s[i]=='a')
				ng++;
			else
				nl++;
		}
		if(ng/x<nl/y || (ng/x==nl/y && ng%x<nl%y)){ //take care of ng/x is integer but nl/y is fraction 
			ll tmp=ng;ng=nl;nl=tmp;
			tmp=x;x=y;y=tmp;
			swap=true;
		}

		//always start with larger group
		if(swap){
			nbg=ceil((double)ng/x);
			nbl=ceil((double)nl/y);
			nrg=ng%x;
			nrl=nl%y;

			//divide a's into nbg-1 buckets
			if((nbg)==nbl){
				for(i=0;i<nl/y;i++){
					for(j=0;j<x;j++)
						printf("b");
					for(j=0;j<y;j++)
						printf("a");
				}
				ng-=x*i;
				nl-=y*i;
				if(nl>0){
					for(j=0;j<min(x,ng);j++){
						printf("b");
					}
					ng-=j;
					for(j=0;j<nl;j++){
						printf("a");
					}
					nl-=j;
				}
				ng=0;
			}else{//nbg>nbl, so either divide all l equally into nbg-1 buckets or concentrate them to beginning
				if(nl/(nbg-1)>=1){
					ll r=nl%(nbg-1);
					for(i=0;i<nbg-1;i++){
						for(j=0;j<x;j++)
							printf("b");
						if(i<r)
							for(j=0;j<nl/(nbg-1)+1;j++)
								printf("a");
						else
							for(j=0;j<nl/(nbg-1);j++)
								printf("a");
					}
					if(ng%x!=0){
						for(j=0;j<ng%x;j++){
							printf("b");
						}
					}else{
						for(j=0;j<x;j++){
							printf("b");
						}
					}
					ng=0;
				}else{
					for(i=0;i<nl;i++){
						for(j=0;j<x;j++)
							printf("b");
						printf("a");
					}
					ng-=nl*x;
				}
			
			
				//only ng remaining
				if(ng%x==0 && ng!=0){
					for(i=0;i<ng/x-1;i++){
						for(j=0;j<x;j++){
							printf("b");
						}
						printf("*");
					}
					for(j=0;j<x;j++){
						printf("b");
					}
				}else{
					for(i=0;i<ng/x;i++){
						for(j=0;j<x;j++){
							printf("b");
						}
						printf("*");
					}
					for(j=0;j<ng%x;j++){
						printf("b");
					}
				}
			}
		}
		//no swap region
		else{
			nbg=ceil((double)ng/x);
			nbl=ceil((double)nl/y);
			nrg=ng%x;
			nrl=nl%y;
			//printf("no swap\n");

			//divide b's into nbg-1 buckets
			if((nbg)==nbl){
				for(i=0;i<nl/y;i++){
					for(j=0;j<x;j++)
						printf("a");
					for(j=0;j<y;j++)
						printf("b");
				}
				ng-=x*i;
				nl-=y*i;
				if(nl>0){
					for(j=0;j<min(x,ng);j++){
						printf("a");
					}
					ng-=j;
					for(j=0;j<nl;j++){
						printf("b");
					}
					nl-=j;
				}
				ng=0;
			}else{//nbg>nbl, so either divide all l equally into nbg-1 buckets or concentrate them to beginning
				if(nl/(nbg-1)>=1){
					ll r=nl%(nbg-1);
					for(i=0;i<nbg-1;i++){
						for(j=0;j<x;j++)
							printf("a");
						if(i<r)
							for(j=0;j<nl/(nbg-1)+1;j++)
								printf("b");
						else
							for(j=0;j<nl/(nbg-1);j++)
								printf("b");
					}
					if(ng%x!=0){
						for(j=0;j<ng%x;j++){
							printf("a");
						}
					}else{
						for(j=0;j<x;j++){
							printf("a");
						}
					}
					ng=0;
				}else{
					for(i=0;i<nl;i++){
						for(j=0;j<x;j++)
							printf("a");
						printf("b");
					}
					ng-=nl*x;
				}
			
				//only ng remaining
				if(ng%x==0 && ng!=0){
					for(i=0;i<((ng/x)-1);i++){
						for(j=0;j<x;j++){
							printf("a");
						}
						printf("*");
					}
					for(j=0;j<x;j++){
						printf("a");
					}
				}else{
					for(i=0;i<ng/x;i++){
						for(j=0;j<x;j++){
							printf("a");
						}
						printf("*");
					}
					for(j=0;j<ng%x;j++){
						printf("a");
					}
				}
			}
		}
		printf("\n");
	}
	return 0;
}
