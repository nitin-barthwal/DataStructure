/******************************************************************************

Check Tree is BST or not

*******************************************************************************/
#include<stdio.h>
#include<limits.h>

struct tree
{
int data;
struct tree *left;
struct tree *right;
};

struct tree* allocate(int data)
{
struct tree* temp = (struct tree*) malloc(sizeof(struct tree));
temp ->data = data;
temp->left = NULL;
temp->right = NULL;
return temp;
}
int isBST(struct  tree* curr,int min,int max)
{
  if ( curr== NULL)
  {
   return 1;
  }
  if( curr ->data  < min  || curr->data > max)
	{ 
         //  printf("\nTree Not BST");
            return 0;
	}
   return ( isBST(curr->left, min,curr->data) && isBST(curr->right, curr->data,max) );

}

void validateBST(struct tree * root)
{
   struct tree *curr = root;
  if( root ==NULL || (root->left == NULL && root->right ==NULL ) )
     {
       printf("TREE is validated");
       return ;
    }
   if (isBST(root,INT_MIN,INT_MAX))
	printf("tree is BST");
   else 
	printf("Tree Not BST");
   
}
void main()
{
  struct tree* root = NULL;
  root = allocate(100);
  root->left = allocate(80);
  root->right = allocate(120);
  root->left->left = allocate(70);
  root->left->right = allocate(110);
  root->right->left = allocate(105);
  root->right->right = allocate(130);

  validateBST(root);

}

