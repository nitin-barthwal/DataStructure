/******************************************************************************
Print a given matrix in spiral form
Input:
        1    2   3   4
        5    6   7   8
        9   10  11  12
        13  14  15  16
Output: 
1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10 

Input:
        1   2   3   4  5   6
        7   8   9  10  11  12
        13  14  15 16  17  18
Output: 
1 2 3 4 5 6 12 18 17 16 15 14 13 7 8 9 10 11
*******************************************************************************/
#include <stdio.h>
#define M 4
#define N 4
void spiral_matrix(int arr[M][N],int size)
{
    int count=0,i,j,k,l,c=0;
    while(c<size)
    {
        //Right
        for(i=count;i<N;i++)
        { 
            if(arr[count][i] != 0)
              {   printf("%d ",arr[count][i]);
                arr[count][i] = 0;
                c++;
              }
           
        }
        if(count>=size) break;
        //Down
        for(i=count;i<M;i++)
        { 
            if(arr[i][N-count-1] != 0)
              {  printf("%d ",arr[i][N-count-1]);
                 arr[i][N-count-1] = 0;
                 c++;
              }
            
        }
        if(count>=size) break;
        //Left
        for(i=N-1;i>=count;i--)
        { 
            if(arr[M-count-1][i] != 0)
              {   printf("%d ",arr[M-count-1][i]);
                arr[M-count-1][i] = 0;
                c++;
              }
            
        }
        if(count>=size) break;
        //Up
        for(i=M-1;i>=count;i--)
        { 
            if(arr[i][count] != 0)
              {  printf("%d ",arr[i][count]);
                 arr[i][count] = 0;
                 c++;
              }
         
        }
        count++;
    }
}   
// 1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10 
int main() {
	int arr[M][N] = {{ 1,2,3,4},{5, 6, 7, 8},{9, 10,11, 12},{13,  14,  15,  16}};
	
	for (int i = 0 ;i<4;i++)
	{
	    for(int j=0;j<4;j++)
	        printf("%d " ,arr[i][j] );
	    printf("\n");
	}
/*	int arr[M][N] = {{ 1,2,3,4,5,6},{7, 8,9,10,11,12},{13,  14,  15,  16,17,18}};
*/
	spiral_matrix(arr, M*N);
		return 0;
}

