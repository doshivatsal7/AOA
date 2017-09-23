#include<stdio.h>
#include<stdlib.h>

void main()
{
	int a[100],n,count,i;
	printf("Enter the number of players: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		a[i]=rand()%100+1;
		printf("%d ",a[i]);
	}
	printf("\n");
	count=n;
	while(count>1)
	{
		count=0;
		for(i=0;i<n-1;i=i+2)
		{
			if(a[i]>a[i+1])
			{
				a[count++]=a[i];
			}
			else
			{
				a[count++]=a[i+1];
			}
		}
		if(n%2==0)
        	{
            	n=n/2;
        	}	
        	else
        	{
            	a[count++]=a[n-1];
            	n=(n/2)+1;
        	}
	}
	printf("The winner is: %d\n",a[0]);
}

/*OUTPUT:

ubuntu@ubuntu:~$ cd Desktop
ubuntu@ubuntu:~/Desktop$ gcc Tennis.c -o Tennis
ubuntu@ubuntu:~/Desktop$ ./Tennis
Enter the number of players: 20
84 87 78 16 94 36 87 93 50 22 63 28 91 60 64 27 41 27 73 37 
The winner is: 94
*/
