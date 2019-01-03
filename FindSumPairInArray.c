/******************************************************************************

Finding a pair in an array with sum as K
Input : {4,7,3,8,9,5,90,77,56,34,23,58,21,81,66}
        Sum : 12
Output : Pair Found is 4 and 8 
*******************************************************************************/
#include <stdio.h>

void find_pair(int *arr , int x,int size)
{
    int arr2[15] = {0};
    for(int i= 0 ;i<size; i++ )
    {
        if(x > arr[i])
            arr2[x - arr[i]] = arr[i];
        if( (arr2[x-arr[i]] + arr2[arr[i]]) == x )
        {
            //pair found
            printf("Pair found is  %d  & %d", arr2[arr[i]] , x - arr2[arr[i]]);
            return;
        }
    }
    printf("Pair Not Found");
}
int main()
{
    int arr[]= {4,7,3,8,9,5,90,77,56,34,23,58,21,81,66};
    int size = sizeof(arr)/sizeof(arr[0]);
    int x = 12;
    find_pair(arr,x,size);
    printf("size = %d",size);
    return 0;
}
