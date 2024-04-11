#include <stdio.h>
#include <stdlib.h>

void FCFS(int a[],int tn);

int main()
{
    int tracks[20], tn, i;
    
    printf("Enter the no. of tracks:");
    scanf("%d", &tn);

    printf("Enter the current position of head:");
    scanf("%d", &tracks[0]);

    printf("Enter tracks:\n");

    for (i=1;i<=tn;i++)
    {
        scanf("%d",&tracks[i]);
    }

    FCFS(tracks,tn);
}

void FCFS(int a[],int tn)
{
    int trks = 0;
    printf("Track order\n");
    for(int i = 1;i<=tn;i++)
    {
        printf("->%d",a[i]);
        trks += abs(a[i]-a[i-1]);

    }
    printf("\nTotal tracks covered:%d", trks);
}

