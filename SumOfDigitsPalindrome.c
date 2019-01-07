/******************************************************************************
Write a program to check if the sum of digits of a given number N is a palindrome number or not.

Input:
The first line of the input contains T denoting the number of testcases. T testcases follow. Then each of the T lines contains single positive integer N denoting the value of number.

Output:
For each testcase, in a new line, output "YES" if pallindrome else "NO". (without the quotes)

Constraints:
1 <= T <= 200
1 <= N <= 1000

Example:
Input:
2
56
98
Output:
YES
NO

*******************************************************************************/
#include <stdio.h>
int sum(int N)
{
    if (N==0)
        return 0;
    return N%10 + sum(N/10);
}
int palindrome(int n)
{
    int i;
    char c[5]={0};
    for(i=0;n>0;i++)
        { 
          c[i]=n%10;
          n = n/10;
        }
        i = i-1;
    for(int j =0 ;j<i;j++,i--)
    {    if (c[i]!=c[j])
           return 0;
    }
    return 1;
}

int main() {
 int T,N,i;
scanf("%d",&T);
for(i = 0 ;i<T;i++)
{
    scanf("%d",&N);
    int x = sum(N);
    if(palindrome(x))
        printf("YES\n");
    else
        printf("NO\n");
}
	return 0;
}