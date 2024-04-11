#include <stdio.h>
#include <stdlib.h>

int main()
{
	int max[10][10], allocated[10][10], need[10][10], available[10], safe_sequence[10];
	int i,j,p,r,process,count;
	
	printf("enter the no. of process:");
	scanf("%d",&p);
	
	printf("enter the no. of resources:");
	scanf("%d",&r);
	
	printf("enter maximum resources for each process:\n");
	for(i=0;i<p;i++)
	{
		printf("For process %d:",i+1);
		for(j=0;j<r;j++)
		{
			scanf("%d",&max[i][j]);
		}
	}
	
	printf("enter allocated resources for each process:\n");
	for(i=0;i<p;i++)
	{
		printf("For process %d:",i+1);
		for(j=0;j<r;j++)
		{
			scanf("%d",&allocated[i][j]);
		}
	}
	
	printf("enter available resource:");
	for (i=0;i<r;i++)
	{
		scanf("%d",&available[i]);
	}
	
	//calculating need
	for(i=0;i<p;i++)
	{
		for(j=0;j<r;j++)
		{
			need[i][j] = max[i][j] - allocated[i][j];
		}
	}
	
	int executed[10]={0};
	do
	{
		// printing max and alloc
		printf("\nMax:\t\tAllocated:\n");
		for(i=0;i<p;i++)
		{
			for(j=0;j<r;j++)
			{
				printf("%d ",max[i][j]);
			}
			printf("\t");
			for(j=0;j<r;j++)
			{
				printf("%d ",allocated[i][j]);
			}
			printf("\n");
		}
		
		process = -1;
		for(i=0;i<p;i++)
		{
			if(executed[i]==0)
			{
				process = i;
				for(j=0;j<r;j++)
				{
					if (need[i][j] > available[j])
						{
							process = -1;
							break;						
						}
				}
			}
			if (process != -1)
			{
				break;
			}
		}
		if (process != -1)
		{
			printf("\nProcess %d proceeds to completion",process+1);
			safe_sequence[count] = process + 1;
			count++;
			executed[process] = 1;
			for(j = 0;j < r;j++)
			{
				available[j] += allocated[process][j];
				allocated[process][j] = 0;
				max[process][j] = 0;
				//executed[process] = 1;
			}
		}
		
	}
	while(count!=p && process!= -1);
	if (count==p)
	{
		
		printf("\n System is safe");
		printf("\nSafe sequence is:");
		for (i=0;i<p;i++)
		{
			printf("%d ",safe_sequence[i]);
		}
		
	}
	else
	{
		printf("\nThe system is in an unsafe state!!");
	}	
	return 0;
}
