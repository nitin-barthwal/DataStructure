/******************************************************************************

 Circular shift of k position in an Array

*******************************************************************************/
#include <stdio.h>
#define SIZE 10

void show(int *arr)
{
    for(int i = 0 ;i<SIZE;i++)
       printf("%d  ",arr[i]);
}
int main()
{
   int arr[SIZE] = {0,1,2,3,4,5,6,7,8,9};
   int jump = -1,shift=0;
   int count = 0,temp,val;
   if( jump == SIZE || jump == 0)
    { show(arr);
      return 1;
     }
    else if(jump < 0)
    {   jump = (jump*-1)%SIZE;
        jump = SIZE - jump;
    }
    else if(jump > SIZE)
     jump = jump - SIZE;
    val = arr[0];
    int pos = 0,i=jump;
   while(shift < SIZE)
   {
        temp = arr[(i)%SIZE];
        arr[(i)%SIZE] = val;
        val = temp ;
        shift++;
        if( pos == i )
         {   
             pos = (pos+1)%SIZE;
             i  = (i+1+jump)%SIZE;
             val = arr[pos];
         }
        else
         i = (i+jump)%SIZE;
   }
   show(arr);
    return 0;
}
