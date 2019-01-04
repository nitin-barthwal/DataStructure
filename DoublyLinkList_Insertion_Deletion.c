/******************************************************************************

Doubly Link List
Insertion Deletion at 
1 Begnning
2 End 
3 At a given location

*******************************************************************************/
#include <stdio.h>
struct Node
{
    int data;
    struct Node* next;
    struct Node* prev;
};

void insert_beginning(struct Node** head, struct Node** tail, int data)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next =NULL;
    temp->prev = NULL;
    
    if(*head == NULL)
       { *head= temp;
         *tail = temp;
       }
    else
    {
        temp->next = *head;
        (*head)->prev = temp;
        *head = temp;
    }
}


void insert_end(struct Node** head,struct Node ** tail, int data)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next =NULL;
    temp->prev = NULL;
    
    if(*head == NULL)
       { *head= temp;
         *tail = temp;
       }
    else
    {
        (*tail)->next = temp;
        temp->prev = *tail;
        *tail = temp;
    }
}


void insert_at_location(struct Node** head,struct Node ** tail, int data,int loc)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next =NULL;
    temp->prev = NULL;
    struct Node* curr = *head;
    if(*head == NULL)
       { *head= temp;
         *tail = temp;
       }
    else
    {
        int count = 1;
        while(count != loc && curr->next != NULL)
            { curr = curr->next;
              count++;
            }
            if (loc == 1)
            { // add at the begnning
                temp->next = *head;
                (*head)->prev = temp;
                *head = temp;
            }
            else  if(curr->next == NULL && count!= loc)
            {  // adding at the end
                curr->next = temp;
                temp->prev = curr;
                *tail = temp;
            }
            else
            { // inserting at location :: loc
            
            temp->prev = curr->prev;
            temp->next = curr;
            curr->prev = temp;
            temp->prev ->next = temp;
            }
    }
}



void delete_beginning(struct Node** head,struct Node ** tail)
{
    struct Node* temp = NULL;
    
    if(*head == NULL)
       { 
           printf(" Cant delete . List Empty");
           return;
       }
    else
    {
        if((*head)->next == NULL)
            {  free(head);
                return ; 
            }
        temp = *head;
        *head = (*head)->next;
        free(temp);
        (*head)->prev = NULL;
    }
}


void delete_end(struct Node** head,struct Node ** tail)
{
    struct Node* temp = NULL;
    if(*head == NULL)
       { 
           printf(" Cant delete . List Empty");
           return;
       }
    else
    {
        if((*head)->next == NULL)
            {  free(head);
                return ; 
            }
        temp = *tail;
        *tail = (*tail)->prev;
        free(temp);
        (*tail)->next = NULL;
    }
}

void show( struct Node * head)
{
    struct Node* temp=head;
    while(temp)
    {
        printf(" %d -> ",temp->data);
        temp = temp->next;
    }
}


void delete_at_location(struct Node** head,struct Node ** tail,int loc)
{
    struct Node* temp =  NULL;
    struct Node* curr = *head;
    if(*head == NULL)
       {   printf(" Cant delete . List Empty");
           return;
       }
    else
    {
        int count = 1;
        while(count != loc && curr->next != NULL)
            { curr = curr->next;
              count++;
            }
        if(curr->next == NULL)
            {  // deleting at the end
                *tail= curr->prev;
                free(curr);
                (*tail)->next = NULL;
            }
            else if (curr == 1)
            { // deleting at the begnning
                temp= *head;
                *head = (*head)->next ;
                free(temp);
                (*head)->prev = NULL;
            }
            else
            { // deeting at location :: loc
            temp = curr;
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
            free(temp);
            }
    }
}

int main()
{
    struct Node* head =NULL;
    struct Node* tail =NULL;
    insert_beginning(&head,&tail,10);
    insert_beginning(&head,&tail,20);
    insert_end(&head,&tail,30);
    show(head);
    printf("\n");
    insert_at_location(&head,&tail,13, 3);
    insert_beginning(&head,&tail,3);
    show(head);
     printf("\n");
    insert_end(&head,&tail,80);
    insert_at_location(&head,&tail,45, 3);
    show(head);
     printf("\n");
    delete_beginning(&head,&tail);
    delete_end(&head,&tail);
       show(head);
     printf("\n");
    delete_at_location(&head,&tail, 3);  
        show(head);
    return 0;
}
