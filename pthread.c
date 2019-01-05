/******************************************************************************

Sum of an aray using Pthreads

*******************************************************************************/
#include <stdio.h>
#include<pthread.h>
# define THREAD_COUNT 4  // No of threads to create
#define MAX 16 // no of elements in array
int sum[THREAD_COUNT] = {0};
int part = 0;
int arr[] = {2,4,5,7,3,5,9,3,5,7,8,2,3,6,3,1};

void* sum(void *arg)
{
    int index = part;
    for(int i = index*THREAD_COUNT ;i< index *4 ;i++)
        sum[index] += arr[i];
}
int main()
{
   
    pthread_t tid[THREAD_COUNT];
    int i =0,ans =0;
    for(i = 0 ; i<THREAD_COUNT;i++)
        pthread_create(&tid[i],NULL,sum,NULL);
    for( i=0;i<THREAD_COUNT;i++)
        pthread_join(tid[i],NULL);
    for(i=0;i<THREAD_COUNT;i++)
        ans += sum[i];
    printf(" Sum of array is %d",ans);
    return 0;
}

