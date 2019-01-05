/******************************************************************************

Remove certain characters from a string and split it in a defined pattern  
 Input : s[] = "hello$%3^23#4& f43   yo90"
 Output : hel lo3 234 f43 yo 90
*******************************************************************************/
#include <stdio.h>

void split(char* str)
{
    int len = strlen(str);
    int i =0,j=0;
    char str2[25];
    while(i< len)
    {
        if( (str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= '0' && str[i] <= '9') )
        { // valid character
        if(j%4==0)
          {
            str2[j] = ' ';
            j++;
          }
         str2[j] = str[i];
         j++;
        }
        i++;
    }
    str2[j]='\0';
    if (str2[j-2] == ' ')
     {
         char temp = str2[j-2];
         str2[j-2] = str2[j-3];
         str2[j-3] = temp;
     }
     printf("\n updated string is %s",str2);
}
int main()
{
    char s[] = "hello$%3^23#4& f43   yo90";
    split(s);
    return 0;
}
