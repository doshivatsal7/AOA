#include<stdio.h>

int min,mincost=0,cost[9][9],parent[9];

int find(int i)
{
	 while(parent[i])
	 	i=parent[i];
	 return i;
}

int uni(int i,int j)
{
	 if(i!=j)
	 {
	  	parent[j]=i;
	  	return 1;
	 }
	 return 0;
}

void main()
{
	int i,j,k,a,b,u,v,n,ne=1;
	printf("\nEnter the no. of vertices :\n");
	scanf("%d",&n);
	printf("\nEnter the cost adjacency matrix :\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&cost[i][j]);
			if(cost[i][j]==0)
				cost[i][j]=9999;
		}
	 }
	 printf("\nThe edges of Minimum Cost Spanning Tree are :\n\n");
	 while(ne<n)
	 {
		min=9999;
	  	for(i=1;i<=n;i++)
	  	{
	   		for(j=1;j<=n;j++)
	   		{
	    			if(cost[i][j]<min)
	    			{
				     min=cost[i][j];
				     a=u=i;
				     b=v=j;
	    			}
	   		}
	  	}
		u=find(u);
		v=find(v);
	  	if(uni(u,v))
	  	{
	   		printf("%d. edge (%d,%d) =%d\n",ne++,a,b,min);
	   		mincost +=min;
	  	}
	  	cost[a][b]=cost[b][a]=999;
	 }
	 printf("\n\t***Minimum cost = %d***\n",mincost);
}

/*
OUTPUT:
			
student@student-HP-ProOne-400-G1-AiO:~$ cd Desktop
student@student-HP-ProOne-400-G1-AiO:~/Desktop$ cd Vatsal
student@student-HP-ProOne-400-G1-AiO:~/Desktop/Vatsal$ gcc Kruskal.c -o Kruskal
student@student-HP-ProOne-400-G1-AiO:~/Desktop/Vatsal$ ./Kruskal

Enter the no. of vertices :
7

Enter the cost adjacency matrix :
0 28 0 0 0 10 0 
28 0 16 0 0 0 14
0 16 0 12 0 0 0
0 0 12 0 22 0 18
0 0 0 22 0 0 24
10 0 0 0 25 0 0 
0 14 0 18 24 0 0

The edges of Minimum Cost Spanning Tree are :

1. edge (1,6) =10
2. edge (3,4) =12
3. edge (2,7) =14
4. edge (2,3) =16
5. edge (4,5) =22
6. edge (6,5) =25

	***Minimum cost = 99***
*/