#include <stdio.h>


unsigned long long int dp[501][503][2];

unsigned long long int nCr(unsigned long long int n, unsigned long long int r,unsigned long long int mod)
{
	if(n==r) {dp[n][r][1]=1;
		return dp[n][r][0] = 1%mod;}
	if(r==0) {dp[n][r][1]=1;
		return dp[n][r][0] = 1%mod;}
	if(r==1) 
	{
	    dp[n][r][1]=1;
		return dp[n][r][0] = (unsigned long long int)n%mod ;
        }
	  if(dp[n][r][1]==1) 
		return dp[n][r][0];
	   dp[n][r][1]=1;
	return dp[n][r][0] =( nCr(n-1,r,mod) + nCr(n-1,r-1,mod))%mod;
   
}

int main()
{
	long long int t;
	scanf("%lld",&t);
	unsigned long long int n, r,mod;
	while(t--)
	{
		scanf("%Lu %Lu %Lu",&n,&r, &mod)==3;
                if(n<r){
                printf("0\n");
                continue;
                 }               
		r = (r<n-r)? r : n-r;
		printf("%llu\n",nCr(n,r, mod));
		for(long long int i=0;i<501;i++)
		{
			for(long long int j=0;j<501;j++)
			{
				for(long long int k=0;k<2;k++)
					dp[i][j][k]=0;
			}
		}
	}
	return 0;
} 

