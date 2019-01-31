#include<stdio.h>
void rec(int matrix[101][101],int j,int i,int xi,int yi,int q)
{

	{
		if(min[i][j]>=matrix[i][j] && q==1)
			min[i][j]=matrix[i][j];
	}
	rec(matrix,j+1,i,xi,yi,1);
	rec(matrix,j,i+1,xi,yi,2);
	rec(matrix,j-1,i,xi,yi,3);
	rec(matrix,j,i-1,xi,yi,4);
}
int main(void)
{
	int t,n,m,i;
	int matrix[101][101];
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{ 
		scanf("%d %d",&n,&m);
		// int matrix[n][m];
		for(j=0;j<n;j++)
		{
			scanf("%d",&matrix[i][j]);
		}
		int xf,yf,xi,yi;
		scanf("%d %d",&xi,&yi);
		scanf("%d",&xf,&yf);
		for(int i=0;i<t;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(matrix[i][j]==0)
					continue;
				else if(i==xf && j==yf)
					matrix[i][j]=0;
				else
					matrix[i][j]=-99999999;
			}
			rec(martrix,xf,yf,xi,yi);
		}  
		return 0;
	}
}
