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

int main(){
	ll i,j,k,t,n,x,y,z;
	bool f3,f1,f2,f4;
	ll arr[10][10];
	ll cnt[10];
	t=inp();
	while(t--){
		n=inp();
		x=y=z=0;
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				arr[i][j]=inp();
				if(arr[i][j]==1)
					x++;
				if(arr[i][j]==2)
					y++;
				if(arr[i][j]==3)
					z++;
			}
			cnt[i]=x*100+y*10+z;
			x=y=z=0;
		}

		//for(i=0;i<n;i++)
			//printf("%lld\n", cnt[i]);

		if(n==10){
			f1=f2=f3=false;
			for(i=0;i<n;i++){
				if(cnt[i]==900){
					if(f1==true)
						printf("7\n");
					else{
						printf("1\n");
						f1=true;
					}
				}
				else if(cnt[i]==531){
					if(f2==true)
						printf("8\n");
					else{
						printf("4\n");
						f2=true;
					}
				}
				else if(cnt[i]==720){
					if(f3==true)
						printf("9\n");
					else{
						printf("3\n");
						f3=true;
					}
				}
				else if(cnt[i]==540)
					printf("2\n");
				else if(cnt[i]==810)
					printf("5\n");
				else if(cnt[i]==360)
					printf("6\n");
				else if(cnt[i]==450)
					printf("10\n");
			}
		}

		else if(n==9){
			f1=f2=f3=f4=false;
			for(i=0;i<n;i++){
				if(cnt[i]==800){
					if(f1==true)
						if(f4==false){
						printf("5\n");
						f4=true;
						}
						else
						printf("7\n");
					else{
						printf("1\n");
						f1=true;
					}
				}
				else if(cnt[i]==521){
					if(f2==true)
						printf("8\n");
					else{
						printf("4\n");
						f2=true;
					}
				}
				else if(cnt[i]==620){
					if(f3==true)
						printf("9\n");
					else{
						printf("3\n");
						f3=true;
					}
				}
				else if(cnt[i]==530)
					printf("2\n");
				else if(cnt[i]==350)
					printf("6\n");
			}
		}

		else if(n==8){
			f1=f2=f3=f4=false;
			for(i=0;i<n;i++){
				if(cnt[i]==700){
					if(f1==true)
						if(f4==false){
						printf("5\n");
						f4=true;
						}
						else
						printf("7\n");
					else{
						printf("1\n");
						f1=true;
					}
				}
				else if(cnt[i]==421){
					if(f2==true)
						printf("8\n");
					else{
						printf("4\n");
						f2=true;
					}
				}
				else if(cnt[i]==610){
					printf("3\n");
				}
				else if(cnt[i]==430)
					printf("2\n");
				else if(cnt[i]==340)
					printf("6\n");
			}
		}

		else if(n==7){
			f1=f2=f3=f4=false;
			for(i=0;i<n;i++){
				if(cnt[i]==600){
					if(f1==true)
						if(f4==false){
						printf("5\n");
						f4=true;
						}
						else
						printf("7\n");
					else{
						printf("1\n");
						f1=true;
					}
				}
				else if(cnt[i]==420){
					if(f2==true)
						printf("4\n");
					else{
						printf("2\n");
						f2=true;
					}
				}
				else if(cnt[i]==510)
					printf("3\n");
				else if(cnt[i]==330)
					printf("6\n");
			}
		}

		else if(n==6){
			f1=f2=f3=f4=false;
			for(i=0;i<n;i++){
				if(cnt[i]==500){
					if(f1==true)
						printf("5\n");
					else{
						printf("1\n");
					}
				}
				else if(cnt[i]==320){
					if(f2==true)
						printf("4\n");
					else{
						printf("2\n");
						f2=true;
					}
				}
				else if(cnt[i]==410)
					printf("3\n");
				else if(cnt[i]==230)
					printf("6\n");
			}
		}

		else if(n==5){
			f1=f2=f3=f4=false;
			for(i=0;i<n;i++){
				if(cnt[i]==400){
					if(f1==true)
						if(f4==false){
						printf("3\n");
						f4=true;
						}
						else
						printf("5\n");
					else{
						printf("1\n");
						f1=true;
					}
				}
				else if(cnt[i]==310){
					if(f2==true)
						printf("4\n");
					else{
						printf("2\n");
						f2=true;
					}
				}
			}
		}

		else if(n==4){
			f2=f1=false;
			for(i=0;i<n;i++){
				if(cnt[i]==300){
					if(f1==true)
						printf("3\n");
					else{
						printf("1\n");
						f1=true;
					}
				}
				else if(cnt[i]==210){
					if(f2==true)
						printf("4\n");
					else{
						printf("2\n");
						f2=true;
					}
				}
			}
		}

		else if(n<=3){
			for(i=0;i<n;i++){
				printf("%lld\n",i+1);
			}
		}
		else{
			printf("-1\n");
		}
	}
	return 0;
}
