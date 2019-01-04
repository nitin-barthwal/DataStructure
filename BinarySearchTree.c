/******************************************************************************

BST Binary Search treeAddition
Deletion
Sum of all elements 
Finding Minimum

*******************************************************************************/
#include <stdio.h>
struct Node  
{ 
  int data; 
  struct Node *left; 
  struct Node *right; 
};

struct Node* new_node(int x)
{
    struct Node *p;
    p = (struct Node*) malloc(sizeof(struct Node));
    p->data = x;
    p->left = NULL;
    p->right = NULL;

    return p;
}

//recursive insert
struct Node* insert(struct Node *root, int x)
{
    //searching for the place to insert
    if(root==NULL)
        return new_node(x);
    else if(x>root->data) // x is greater. Should be inserted to right
        root->right = insert(root->right, x);
    else // x is smaller should be inserted to left
        root->left = insert(root->left,x);
    return root;
}
//Iterative insert
struct Node* createNode(struct Node* root,int data)
{
    struct Node* temp = root;
    struct Node* parent;
    struct Node* left=NULL;
    struct Node* right= NULL;
    struct Node* curr=root;
    temp = (struct Node* )malloc(sizeof(struct Node));
    temp->data = data;
    temp->left =NULL;
    temp->right = NULL;
    
    if(root==NULL)
        root = temp;
    else
    {
        // traverse to correct location
        while(curr)
        {
           parent=curr;
            if(temp->data < curr->data)
                curr = curr->left;
            else 
                {
                    temp->data > curr->data;
                     curr = curr->right;
                }
        }  
        if ( parent->data < temp->data)
            parent->right = temp;
        else
            parent->left = temp;
    }
    return root;
}

void inorder(struct Node* curr)
{
   // struct Node* curr = root;
    if(curr==NULL)
        return;
    inorder(curr->left);
    printf(" %d ",curr->data);
    inorder(curr->right);
}

//binary tree sum of all elements 
int tree_sum(struct Node* curr)
{
    if(curr==NULL)
        return 0;
    return curr->data + tree_sum(curr->left) + tree_sum(curr->right);
}

int search(struct Node* root,int data)
{
    if(root == NULL)
        return 0;
    while(root)
     {   if(root->data == data)
        { return 1;
        }
        else if(root->data > data)
        { root = root->left;
        }
        else 
        { root = root->right;
        }
     }
     return 0;
}

struct Node* getMinimum(struct Node* root)
{
    while(root->left)
    {
        root=root->left;
    }
    return root;
}
struct Node* rec_delete(struct Node* root,int data)
{
    struct Node* temp;
    if(root==NULL)
        return root;   // data not present
    else if(root->data > data)
        root->left = rec_delete(root->left,data);  // move left
    else if(root->data <  data)
        root->right = rec_delete(root->right,data);  // move right
    //Reach to the node to be deleted
    else //(root->data == data)
    {
        //No Children
        if(root->left == NULL && root->right ==NULL )
        {
            free (root);
            return NULL;
        }
        //One Child
        else if(root->left==NULL || root->right==NULL)
        {
            struct Node *temp;
            if(root->left==NULL)
                temp = root->right;
            else
                temp = root->left;
            free(root);
            return temp;
        } 
        // node with two children: Get the inorder successor (smallest in the right subtree) 
        else
        {
            temp = getMinimum(root->right);
            root->data = temp->data;
            root->right = rec_delete(root->right,temp->data);
        }
    }
    
    return root;
}
struct Node* rec_search(struct Node* root,int data)
{
    if(root== NULL)
        return 0;
    else if( root -> data == data)
    {
        return 1;
    }
    else if (root->data > data )
    {
        root->left = rec_search(root->left,data);
    }
     else 
    {
        root->right = rec_search(root->right,data);
    }
}

main ()
{
  printf ("Hello World");
  struct Node* root=NULL;
  root = insert(root,50);
  root = createNode(root,80);
  root = createNode(root,70);
  root = insert(root,30);
  root = createNode(root,20);
  
  printf("\nsearching 20 , Found=1,not found =0   :: %d\n",search(root,20));
  inorder(root);
  root = rec_delete(root,80);
  printf("\n deleting 80 . New list is  :: ");
  inorder(root);
  
  printf("\n sum of the tree is  ::  %d",tree_sum(root));
  return 0;
}




