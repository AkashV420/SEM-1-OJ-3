#include<stdio.h>
int gcd(int a,int b)
   { 
     if(b==0)
      return a;
     return gcd(b,a%b);
   }

int main()
{
  int i,n,a,b,c,j;
  scanf("%d",&n);
  for(j=0;j<n;j++)
  { 
    scanf("%d %d %d",&a,&b,&c);
    if((c % gcd(a,b))==0)
      printf("YES\n");
    else
      printf("NO\n");
  }
    return 0;
}

    
  

    
