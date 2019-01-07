
#include <stdio.h>

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

struct my_queue
{
    struct Node* d;
    struct my_queue* next;
};

struct Node* insert(int data)
{
    struct Node* temp;
    temp = (struct Node*) malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void enqueue( struct my_queue** front,struct Node* curr, struct my_queue** rear)
{
    struct my_queue* q = (struct my_queue*)malloc(sizeof(struct my_queue));
    q->d = curr;
    q->next = NULL;
    if(*front==NULL)
        {
            *front = q;
            *rear = *front;
        }
        else{
             (*rear)->next = q;
             *rear = (*rear)->next;
        }
}
void dequeue(struct my_queue** front)
{
  if((*front)!=NULL)
  { 
      printf(" %d ",(*front)->d->data);
      *front = (*front)->next;
  }
}
int isempty(struct my_queue* front)
{
    if (front == NULL)
        return 0;
    else 
        return 1;
}
void levelorder(  struct Node* root)
{
    struct my_queue* front=NULL;
    struct my_queue* rear=NULL;
    struct Node* curr=root;

    enqueue(&front,curr,&rear);
   
    while( isempty(front))  // q is not empty
    {
        curr = front->d;
        dequeue(&front);
        if(curr->left)
          enqueue(&front,curr->left,&rear);
        if(curr->right) 
          enqueue(&front, curr->right,&rear);
    }
}
void inorder(struct Node* root)
{
    if(root==NULL)
    { return ;
    }
    inorder(root->left);
    printf("%d   ",root->data);
    inorder(root->right);
}

int main()
{
    struct Node* root;
    root = insert(50);
    root->left = insert(30);
    root->right = insert(100);
    root->left->left = insert(20);
    root->left->right = insert(40);
    root->right->left = insert(80);
    root->right->right = insert(120);
    
    printf("\n The inorder traversal is ");
    inorder(root);
        
    printf("\n The levelorder traversal is ");
    levelorder(root);

    return 0;
}





