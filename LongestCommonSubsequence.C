#include<stdio.h>
#include<string.h>

int i,j,m,n,a,c[20][20];
char x[15],y[15],b[20][20];
void print_lcs(int i,int j);
void lcs_length(void);

void main()
{
	printf("Enter 1st sequence : ");
	scanf("%s",x);
	printf("Enter 2nd sequence : ");
	scanf("%s",y);
	lcs_length();
	printf("\n");
}

void print_lcs(int i,int j)
{
	if(i==0 || j==0)
		return;
	if(b[i][j]=='c')
	{
		print_lcs(i-1,j-1);
		printf(" %c",x[i-1]);
	}
	else if(b[i][j]=='u')
		print_lcs(i-1,j);
	else
		print_lcs(i,j-1);
}

void lcs_length(void)
{
	m=strlen(x);
	n=strlen(y);
	for(i=0;i <= m;i++)
		c[i][0]=0;                                
	
	for(i=0;i  <= n;i++)
	{
		printf("0 \t");
		c[0][i]=0;
	}
	printf("\n");
	for(i=1;i <= m;i++)
	{
		printf("0 \t");         
		for(j=1;j <= n;j++)
		{
			if(x[i-1]==y[j-1])
			{
				c[i][j]=1+c[i-1][j-1];
				b[i][j]='c';
				printf("%d C\t",c[i][j]);
			}
			else if(c[i-1][j] >= c[i][j-1])
			{
				c[i][j]=c[i-1][j];
				b[i][j]='u';
				printf("%d U\t",c[i][j]);
			}
			else
			{
				c[i][j]=c[i][j-1];
				b[i][j]='l';
				printf("%d L\t",c[i][j]);
			}
		}
		printf(" \n");  
	}
	printf("\nLongest common subsequence is :");
	print_lcs(m,n);
	printf("\n");
	printf("The length of Subsequence is: %d",c[m][n]);
}
/*
OUTPUT:
			
student@student-HP-ProOne-400-G1-AiO:~$ cd Desktop
student@student-HP-ProOne-400-G1-AiO:~/Desktop$ cd Vatsal
student@student-HP-ProOne-400-G1-AiO:~/Desktop/Vatsal$ gcc LCS.c -o LCS
student@student-HP-ProOne-400-G1-AiO:~/Desktop/Vatsal$ ./LCS


Enter 1st sequence : 1000101011
Enter 2nd sequence : 00011101
0 	0 	0 	0 	0 	0 	0 	0 	0 	
0 	0 U	0 U	0 U	1 D	1 D	1 D	1 L	1 D	 
0 	1 D	1 D	1 D	1 U	1 U	1 U	2 D	2 L	 
0 	1 D	2 D	2 D	2 L	2 L	2 L	2 D	2 U	 
0 	1 D	2 D	3 D	3 L	3 L	3 L	3 D	3 L	 
0 	1 U	2 U	3 U	4 D	4 D	4 D	4 L	4 D	 
0 	1 D	2 D	3 D	4 U	4 U	4 U	5 D	5 L	 
0 	1 U	2 U	3 U	4 D	5 D	5 D	5 U	6 D	 
0 	1 D	2 D	3 D	4 U	5 U	5 U	6 D	6 U	 
0 	1 U	2 U	3 U	4 D	5 D	6 D	6 U	7 D	 
0 	1 U	2 U	3 U	4 D	5 D	6 D	6 U	7 D	 

Longest common subsequence is : 0 0 0 1 1 0 1
The length of Subsequence is: 7


*/