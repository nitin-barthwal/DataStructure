/******************************************************************************
Program to print all substrings of a given string
a. O(n3)  3 loops
b. O(n2)  2 loops

Count Number of substrings of a string

Sum of all substrings of a string representing a number
Input  : num = “1234”
Output : 1670
Sum = 1 + 2 + 3 + 4 + 12 + 23 + 34 + 123 + 234 + 1234  = 1670

*******************************************************************************/
#include <stdio.h>
#include<string.h>
#include<math.h>

void print_substring(char *str)
{
    int len = strlen(str);
    int i,j,k;
  for( i = 0;i < len;i++)
  { 
      for( j = len-1 ;j>=i ;j--)
      {
        for( k =i;k<=j  ;k++)
          printf("%c",str[k]);
        printf("\n");
      }
    }
}

void print_substring2(char *str)
{
    int len = strlen(str);
    int i,j,k;
    char str2[len];
  for( i = 0;i < len;i++)
  {   
      for( j = i,k=0 ;j<len ;j++,k++)
      {
          printf("\n");
          str2[k]=str[j];
          str2[k+1]='\0';
          printf("%s",str2);
      }
    }
}


void count_substring(char *str)
{
    int len = strlen(str);
    int i,j,k,count=0;
    char str2[len];
  for( i = 0;i < len;i++)
  {   
      for( j = i,k=0 ;j<len ;j++,k++)
      {
          count++;
      }
    }
    printf("\n No of substring in %s are :: %d",str,count);
}


void substring_sum(int num)
{
    int len,p,sum=0,n=num;
    // get lenth of num
    for( len=0;num>0;num=num/10,len++) ;
    num=n;
    int i,j,k,temp=0;
    int arr[len];
    //copy num in array
  for(i = len-1; i>=0;i--)
   {  arr[i] = num%10;
      num = num/10;
   }
   
  for( i = 0;i < len;i++)
  {   
      for( j = len-1 ;j>=0 ;j--)
      {
          for( k = i ,p=j-i; k<=j; k++,p-- )
          {
              temp = temp + arr[k] * pow(10,p);
          }
          sum = sum + temp;
          temp =0;
      }
    }
    printf("sum = %d",sum);
}

int main ()
{
  char *str = "abcd";
  //print_substring2(str);
  
  char *str2="nitin";
  //print_substring2(str2);
  
  char *str3="hello";
  //count_substring(str3);
  
  int num = 123;
  substring_sum(num);
  num = 1234;
  substring_sum(num);
  num = 13;
  substring_sum(num);
  num = 7;
  substring_sum(num);
  return 0;
}


