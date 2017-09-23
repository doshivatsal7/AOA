#include<stdio.h>
int a,b,u,v,n,i,ne=1,j;
int visited[10]={0},min,mincost=0,cost[10][10];
void main()
{
 	printf("\nEnter the number of nodes:");
	scanf("%d",&n);
	printf("\nEnter the adjacency matrix:\n");
 	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
 		{
			scanf("%d",&cost[i][j]);
 			if(cost[i][j]==0)	
				cost[i][j]=999;
		}
	} 
	visited[1]=1;
	printf("\n");
	while(ne < n)
	{
 		for(i=1,min=999;i<=n;i++)
 		for(j=1;j<=n;j++)
 		if(cost[i][j]< min)
 		if(visited[i]!=0)
 		{
 			min=cost[i][j];
 			a=u=i;
 			b=v=j;
 		}
 		if(visited[u]==0 || visited[v]==0)
 		{
 			printf("\n Edge %d:(%d %d) cost:%d",ne++,a,b,min);
 			mincost+=min;
			visited[b]=1;
 		}
 		cost[a][b]=cost[b][a]=999;
 	}
 	printf("\nMinimun cost=%d",mincost);
}



/*OUTPUT:
			
student@student-HP-ProOne-400-G1-AiO:~$ cd Desktop
student@student-HP-ProOne-400-G1-AiO:~/Desktop$ cd Vatsal
student@student-HP-ProOne-400-G1-AiO:~/Desktop/Vatsal$ gcc Prim.c -o Prim
student@student-HP-ProOne-400-G1-AiO:~/Desktop/Vatsal$ ./Prim

Enter the number of nodes:5

Enter the adjacency matrix:
0 3 0 0 1
3 0 9 2 2
0 9 0 3 7
0 2 3 0 0
1 2 7 0 0



Edge 1:(1 5) cost:1
Edge 2:(5 2) cost:2
Edge 3:(2 4) cost:2
Edge 4:(4 3) cost:3
Minimun cost=8


*/