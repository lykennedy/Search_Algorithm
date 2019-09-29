#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void sort(int *n,int j )
{
    printf("Doing the bubble sort... This may take a while...\n");
    clock_t t;
    t = clock();
    int ph,fh,i; /* Placeholders and counters */
    int counter = 1; /*Counter is to check if the list was successfully bubble sorted. */
    while (counter != 0) /* Only breaks if bubble sort is done */
    {
        counter = 0;
        for(i=0;i<j;i++)
        {
            ph = n[i];
            fh = n[i + 1];

            if (n[i] > n[i + 1]) /* Comparing adjacent numbers */
            {
                if (i == (j-1)) /* When we reach the last iteration loop through the array again.*/
                {
                    continue;
                }
                n[i] = fh; /* Switching if the ith iteration is bigger than the next iteration.*/
                n[i+1] = ph;
                counter += 1;
            }

        }
    }
    t = clock() - t;
    double time_elapsed = (double)(t)/CLOCKS_PER_SEC;

    //for(i=0;i<j;i++) /* Printing out the sorted array.*/
    //{
    //    printf("%d\n", n[i]);
    //}

    printf("It took %f seconds to complete the bubble sort\n", time_elapsed);

}

void searching(int *n, int j, int target)
{
    int mid, start, end;
    start = 0; //Corresponds to the first element of the lower array or upper array.
    end = j-1; //Corresponds to the last element of the lower array or upper array.
    mid = j/2; //Middle of the array.

    while(start <= end)
    {
        if(target > n[mid])
        {
            start = mid + 1; //Means we don't care about the lower half of the array.
        }
        else if(target == n[mid]) //Target value was found.
        {
            printf("%d was found at index %d\n",target, mid);
            break; //Break out of the loop.
        }
        else
        {
            end = mid - 1; //Means that the array is in the lower half of the array, disregard the upper half of the array.
        }
        mid = (start + end)/2; //Updating the middle.
    }

    if(start > end)
    {
        printf("%d was not found in the array\n", target);
    }

}

int main()
{
    int *n, j,i,mid;
    srand((double)time(NULL) * getpid());
    int target;
    printf("What number are you looking for?\n");
    scanf("%d",&target);
    //j = rand() % 10000; //Generating j elements
    j = 100;
    n = (int*)calloc(j,sizeof(int)); //Will be the array we sort and search through.

    for(i=0;i<j;i++) //Populating the n array.
    {
        n[i] = ((rand() % 500) + (rand() % 500));
    }
    n[j-1] = 911;

    sort(n,j);
    for(i=0;i<j;i++)
    {
        printf("n[%d] = %d\n", i,n[i]);
    }
    searching(n,j,target);

    free(n);
    printf("%d elements\n",j);

    return 0;
}
