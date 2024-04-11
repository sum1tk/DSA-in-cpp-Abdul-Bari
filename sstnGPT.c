#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void SSTN(int a[], int tn)
{
    int visited[20] = {0};
    int current = a[0];
    int trks = 0; 
    printf("%d", current); 

    for(int i = 1; i <= tn; i++)
    {
        int minseek = INT_MAX;
        int next = 0;
        for(int j = 1; j <= tn; j++) 
        {
            if (visited[j] == 0 && minseek > abs(current - a[j])) 
            {
                minseek = abs(current - a[j]);
                next = j;
            }
        }
        visited[next] = 1;
        current = a[next]; 
        trks += minseek;
        printf("->%d", current);
    }
}

int main() {

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

    SSTN(tracks,tn);

    // int tracks[] = {50, 1, 53, 47, 70}; // Example array of tracks
    // int num_tracks = sizeof(tracks) / sizeof(tracks[0]);
    // SSTN(tracks, num_tracks);
    return 0;
}
