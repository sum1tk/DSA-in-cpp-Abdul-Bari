#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void SSTN(int a[],int tn);

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
    // int tracks[] = {100, 30, 50, 10, 20}; // Example array of tracks
    // int num_tracks = sizeof(tracks) / sizeof(tracks[0]);
    // SSTN(tracks, num_tracks);
    SSTN(tracks,tn);
    return 0;
    
}

void SSTN(int a[], int tn)
{
    int i,j;                    // initialise loop variables
    int visited[20] = {0};      //
    int current = 0;            // current head index

    int trks = 0; // Initialize trks (will keep track of seek time)
    printf("%d", a[current]); // Print initial track

    int minseek = INT_MAX;    //min seek time initialised to a very large number
    int next;                 //the next track index 
    for(i=1; i<=tn; i++)        // will loop track times 
    {
        minseek = INT_MAX;
        next = 0;
        for(j=1; j<=tn; j++)
        {
            if (visited[j]==0 && (minseek > abs(a[current] - a[j])))
            {
                minseek = abs(a[current] - a[j]);
                next = j;
            }
        }
        
        visited[next] = 1;
        current = next;
        trks += minseek;
        printf("->%d",a[current]);
    }
    printf("\ntotal seek time:%d",trks);
    
}