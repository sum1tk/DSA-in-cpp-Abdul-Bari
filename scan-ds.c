#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int getmin(int a[],int tn);
int getmax(int a[],int tn);

void SCAN(int a[],int tt, int tn);

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
	
	SCAN(tracks,tt,tn);
	return 0;
}

void SCAN(int a[],int tt, int tn)
{
	
	if(tt-a[0]>a[0])		// if distance to 0 track is lesser 
	{
		int max = getmax(a,tn);
		printf("\nSCAN\nTotal head moment is:%d",a[0]+max);
	}
	else
	{
		int min = getmin(a,tn);
		printf("\nSCAN\nTotal head moment is:%d",tt - a[0] + tt - min);
	}
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
