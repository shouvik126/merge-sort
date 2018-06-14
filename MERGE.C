#include<stdio.h>
#include<conio.h>
int ar[20];
void merge(int low ,int mid,int high)
{
	int i=low,j=mid+1,k=0,b[20];
	while(i<=mid &&j<=high)
	{
		if(ar[i]<ar[j])
		{
			b[k++]=ar[i++];
		}
		else
		{
			b[k++]=ar[j++] ;
		}
	}
	for(;i<=mid;i++)
		b[k++]=ar[i];
	for(;j<=high;j++)
		b[k++]=ar[j];
	for(i=low,k=0;i<=high;i++,k++)
	{
		ar[i]=b[k] ;
	}
}
void mergesort(int low,int high)
{
	if(low<high)
	{
		int mid=(low+high)/2;
		mergesort(low,mid);
		mergesort(mid+1,high);
		merge(low,mid,high);
	}
}
void main()
{
	int n,i,j;
	clrscr();
	printf("\nEnter how many no you want to enter:=");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("A[%d]:=",i+1);
		scanf("%d",&ar[i]);
	}
	clrscr();
	printf("\nBefore sorting:=\n");
	for(j=0;j<n;j++)
	{
		printf("%d,",ar[j]);
	}
	mergesort(0,n-1);
	printf("\nAfter sorting:=\n");
	for(j=0;j<n;j++)
	{
		printf("%d,",ar[j]);
	}
	getch();
}