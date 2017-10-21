#include <stdio.h>
#define ll unsigned int
#define max 4294967296

int main(){
	ll t,n,i,j;
	unsigned int sum;
	ll q[10],r[10],excess[10],p[10],excess2[10];
	for(i=99991;i<=100000;i++){
		q[i-99991]=max/i;
		r[i-99991]=max%i;
		p[i-99991]=q[i-99991]+r[i-99991]/4;
		if(i==99991){
			p[i-99991]-=2550;
		}else if(i==99992){
			p[i-99991]=76933;
			q[i-99991]=42952;
			r[i-99991]=110912;
		}else if(i==99994){
			p[i-99991]=99204;
			q[i-99991]=42951;
			r[i-99991]=max-q[i-99991]*(i);
		}else if(i==99996){
			p[i-99991]=92726;
			q[i-99991]=42950;
			r[i-99991]=max-q[i-99991]*(i);
		}else if(i==99997){
			p[i-99991]+=10550;
		}else if(i==99998){
			p[i-99991]+=43550;
			q[i-99991]=42949;
			r[i-99991]=max-q[i-99991]*(i);
		}else if(i==99999){
			p[i-99991]+=50550;
			q[i-99991]=42949;
			r[i-99991]=max-q[i-99991]*(i);
		}
		/*excess[i-99991]=(q[i-99991])*(i-1)+2*p[i-99991]-max;
		excess2[i-99991]=(q[i-99991])*(i-1)+p[i-99991]+q[i-99991]-max;
		
		printf("%u %u %u %u %u\n",p[i-99991],q[i-99991],r[i-99991],excess[i-99991],excess2[i-99991]);

		sum=0;
		//printf("%u ",p[i-99991]);
		sum=2*p[i-99991];
		for(j=1;j<i-1;j++){
			sum+=q[i-99991];
			//printf("%lld ",q[n-99991]);
		}
		sum+=q[i-99991];
		//printf("%u ",q[i-99991]);
		//printf("%u %u\n",sum,(sum-p[i-99991]+q[i-99991]));
		*/
	}

	scanf("%u",&t);
	while(t--){
		sum=0;
		scanf("%u",&n);
		printf("%u ",p[n-99991]);
		sum=2*p[n-99991];
		for(i=1;i<n-1;i++){
			sum+=q[n-99991];
			printf("%u ",q[n-99991]);
		}
		sum+=q[n-99991];
		printf("%u\n",q[n-99991]);
		//printf("%u %u",sum,(sum-p[n-99991]+q[n-99991]));
	}

	return 0;
}
