/******************************************************************************

1. Find an element is a sorted array. (Binary Search)
    int arr[] = { 1,  2, 3,  5, 6,8, 10 ,12, 33 }; 
  Output:: binary Search result for Element 8 is :: 1 ( 0 = Not Found,1 = Found)
  
2. Find the missing number in sorted array of integers recursively . (Binary Search)
    int arr2[] = { 6,7,8, 10 ,11,12,13,14,15 };
 Output:: Missing num is :: 9  

3. Find missing number non recursively in a sorted array ( Binary Search) 
    int arr2[] = { 6,7,8, 10 ,11,12,13,14,15 };
 Output:: (Non Recursively) Missing num is :: 9  

4. Find frequency of a number in a sorted array using Binary Search
    int arr3[] = { 6,6,8, 8 ,8,12,14,14,15 }; 
 Output:: Frequency of 8 is :: 3
 
*******************************************************************************/
#include <stdio.h>
int binSearch(int *arr,int size, int key)
{
    int mid=0,start=0,end=size-1;
    while(start+1!=end)
    {
        mid = (start + end)/2;
        if(arr[start] == key || arr[mid] == key || arr[end] == key )
        {   //key found
            return 1;
        }
        if(arr[mid] < key )
        {  start = mid; 
        }
        else
        {  end = mid; 
        }
    }
    return 0;  //not found
}


// Recusrsive Binary Search
int findMissingUsingBinSearch(int *arr2,int start,int end)
{  //arr2[] = { 6,7,8, 10 ,11,12,13,14,15 }
      int mid;
      if(start +1 == end)
        return arr2[start]+1;
      mid = (start+end)/2;
      if( arr2[mid] != arr2[start] + mid -start)
        findMissingUsingBinSearch(arr2,start,mid);
      else
        findMissingUsingBinSearch(arr2,mid,end);
    return ;  
}

// Non Recursive Binary search
int findMissing(int *arr2,int size)
{  //arr2[] = { 6,7,8, 10 ,11,12,13,14,15 }
      int mid=0,start=0,end=size-1;
    while(start+1!=end)
    {
        mid = (start + end)/2;
        if(arr2[mid] != arr2[start] + mid - start)
           end = mid;
        else
          start = mid; 
    }
    return arr2[start]+1;  
}

// Find Frequency of  a number in an array
int findFrequency(int *arr,int size,int key)
{ // arr3[] = { 6,6,8, 8 ,8,12,14,14,15 }
    int mid=0,start=0,end=size-1,loc=-1,freq =0;
    while(start+1!=end)
    {
        mid = (start + end)/2;
        if(arr[start] == key  )
        {  loc =start; 
           break;
        }
        else if(arr[mid] == key   )
        {   loc =mid;
             break;
        }
        else if( arr[end] == key )
        {   loc =end;
            break;
        }
        
        if(arr[mid] < key)
           end = mid;
        else
          start = mid; 
    }
    if(loc == -1)
        return 0; // Item not found.
    // got location
    start = loc-1;
    end=loc+1;
    int count =1;
    while(arr[start] == arr[loc])
    {
        count++;
        start--;
    }
    while(arr[end] == arr[loc])
    {
        count++;
        end++;
    }
    return count;  
}
int main() 
{  int key= 9;
    int arr[] = { 1,  2, 3,  5, 6,8, 10 ,12, 33 }; 
    int arr2[] = { 6,7,8, 10 ,11,12,13,14,15 };
    int arr3[] = { 6,6,8, 8 ,8,12,14,14,15 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
  
    printf("binary search result for Element %d is  ::   %d ( 0 = Not Found, 1 = Found)" ,key, binSearch(arr, n,key) );
    n = sizeof(arr2) / sizeof(arr2[0]); 
    printf("\nmissing num is   ::   %d" , findMissingUsingBinSearch(arr2, 0,n) );
    printf("\n(Non Recursively) missing num is   ::   %d" , findMissing(arr2,n) );
    n = sizeof(arr3) / sizeof(arr3[0]); 
    printf("\n frequency of %d is ::   %d" , key,findFrequency(arr3, n,key) );
    return 0; 
} 

