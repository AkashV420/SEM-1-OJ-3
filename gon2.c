#include<stdbool.h>
#include <stdio.h>
#include<stdlib.h>
#include <string.h>

int min(int a,int b){
	return a> b?b:a;
}
int minimum, dist;
int game(int n){
	if(n== 0){
		return 99988654;
	}else{
		return n;
	}
}

 int N, M;
//nction returns false if the cell has value 0 or already gayahua
bool possible2(int mat[][100], int gayahua[][100], int x, int y)
{
	if (!(mat[x][y] != 0) || gayahua[x][y])
		return false;
 
	return true;
}
bool possible(int x, int y)
{
	if (!(x >= M || y >= N || x < 0 || y < 0))
		return true;
	 
	return false;
} 	 

int pttflo(int mat[][100], int gayahua[][100], int i, int j,int x, int y, int minimum, int dist)
{
	
	if (i == x && j == y) 
	{
		minimum = min(dist,minimum);
		
		// printf("in recursion %d\n",minimum );
		return minimum;
	}

	gayahua[i][j] = 1;
	 int fine[5]= {0};
	if (possible(i - 1, j) && possible2(mat, gayahua, i - 1, j))
		fine[1]= pttflo(mat, gayahua, i - 1, j, x, y, minimum, dist + 1);
	 
	if (possible(i, j - 1) && possible2(mat, gayahua, i, j - 1))
		fine[2] = pttflo(mat, gayahua, i, j - 1, x, y, minimum, dist + 1);
	 
	if (possible(i, j + 1) && possible2(mat, gayahua, i, j + 1))
		fine[3] =pttflo(mat, gayahua, i, j + 1, x, y, minimum, dist + 1);
	 
	if (possible(i + 1, j) && possible2(mat, gayahua, i + 1, j))
		fine[4]=  pttflo(mat, gayahua, i + 1, j, x, y, minimum, dist + 1);
 
	gayahua[i][j] = 0;
	// if(minimum||(fine[1]== fine[2]== fine[3]== fine[4]== 0)){
		// return 99988654;
	// }else{
		return min(game(fine[1]),min(game(fine[2]),min(game(fine[3]),game(fine[4]))));
	// }
}


int main()
{
	int t;
	scanf("%d", &t);
	for(int alpha= 0;alpha< t;alpha++){
	int mat[100][100] ; 
	int gayahua[100][100];
	scanf("%d %d", &N,&M);
	memset(gayahua, 0, sizeof (gayahua));
	memset(mat, 0, sizeof (mat));
	for (int i = 0; i < N; ++i)
	{
		for (int j= 0; j < M; ++j)
		{
			scanf("%d", &mat[i][j]);
		}

	}
	// for (int i = 0; i < N; ++i)
	// {
	// 	for (int j= 0; j < M; ++j)
	// 	{
	// 		printf("%d", mat[i][j]);
	// 	}
	// 	printf("\n");

	// }

	int fx,fy,sx,sy;
	int minimum = 99988654;
	scanf("%d %d %d %d",&fx,&fy,&sx,&sy);
	dist = 0;
	minimum = pttflo(mat, gayahua, fx, fy, sx, sy, minimum, dist);
 	// printf("%d\n", minimum);
	if(minimum != 99988654)
		printf("%d\n", minimum);
	else 
		printf("-1\n");
	}
	return 0;
}