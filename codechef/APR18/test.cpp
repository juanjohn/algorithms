#include<stdio.h>
#include<math.h>

long long int power(long long int x, long long int y, long long int mod)
{
    if (y == 0)
        return 1;
    else if (y%2 == 0)
    {
    	long long int m = power(x, y/2,mod);
    	return (m%mod*m%mod)% mod;
	}

    else
    {
    	long long int n = power(x,y/2,mod);
    	return ((((x*n)%mod)%mod)*n)% mod;
	}

}
int main()
{
	long long int t,n,w;
	scanf("%lld",&t);
	long long int mod = (pow(10,9)+7);
	while(t--)
	{
		scanf("%lld %lld",&n,&w);
		long long int dn = 0,i;
		long long int d1=1;
		long long int count=0;
		long long int x=1;
		long long int ans;
		if(w<=8 && w>=0)
		{
			count = 9-w;
	    }
	    else if(w<0 && w>= -9)
	    {
	    	count = 10+w;
		}
		else
		{
			count =0;
		}

		count = count % mod;
		if (count == 0)
		{
			ans =0;
		}
		else
		{
			x = power(10,n-2,mod);
			ans = (count*x)% mod;
		}

		printf("%lld\n",ans);

	}

	return 0;
}
