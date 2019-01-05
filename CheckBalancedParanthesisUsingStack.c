/******************************************************************************

 Check for Balanced Parentheses in an expression

*******************************************************************************/
#include <stdio.h>

struct stack 
{
    char data;
    struct stack * next;
};
void push(struct stack** top , char c)
{
    struct stack* temp = (struct stack*)malloc(sizeof(struct stack));
    temp->data = c;
    temp->next = *top;
    *top = temp;
}

char pop( struct stack **top)
{
    struct stack *temp = *top;
    char data = temp->data;
    *top = (*top)->next;
    free(temp);
    return data;
}
int checkBalanced( char* str,int len)
{
    struct stack *top = NULL;
    char prev;
    push(&top,'-');
    int i =0;
    while( i < len )
    {
     if( str[i] == '(' )
          {
            push(&top,'(');
          }
      else if( str[i] == ')' )
      {
        prev = pop(&top);
            if(prev == '-' )
               return 1;
      }
      i++;
    }
     prev = pop(&top);
     if(prev == '-' )
        return 0; // balanced
     else 
        return 1; // unbalanced
}

int main()
{
   char * str = "((( 23 + 56) % (45) + 6)-7)";
   int len = strlen(str);
   printf("Paranthesis is Balanced or not :: %d , (0 = Balanced ,1 = Not Balanced ) ",checkBalanced(str,len));
    return 0;
}
