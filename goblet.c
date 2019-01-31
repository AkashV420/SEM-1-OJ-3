#include<stdio.h> 
#include<stdlib.h>
int main ()
{
	int X,Y,N,Q;
	int l=0,l1=0;
	int m=99999999,m1=99999999;
	int x,y;
	int p=0;
	char str[10];
	scanf("%d",&N);
	//int FIND[100000][2]={0};
	int PLACE[100001][2]={0};
	scanf("%d",&Q);
	for(int i=0;i<Q;i++)
	{
		 m = 99999999;
		scanf("%s %d %d",str,&X,&Y);
		if(str[0]=='P'){
			PLACE[l++][0]=X;
			PLACE[l1++][1]=Y;
			p++;
			continue;
		}  
		
		if(str[0]=='F'&& p==0){
			printf("-1 -1\n");
			continue;
		}
		if(str[0]=='F' && p!=0)
		{
			m=abs(X-PLACE[0][0])+abs(Y-PLACE[0][1]);
			x = PLACE[0][0];
			y = PLACE[0][1];
		for(int i=1;i<=l-1;i++)
			{
				m1 = abs(X-PLACE[i][0])+abs(Y-PLACE[i][1]);
				if(m1<m)
				{
					m=m1;
					x=PLACE[i][0];
					y=PLACE[i][1];
				}else if(m1==m)
				{
					if(x>PLACE[i][0])
					{
						x=PLACE[i][0];
						y=PLACE[i][1];
					}
					else if(x==PLACE[i][0])
					{
						if(y>PLACE[i][1])
						{
							y=PLACE[i][1];
							x=PLACE[i][0];
						}
					}
				}

			}
		//	printf("%d %d\n",x,y);
		}
            printf("%d %d\n",x,y);

         }    
	return 0;
}
