/******************************************************************************

Finding a pair in an array with sum as K
Input : {3,5,6,7,10,12,20,21,81,66}
        Sum : 13
Output : Pair Found is 3 and 10
*******************************************************************************/
#include <stdio.h>

void find_pair(int *arr , int x,int size)
{
    int loc=size-1;
    int sum;
    if(loc == -1)
    {//  int arr[]= {3,5,6,7,10,12,20,21,81,66};
        printf("pair cant be found");
        return;
    }
    int j = loc;
    for(int i= 0 ; i<j ;  )
    {
        sum = arr[i]+arr[j];
        if( sum == x)
           {
            printf("Pair found is  %d  & %d", arr[i],arr[j]);  //pair found
            return;
            }
        if( sum > x )
         j--;
        else
         i++;
    }
    printf("Pair Not Found");
}
int main()
{
    int arr[]= {3,5,6,7,10,12,20,21,81,66};
    int size = sizeof(arr)/sizeof(arr[0]);
    int x = 13;
    find_pair(arr,x,size);
    return 0;
}
