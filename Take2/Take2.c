/**
*C file of hidden for question 1.b from assignment 4
*Author Alexey Titov
*Version 3.0
**/
//library
#include "Take2.h"

// A utility function to get height of the tree
int height(Node_AVL *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}
 
// A utility function to get maximum of two integers
int max(int a, int b)
{
    return (a > b)? a : b;
}
 
// Helper function that allocates a new node with the given key and
// NULL left and right pointers.
Node_AVL* newNode(int key)
{
    Node_AVL* node = (Node_AVL*)malloc(sizeof(Node_AVL));
    node->key   = key;
    node->left   = NULL;
    node->right  = NULL;
    node->height = 1;  // new node is initially added at leaf
    return(node);
}
 
// A utility function to right rotate subtree rooted with y
// See the diagram given above.
Node_AVL *rightRotate(Node_AVL *y)
{
    Node_AVL *x = y->left;
    Node_AVL *T2 = x->right;
 
    // Perform rotation
    x->right = y;
    y->left = T2;
 
    // Update heights
    y->height = max(height(y->left), height(y->right))+1;
    x->height = max(height(x->left), height(x->right))+1;
 
    // Return new root
    return x;
}
 
// A utility function to left rotate subtree rooted with x
// See the diagram given above.
Node_AVL *leftRotate(Node_AVL *x)
{
    Node_AVL *y = x->right;
    Node_AVL *T2 = y->left;
 
    // Perform rotation
    y->left = x;
    x->right = T2;
 
    //  Update heights
    x->height = max(height(x->left), height(x->right))+1;
    y->height = max(height(y->left), height(y->right))+1;
 
    // Return new root
    return y;
}
 
// Get Balance factor of node N
int getBalance(Node_AVL *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}
 
// Recursive function to insert key in subtree rooted
// with node and returns new root of subtree.
Node_AVL* insert(Node_AVL* node, int key)
{
    /* 1.  Perform the normal BST insertion */
    if (node == NULL)
        return(newNode(key));
 
    if (key < node->key)
        node->left  = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else // Equal keys are not allowed in BST
        return node;
 
    /* 2. Update height of this ancestor node */
    node->height = 1 + max(height(node->left),height(node->right));
 
    /* 3. Get the balance factor of this ancestor
          node to check whether this node became
          unbalanced */
    int balance = getBalance(node);
 
    // If this node becomes unbalanced, then
    // there are 4 cases
 
    // Left Left Case
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);
 
    // Right Right Case
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);
 
    // Left Right Case
    if (balance > 1 && key > node->left->key)
    {
        node->left =  leftRotate(node->left);
        return rightRotate(node);
    }
 
    // Right Left Case
    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
 
    /* return the (unchanged) node pointer */
    return node;
}

//the function choose median number
int Median(Node_AVL *root)
{
    if(root->left == NULL)
        return root->key;
    if (root->right==NULL)
        return root->left->key;
    if (root->right->height<root->left->height)
        return root->left->key;
    return root->key; 
}

//the function return median and stores 'num' in memory
int take2(int num)
{
    static Node_AVL *root = NULL;
 
  /* Constructing tree given in the above figure */
  root = insert(root, num);
  return Median(root);
}