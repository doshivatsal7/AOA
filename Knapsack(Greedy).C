#include<stdio.h>

int weight,n;
float p_w[10],x[10],p[10],w[10];

void greedy(int weight, int n)
{
    int i;
    float rem_weight=weight, profit=0;
    for(i=0;i<n;i++)
        x[i]=0;
    printf("   x[i] \t   w[i] \t    p[i]\n");
    for(i=0;i<n;i++)
    {
        if(w[i]>rem_weight)
            break;
        x[i]=1;
        rem_weight=rem_weight-w[i];
        profit=profit+p[i];
        printf("%f\t%f\t%f\n",x[i],w[i],p[i]);
    }
    if(i<n)
    {
        x[i]=rem_weight/w[i];
        profit=profit+x[i]*p[i];
        rem_weight=rem_weight-x[i]*w[i];
        printf("%f\t%f\t%f\n",x[i],w[i],p[i]);
    }
    printf("The maximum profit is: %f\n",profit);
}

int main()
{
    int i,j;
    float temp;
    printf("Enter the weight of Knapsack and number of objects: ");
    scanf("%d %d",&weight,&n);
    for(i=0;i<n;i++)
    {
        printf("Enter the weight and profit of object: ");
        scanf("%f %f",&w[i],&p[i]);
        p_w[i]=p[i]/w[i];
    }
    for(i=0;i<n;i++)
    {  
          for(j=0;j<n-1;j++)
          {
            if(p_w[j]<p_w[j+1])
            {
              temp=p_w[j];
              p_w[j]=p_w[j+1];
              p_w[j+1]=temp;
              
              temp=p[j];
              p[j]=p[j+1];
              p[j+1]=temp;  
              
              temp=w[j];
              w[j]=w[j+1];
              w[j+1]=temp;
            }
          }
    }
    greedy(weight,n);
    return 0;
}
 
/*OUTPUT:
  
ubuntu@ubuntu:~$ cd Desktop
ubuntu@ubuntu:~/Desktop$ gcc Greedy.c -o Greedy
ubuntu@ubuntu:~/Desktop$ ./Greedy
Enter the weight of Knapsack and number of objects: 20 3
Enter the weight and profit of object: 18 25
Enter the weight and profit of object: 15 24
Enter the weight and profit of object: 10 15
   x[i] 	   w[i] 	    p[i]
1.000000	15.000000	24.000000
0.500000	10.000000	15.000000
The maximum profit is: 31.500000
   
  */ 
