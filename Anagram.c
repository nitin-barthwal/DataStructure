/******************************************************************************
Check whether two strings are anagram of each other
*******************************************************************************/
#include <stdio.h>
#include<string.h>
int check_anagram(char *str,char* str2)
{
    int len1 = strlen(str);
    int len2 = strlen(str2);
    int i=0;
    if(len1 != len2)
        return 0 ;

    int arr[26]={0};
    while(i<len1)
    {
        arr[str[i]-'A'] += 1;
        arr[str2[i]-'A'] -= 1;
        i++;
    }
    for(i=0;i<26;i++)
        if(arr[i] !=0 )
            return 0;
    return 1;
}

int main()
{
    char *str = "SILENT";
    char *str2 = "LISTEN";
    printf("%s & %s anagram or not, (0 = Not anagram, 1 = Anagram )  :: %d",str,str2,check_anagram(str,str2));
    
    return 0;
}

