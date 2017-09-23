#include<stdio.h>
#define infinity 999

void dij(int n,int v,int cost[10][10],int dist[])
{
 int i,u,count,w,flag[10],min;
 for(i=0;i<n;i++)
 {
  flag[i]=0;
  if(i!=v)
  	dist[i]=cost[v][i];
  else
  	dist[i]=0;
 }
 count=1;
 while(count<n)
 {
  min=99;
  for(w=0;w<n;w++)
   if(dist[w]<min && !flag[w])
    min=dist[w],u=w;
  flag[u]=1;
  count++;
  for(w=0;w<n;w++)
  {
   if((dist[u]+cost[u][w]<dist[w]) && !flag[w])
    dist[w]=dist[u]+cost[u][w];
  }
 }
}

void main()
{
 int n,v,i,j,cost[10][10],dist[10];
 printf("\nEnter the number of nodes:");
 scanf("%d",&n);
 printf("\nEnter the cost matrix:\n");
 for(i=0;i<n;i++)
  for(j=0;j<n;j++)
  {
   scanf("%d",&cost[i][j]);
   if(cost[i][j]==0)
   cost[i][j]=infinity;
  }
 printf("\nEnter the source of the matrix:");
 scanf("%d",&v);
 dij(n,v,cost,dist);
 printf("\nShortest path:\n");
 for(i=0;i<n;i++)
   printf("%d->%d,cost=%d\n",v,i,dist[i]);

}



/*OUTPUT:

student@student-HP-ProOne-400-G1-AiO:~$ cd Desktop
student@student-HP-ProOne-400-G1-AiO:~/Desktop$ cd Vatsal
student@student-HP-ProOne-400-G1-AiO:~/Desktop/Vatsal$ gcc Djsktra.c –o Djsktra
student@student-HP-ProOne-400-G1-AiO:~/Desktop/Vatsal$ ./Djkstra

Enter the number of nodes:9

Enter the cost matrix:
0 4 0 0 0 0 0 8 0
4 0 8 0 0 0 0 11 0
0 8 0 7 0 4 0 0 2
0 0 7 0 9 14 0 0 0
0 0 0 9 0 10 0 0 0
0 0 4 14 10 0 2 0 0
0 0 0 0 0 2 0 1 6
8 11 0 0 0 0 1 0 7
0 0 2 0 0 0 6 7 0

Enter the source of the matrix:1

Shortest path:
1->0,cost=4
1->1,cost=0
1->2,cost=8
1->3,cost=15
1->4,cost=22
1->5,cost=12
1->6,cost=12
1->7,cost=11
1->8,cost=10
*/