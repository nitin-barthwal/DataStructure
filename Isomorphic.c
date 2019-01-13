
/*************************************
 * Write a function to detect if two trees are isomorphic. Two trees are called isomorphic if one of them can be obtained from other by a series of flips, i.e. by swapping left and right children of a number of nodes. Any number of nodes at any level can have their children swapped. Two empty trees are isomorphic.

Input:
First line consists of T test cases. First line of every test case consists of N, denoting number of Node in tree. Second and third line of every test case consists of N, nodes of binary tree.

Output:
Single line output, return the boolean value true if "Yes" else "No".

 * ***********************************/
/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*Complete the function below
Node is as follows:
struct Node{
	int data;
	Node *left,*right;
};
*/
bool isIsomorphic(Node *root1,Node *root2)
{
   if (root1 == NULL && root2 == NULL)
     return true;
   if (root1 == NULL || root2 == NULL)
     return false;
   if(root1->data!=root2->data)
     return false;
   if ( (isIsomorphic( root1->left, root2->right) &&  isIsomorphic(root1->right, root2->left  ) )||  (isIsomorphic( root1->left, root2->left)  &&  isIsomorphic(root1->right, root2->right )) )
    return true;
}