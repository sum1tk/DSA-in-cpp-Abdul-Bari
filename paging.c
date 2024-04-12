#include <stdio.h>
#include <stdlib.h>
int main()
 {
int total_memory=0,frame_size=0,frame_occupied,fmax;
int page_table[100];
int i,vm,pm;
    char ans='y';
printf("Enter size of physical memory:");
scanf("%d",&total_memory);
printf("Enter the size of frame");
scanf("%d",&frame_size);
printf("enter the no.of frames occupied");
scanf("%d",&frame_occupied);
fmax=total_memory/frame_size;
    if(frame_occupied>fmax)
    {
printf("memory thrash");
        return;
    }
printf("Enter the frames used by pages(less than %d):",fmax);
    for(i=0;i<frame_occupied;i++)
    {
scanf("%d",&page_table[i]);
    }
printf("Virtual memory locations available are 0 to %d\n",frame_size*frame_occupied);
    while(ans=='y')
    {
int r;
printf("Enter the virtual memory address:");
scanf("%d",&vm);
        if(vm>=frame_size*frame_occupied)
        {
printf("Invalid address!!!\n");
        }
        else
        {
            r=vm/frame_size;
            pm=page_table[r]*frame_size+vm%frame_size;
printf("Physical Address is %d",pm);
        }
printf("\nEnter more(y/n)?");
fflush(stdin);
scanf("%c",&ans);
    }
    return 0;
}

