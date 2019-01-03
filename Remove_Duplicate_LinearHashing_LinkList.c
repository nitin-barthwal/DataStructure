/******************************************************************************
Remove duplicates from an unsorted linked list using hashing in O(n) time.
*******************************************************************************/

#include <stdio.h>
#include<stdlib.h>

// Define the LinkList 
struct Node
{
    int data ; 
    struct Node* next;
};

//Hashing function :: key % (size of HashArray)
int hash(int data,int size)
{    return data%size;
}

// Impliment Linear Hashing 
// In Case of Conflict ,check next available space linearly
// hashing(i) =  hash( data + i )  increment i till you find avilable slot or stop if you get duplicate element(element already stored in hash table.

int hashing(int * arr,int data,int size)
{
    int index,i=0;
    index = hash(data,size);
    if ( arr[index] == 0)
      { 
          //update hash table with new element
          arr[index] = data;  // added data to hash table
          return 0;  
      }
    else
    {
        while(arr[hash(data+i,size)]!=0)  // Search free location 
        {
            if(arr[hash(data+i,size)] == data)  // duplicate found. Stop
               {
                   return 1;  // report duplicate data
               }
            i++;
        }
        arr[hash(data+i,size)] = data;  // got the free position without finding any duplicate. Hence insert into HashArray
        return 0;
    }
}

// Function to remove duplicates in a link list using  linear hashing
struct Node* remove_duplicate_using_hashing(struct Node * head, int* arr,int size)
{
struct Node* curr = head;
struct Node* prev = NULL;
int del;

while(curr)  // Do it for all elements in the linklist
{
    del = hashing(arr,curr->data,size); // Call hahing function
    // return 0 if the data is unique.
    // return 1 if data is duplicate.
    if( del) 
    {
        //delete duplicate node from LL
        prev->next = curr->next;
        free(curr);
        curr = prev ->next;
    }
    else{
        // Element is unique ,so just continue checking for next element.
        prev = curr;
        curr= curr->next;
    }
}
return head;    // return updated list head 
}

// allocate memory and data to a new Node and return it.
struct Node* allocate(int data)
{
    struct Node* temp = (struct Node* )malloc(sizeof(struct Node));
    temp->data= data;
    temp->next = NULL;
    return temp;
}

// Show element of a linklist
void show(struct Node* head)
{
    while(head)
    {
        printf(" %d -> ", head->data);
        head = head->next;
    }
}
int main()
{
    struct Node* head = NULL;
    int size = 12;
    int arr[10]={0}; // assign 0 to all elements of the HashArray
    
    head = allocate(40);
    head->next = allocate(20);
    head->next->next = allocate(40);
    head->next->next->next = allocate(35);
    head->next->next->next->next = allocate(21);
    head->next->next->next->next->next = allocate(50);
    head->next->next->next->next->next->next = allocate(35);
    head->next->next->next->next->next->next->next = allocate(26);
    head->next->next->next->next->next->next->next->next = allocate(20);
    head->next->next->next->next->next->next->next->next->next = allocate(45);
    head->next->next->next->next->next->next->next->next->next->next = allocate(33);
    head->next->next->next->next->next->next->next->next->next->next->next = allocate(20);
 
    printf("\n Original list is :: ");
    show(head);
    
    head = remove_duplicate_using_hashing(head, arr,size); // passing head of link list , HashArray , size of HashArray
    
    printf("\n Updated list after removal of duplicate nodes :: ");
    show(head);
    
    return 0;
}
