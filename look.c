#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int getmin(int a[],int tn);
int getmax(int a[],int tn);

void LOOK(int a[],int tt, int tn);

int main()
{
	int i, tt, tn, tracks[10];
	printf("Enter total number of tracks:");
	scanf("%d",&tt);
	
	printf("Enter current head position:");
	scanf("%d",&tracks[0]);
	
	printf("Enter no. of tracks to be visited:");
	scanf("%d",&tn);
	for(i=1;i<=tn;i++)
	{
		scanf("%d",&tracks[i]);		
	}
	
	LOOK(tracks,tn,tt);
	return 0;
}

int getmin(int a[], int tn)
{
	int i,min = INT_MAX;
	for(i=1;i<=tn;i++)
	{
		if(a[i]<min)
		{
			min = a[i];
		}
	}
	
	return min;
}

int getmax(int a[], int tn)
{
	int i,max = INT_MIN;
	for(i=1;i<=tn;i++)
	{
		if(a[i]>max)
		{
			max = a[i];
		}
	}
	
	return max;
}

void LOOK(int a[],int tn,int tt)
{

	int max = getmax(a,tn);
	int min = getmin(a,tn);
	
	if(abs(a[0]-min)<abs(a[0]-max))
	{
		printf("%d",min);
		printf("\n%d",max);
		
		printf("\nLOOK\nTotal head movement is:%d",abs(a[0]-min) + abs(max - min));	
	}
	else
	{
				printf("%d",min);
		printf("\n%d",max);
		printf("\nLOOK\nTotal head movement is:%d",abs(a[0]-max) + abs(max - min));		
	}
}
