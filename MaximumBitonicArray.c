/*********************************
 * Maximum value in a bitonic array
 * Given an array of elements which is first increasing and then decreasing, find the maximum element in the array.

Input:
The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is N, the size of array, the second line of each test case contains N integers which are the array elements.

Output:
Print the maximum element in the array.

Constraints:
1 ≤ T ≤ 50
3 ≤ N ≤ 100
1 ≤ Ai ≤ 106

Example:
Input:
2
9
1 15 25 45 42 21 17 12 11
5
1 45 47 50 5

Output:
45
50
 * *******************************/
#include <stdio.h>

int findMax(int *arr, int start , int end)
{   int mid = (start+end)/2;
    if(start+1 == end)
       return arr[end];
    if(arr[mid] > arr[mid-1])
      start = mid;
    else 
       end =mid;
    return findMax(arr,start,end);
    // 1 15 25 45 42 21 17 12 11  ans 45
}
int main() {
	int N,T;
	scanf("%d",&T);
	for(int i = 0; i<T;i++)
	{
	    scanf("%d",&N);
	    int arr[N];
	    for(int j = 0 ;j<N;j++)
	        scanf("%d",&arr[j]);
	    printf("%d\n",findMax(arr, 0 , N-1));
	}
	return 0;
}