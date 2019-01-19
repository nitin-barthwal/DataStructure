/******************************************************************************
Program to print all substrings of a given string
*******************************************************************************/
#include <stdio.h>
#include<string.h>

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
int main ()
{
  char *str = "abcd";
  print_substring2(str);
  
  char *str2="nitin";
  print_substring2(str2);
  return 0;
}

