int winner(int c[],int start,int end);
void main()
{
	int a[100],n,w,i;
	printf("Enter the number of players: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		a[i]=rand()%100+1;
		printf("%d ",a[i]);
	}
	printf("\n");
	w=winner(a,0,n-1);
	printf("The winner is: %d\n",w);
}

int winner(int c[],int start,int end)
{
	int w1,w2,mid;
	if(start==end)
	{
		return c[start];
	}
	else if(start==end-1)
	{
		if(c[start]>c[end])
			return c[start];
		else
			return c[end];
	}
	else
	{
		mid=(start+end)/2;
		w1=winner(c,start,mid);
		w2=winner(c,mid+1,end);
		if(w1>w2)
			return w1;
		else
			return w2;
	}
}

/*OUTPUT:

ubuntu@ubuntu:~$ cd Desktop
ubuntu@ubuntu:~/Desktop$ gcc Tennis.c -o Tennis
ubuntu@ubuntu:~/Desktop$ ./Tennis
Enter the number of players: 7
84 87 78 16 94 36 87 
The winner is: 94

*/