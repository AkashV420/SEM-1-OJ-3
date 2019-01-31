#include<stdio.h>
void clear(int count[])
{
	for(int i=0;i<10002;i++)
		count[i]=0;
}
void sieve(int array[],int count[],int n,int max)
{
	int a[10002];
	for(int i=2;i<=max;i++)
		a[i]=i;
	for(int i=2;i<=max;i++)
	{
		if(a[i]==i)
		{
			for(int j=i*i;j<=max;j+=i)
			{
				if(a[j]==j)
					a[j]=i;
			}
		}

	}
	for(int i=0;i<n;i++)
	{
		while(array[i]!=1)
		{
			count[a[array[i]]]=1;
			array[i]/=a[array[i]];
		}
	}
	
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{

		
		int max=0,sum=0,n,array[10002],count[10002];
		clear(count);
		clear(array);
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&array[i]);
			if(max < array[i])
				max=array[i];
		}
		sieve(array,count,n,max);
		for(int i=2;i<=10001;i++)
		sum+=count[i];
		printf("%d\n",sum);



	}
	return 0;
}




