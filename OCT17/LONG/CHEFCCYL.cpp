#include <stdio.h>
#define ll long long

ll inp(){
	char c = getchar_unlocked();
	while(c<'0' || c>'9') c = getchar_unlocked();
	ll ret = 0;
	while(c>='0' && c<='9') {
		ret = 10 * ret + c - 48;
		c = getchar_unlocked();
	}
	return ret;
}

int inpi(){
	char c = getchar_unlocked();
	while(c<'0' || c>'9') c = getchar_unlocked();
	int ret = 0;
	while(c>='0' && c<='9') {
		ret = 10 * ret + c - 48;
		c = getchar_unlocked();
	}
	return ret;
}



ll min(ll a,ll b){
	if(a>b)
		return b;
	return a;
}

ll max(ll a ,ll b){
	if(a>b)
		return a;
	return b;
}

int main(){
	
	ll sarr[100000],dr,dr1,dr2,dr3,dl,dl1,dl2,dl3,dis1,dis2;
	ll t,nq,nc,i,j,v1,v2,c1,c2,tmp,a,b;
	t=inp();

	while(t--){
		
		nc=inp();
		nq=inp();
		int in[nc+1];
		int out[nc];
		int w[nc];
		int sA[nc];
		ll sexp[nc];

		sA[0]=inpi();
		sarr[0]=inp();
		for(i=1;i<sA[0];i++){
			sarr[i]=sarr[i-1]+inpi();
		}
		
		for(i=1;i<nc;i++){
			sA[i]=sA[i-1]+inpi();
			for(j=0;j<(sA[i]-sA[i-1]);j++){
				sarr[sA[i-1]+j]=sarr[sA[i-1]+j-1]+inp();
			}
		}
		
		for(i=0;i<nc;i++){
			out[i]=inpi();
			in[i+1]=inpi();
			w[i]=inpi();
		}
		in[0]=in[nc];

		a=min(in[0],out[0]);
		b=max(in[0],out[0]);
		if(a==1)
			dis1=sarr[b-2];
		else
			dis1=sarr[b-2]-sarr[a-2];
		dis2=sarr[sA[0]-1]-dis1;
		sexp[0]=min(dis1,dis2)+w[0];
		
		for(i=1;i<nc;i++){
			a=min(in[i],out[i]);
			b=max(in[i],out[i]);
			dis1=sarr[sA[i-1]+b-2]-sarr[sA[i-1]+a-2];
			
			dis2=(sarr[sA[i]-1]-sarr[sA[i-1]-1])-dis1;
			sexp[i]=(min(dis1,dis2)+w[i])+sexp[i-1];
		}
		while(nq--){
			v1=inp();
			c1=inp();
			v2=inp();
			c2=inp();
			if(c1>c2){
				tmp=c1;c1=c2;c2=tmp;
				tmp=v1;v1=v2;v2=tmp;
			}

			a=min(v1,out[c1-1]);
			b=max(v1,out[c1-1]);
			dis1=sarr[sA[c1-2]+b-2]-sarr[sA[c1-2]+a-2];
			if(c1==1)
				dr1=min(dis1,(sarr[sA[0]-1]-dis1))+w[c1-1];
			else
				dr1=min(dis1,(sarr[sA[c1-1]-1]-sarr[sA[c1-2]-1]-dis1))+w[c1-1];
			dr2=sexp[c2-1-1]-sexp[c1-1];
			a=min(v2,in[c2-1]);
			b=max(v2,in[c2-1]);
			dis1=sarr[sA[c2-2]+b-2]-sarr[sA[c2-2]+a-2];
			dr3=min(dis1,(sarr[sA[c2-1]-1]-sarr[sA[c2-2]-1]-dis1));
			dr=dr1+dr2+dr3;

			a=min(v1,in[c1-1]);
			b=max(v1,in[c1-1]);
			dis1=sarr[sA[c1-2]+b-2]-sarr[sA[c1-2]+a-2];

			if(c1==1)
				dl1=min(dis1,(sarr[sA[0]-1]-dis1));
			else
				dl1=min(dis1,(sarr[sA[c1-1]-1]-sarr[sA[c1-2]-1]-dis1));
			
			if(c1==1)
				dl2=sexp[nc-1]-(sexp[c2-1]);
			else
				dl2=sexp[nc-1]-(sexp[c2-1]-sexp[c1-1-1]);
			a=min(v2,out[c2-1]);
			b=max(v2,out[c2-1]);
			dis1=sarr[sA[c2-2]+b-2]-sarr[sA[c2-2]+a-2];
			dl3=min(dis1,(sarr[sA[c2-1]-1]-sarr[sA[c2-2]-1]-dis1))+w[c2-1];
			dl=dl1+dl2+dl3;
			
				
			//printf("%lld %lld %lld %lld %lld %lld %lld %lld\n",dr,dr1,dr2,dr3,dl,dl1,dl2,dl3);
			printf("%lld\n",min(dr,dl));

		}
		
	}
	
	return 0;
}
