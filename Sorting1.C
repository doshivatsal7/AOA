#include<stdio.h>
#include<string.h>
#define SIZE 30

int a[SIZE],n;
void getArray();
void display(int a[], int n);
void insertion_sort(int a[], int n);
void merge_sort(int a[]);
void merge(int l[], int r[], int a[]);
int length(int a[]);

int main()
{
	int choice;
	do
	{
		printf("\n*****MAIN MENU*****\n");
		printf("1. Enter array\n");
		printf("2. Insertion Sort\n");
		printf("3. Merge Sort\n");
        	printf("4. EXIT\n");
		printf("Enter your choice: ");
		scanf("%d",&choice);
		printf("\n");
		switch(choice)
		{
			case 1 : memset(a,0,SIZE*sizeof(int));
                     	   getArray();
                           display(a,n);
                           break;

			case 2 : insertion_sort(a,n);
                           display(a,n);
                           break;

			case 3 : merge_sort(a);
                           printf("Successfully sorted using Merge Sort Algorithm\n");
                           display(a,n);
                           break;

            case 4 : break;
		}
	}while(choice!=4);
	return 0;
}

void getArray()
{
	int i;
	printf("Enter the number of elements: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter a value: ");
scanf("%d",&a[i]);
	}
}

void display(int a[],int n)
{
	int i;
	printf("The Array is: ");
	for(i=0;i<length(a);i++)
	{
		printf("\t%d",a[i]);
	}
	printf("\n");
}

void insertion_sort(int a[], int n)
{
	int key,i,j;
	for(j=1;i<n;i++)
	{
		key=a[j];
		i=j-1;

		while(a[i]>key && i!=0)
		{
			a[i+1]=a[i];
			i=i-1;
		}
		a[i+1]=key;
	}
	printf("Successfully sorted using Insertion Sort Algorithm\n");
}

int length(int a[])
{
	int i=0;
	while(a[i]!='\0')
	{
		i++;
	}
	return i;
}

void merge_sort(int a[])
{
	int i,len=0,l[SIZE]={0},r[SIZE]={0},mid;
	len=length(a);
	if(len>1)
	{
		mid=(len-1)/2;

		for(i=0;i<=mid;i++)
		{
			l[i]=a[i];
		}
		for(i=mid+1;i<len;i++)
		{
			r[i-mid-1]=a[i];
		}

		merge_sort(l);
		merge_sort(r);
		merge(l,r,a);
	}
	else
		return ;
}

void merge(int l[], int r[], int a[])
{
     int i=0,j=0,k=0;
     while(i<length(l) && j<length(r))
     {
        if(l[i]<r[j])
        {
            a[k]=l[i];
            i++;
            k++;
        }

        else
        {
            a[k]=r[j];
            k++;
            j++;
        }
     }

     while(i<length(l))
     {
        a[k]=l[i];
        i++;
        k++;
     }

     while(j<length(r))
     {
        a[k]=r[j];
        j++;
        k++;
     }
}
	
/*
ubuntu@ubuntu:~$ cd Desktop
ubuntu@ubuntu:~/Desktop$ gcc Sort1.c -o Sort1
ubuntu@ubuntu:~/Desktop$ ./Sort1

*****MAIN MENU*****
1. Enter array
2. Insertion Sort
3. Merge Sort
4. EXIT
Enter your choice: 1

Enter the number of elements: 7
Enter a value: 30
Enter a value: 50
Enter a value: 40
Enter a value: 20
Enter a value: 70
Enter a value: 10
Enter a value: 60
The Array is: 	30	50	40	20	70	10	60

*****MAIN MENU*****
1. Enter array
2. Insertion Sort
3. Merge Sort
4. EXIT
Enter your choice: 2

Successfully sorted using Insertion Sort Algorithm
The Array is: 	10	20	30	40	50	60	70

*****MAIN MENU*****
1. Enter array
2. Insertion Sort
3. Merge Sort
4. EXIT
Enter your choice: 1

Enter the number of elements: 5
Enter a value: 5
Enter a value: 4
Enter a value: 3
Enter a value: 2
Enter a value: 1
The Array is: 	5	4	3	2	1

*****MAIN MENU*****
1. Enter array
2. Insertion Sort
3. Merge Sort
4. EXIT
Enter your choice: 3

Successfully sorted using Merge Sort Algorithm
The Array is: 	1	2	3	4	5

*****MAIN MENU*****
1. Enter array
2. Insertion Sort
3. Merge Sort
4. EXIT
Enter your choice: 4

*/