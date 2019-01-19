/******************************************************************************

nth fibonacci number
first n fibonacci number
first n even number in ascending order
first n even number in descending order

*******************************************************************************/
#include <stdio.h>

void even_asc(int i,int n)
{  
    if(i > n)
        return;
    if( i % 2 == 0 )
        printf("%d ",i);
    even_asc(i+1,n);
}
void even_dsc(int n)
{  
    if(n <= 0)
        return;
    if(  n % 2 == 0 )
        printf("%d ",n);
    even_dsc(n-1);
}

void fib(int n,int a,int b)
{
    if( n == 0 )
        return;
    printf("%d ",a);
    fib(n-1,b,a+b);
}

void n_fib(int n,int a,int b)
{
    if( n == 0 )
     {   
         printf("%d ",b);
         return;
     }
    n_fib(n-1,b,a+b);
}


int main()
{
    printf("\nfirst n fib numbers :: ");
    //first n fib numbers
    fib(15,0,1);
    printf("\nnth fib num :: ");
    //nth fib num
    n_fib(10,0,1);
   // Print 1 to n even num
   printf("\n1 to n even num ascending order :: ");
   even_asc(2,20);
   printf("\n1 to n even num descending order :: ");
   even_dsc(20);
   // print 1 to n odd num
  // odd(20)
    return 0;
}

