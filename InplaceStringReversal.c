/******************************************************************************

Inplace string reversal
Input :: Practice makes Perfect
Output :: Perfect makes Practice
*******************************************************************************/
#include <stdio.h>

// Count No of words
int countword (char* s )
{
    int count=0,i=0;
    
    while(s[i]!='\0') // traverse till the end of string
     {  if(s[i] == ' ')
            count++;   // ifspace is found increment the word count
        i++;
     }
   return (count+1);
}

// Function to do inplace reversal of the string
void reverse(char* s,int len)
{
    
    int i = 0, j = len-1;
    int temp,count;
    // Reverse complete string including words
    while(i<=j)
    {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i++;
        j--;
    }
    i=0;
    j=0;
    //count no of words in the string
    count = countword(s);
    
    // reverse words in the list
    while( count )
    { // when a complete word is encountered  ( j :: starting location of the word, i :: ending location of the word)
        if(s[i] ==' ' || s[i] == '\0')  
        {
            int q = i-1;
            int p = j;
            for(;p < q ; p++,q--) // Swap the word
               {
                 temp = s[p];
                 s[p] = s[q];
                 s[q] = temp;
                }
            j = i+1;
            count--; // reduce the word count
        }
        i++;
    }
   
}
int main()
{
   char str[] = "practise makes Perfect";
   printf("\n strint is %s",str);
   int len = strlen(str);
   reverse(str,len);
   printf("\n After Reversal string is  :: %s ",str);

    return 0;
}
