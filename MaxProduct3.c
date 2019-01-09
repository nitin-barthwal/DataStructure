/******************************************************************************

Maximum Product of 3 elements in an array

*******************************************************************************/
#include <stdio.h>
void arrange(int *max1,int *max2,int *max3)
{
    int a= *max1,b=*max2,c=*max3;
    if(a > b)
       {
           if(b > c)
           { 
               *max1=c;
               *max2=b;
               *max3=a;
           }
           else 
           {  
               if ( a > c )
               {
                   *max1=b;
                   *max2=c;
                   *max3=a; 
               }
               else 
               { 
                   *max1=b;
                   *max2=a;
                   *max3=c; 
               }
           }
       }
    else 
    {
         if(a > c)
           {
               *max1=c;
               *max2=a;
               *max3=b;
           }
           else 
           {
               if ( b < c )
               {
                   *max1=a;
                   *max2=b;
                   *max3=c; 
               }
               else
               {
                   *max1=a;
                   *max2=c;
                   *max3=b; 
               }
           }
    }
}

int maximum(int *arr,int size)
{
    if( size<=2)
        return 0;
    int max1=1;
    int max2=1;
    int max3=1;
    int i=0;
    int neg1=0,neg2=0;
    
    while(i<size)
    {
        if (arr[i] < 0)
        {
            if(neg1==0)
              neg1= arr[i];
            else if(neg2==0)
              { 
                  if(neg1<arr[i])
                    neg2= arr[i];
                  else
                    {
                        neg2= neg1;
                        neg1=arr[i];
                    }
              }
            else
            {
              if (arr[i] < neg1 )
                {
                   neg2=neg1;
                   neg1=arr[i];
                }
              else
              {
                if(arr[i] < neg2)
                       neg2 = arr[i];
              }
            }
        }
        
        if(arr[i] > max1 )
         {   
             max1=arr[i];
             arrange(&max1,&max2,&max3);
             
         }
        i++;
    }
     printf(" %d, %d,     %d  %d %d",neg1,neg2 , max1,max2,max3);
    if(neg1*neg2*max3  > max1*max2*max2)
     return neg1*neg2*max3;
   else
     return max1*max2*max3;
}
int main()
{
    int arr[]= {2,6,4,7,4,-6,-30,-10,5,9,-1,4,0,2,-80};
    printf( "maximum product is :: %d",maximum(arr,16));
    

    return 0;
}





