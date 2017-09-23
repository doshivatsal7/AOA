#include<stdio.h>
#include<string.h>
#define SIZE 30

int a[SIZE],n;
void getArray();
void display(int a[], int n);
void selection_sort(int a[], int n);
int partition(int a[], int start, int end);
void quick_sort(int a[], int start, int end);
void swap(int i, int j);

int length(int a[]);

int main()
{
	int choice;
	do
	{
		printf("\n*****MAIN MENU*****\n");
		printf("1. Enter array\n");
		printf("2. Selection Sort\n");
		printf("3. Quick Sort\n");
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

			case 2 : selection_sort(a,n);
                           display(a,n);
                           break;

			case 3 : quick_sort(a,0,n-1);
                           printf("Successfully sorted using Quick Sort Algorithm\n");
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
	for(i=0;i<n;i++)
	{
		printf("\t%d",a[i]);
	}
	printf("\n");
}

void selection_sort(int a[], int n)
{
	int imin, i, j, temp;
	for(i=0;i<n;i++)
	{
		imin=i;
		for(j=i+1;j<n;j++)
		{
			if(a[imin]>a[j])
			{
				imin=j;
			}
		}
		temp=a[i];
		a[i]=a[imin];
		a[imin]=temp;
	}
	printf("Successfully sorted using Selection Sort Algorithm\n");
}

void swap(int i, int j)
{
    int temp=a[i];
    a[i]=a[j];
    a[j]=temp;
}

void quick_sort(int a[], int start, int end)
{
    int p;
    if(start<end)
    {
        p=partition(a,start,end);
        quick_sort(a,start,p-1);
        quick_sort(a,p+1,end);
    }
}

int partition(int a[], int start, int end)
{
    int pivot, pindex, i,temp;
    pivot=a[end];
    pindex=start;
    for(i=start;i<=end-1;i++)
    {
        if(a[i]<pivot)
        {
            swap(i,pindex);
            pindex++;
        }
    }
    swap(pindex,end);
    return pindex;
}

/*OUTPUT:

ubuntu@ubuntu:~$ cd Desktop
ubuntu@ubuntu:~/Desktop$ gcc Sort2.c -o Sort2
ubuntu@ubuntu:~/Desktop$ ./Sort2

*****MAIN MENU*****
1. Enter array
2. Selection Sort
3. Quick Sort
4. EXIT
Enter your choice: 1

Enter the number of elements: 7
Enter a value: 30
Enter a value: 50
Enter a value: 40
Enter a value: 10
Enter a value: 70
Enter a value: 60
Enter a value: 20
The Array is: 	30	50	40	10	70	60	20

*****MAIN MENU*****
1. Enter array
2. Selection Sort
3. Quick Sort
4. EXIT
Enter your choice: 2

Successfully sorted using Selection Sort Algorithm
The Array is: 	10	20	30	40	50	60	70

*****MAIN MENU*****
1. Enter array
2. Selection Sort
3. Quick Sort
4. EXIT
Enter your choice: 1

Enter the number of elements: 8
Enter a value: 136
Enter a value: 32
Enter a value: 75
Enter a value: 23
Enter a value: 97
Enter a value: 21
Enter a value: 65
Enter a value: 26
The Array is: 	136	32	75	23	97	21	65	26

*****MAIN MENU*****
1. Enter array
2. Selection Sort
3. Quick Sort
4. EXIT
Enter your choice: 3

Successfully sorted using Quick Sort Algorithm
The Array is: 	21	23	26	32	65	75	97	136

*****MAIN MENU*****
1. Enter array
2. Selection Sort
3. Quick Sort
4. EXIT
Enter your choice: 4

*/
