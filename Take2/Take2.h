/**
*hidden file for question 1.b from assignment 4
*Author Alexey Titov
*Version 3.0
**/
//libraries
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
//define variably
#define MAXLENGTH 10
// An AVL tree node
typedef struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    int height;
}Node_AVL;
 
// A utility function to get height of the tree
int height(Node_AVL *N);
 
// A utility function to get maximum of two integers
int max(int a, int b);
 
// Helper function that allocates a new node with the given key and
// NULL left and right pointers. 
Node_AVL* newNode(int key);
 
// A utility function to right rotate subtree rooted with y
// See the diagram given above.
Node_AVL *rightRotate(Node_AVL *y);
 
// A utility function to left rotate subtree rooted with x
// See the diagram given above.
Node_AVL *leftRotate(Node_AVL *x);
   
// Get Balance factor of node N
int getBalance(Node_AVL *N);
 
// Recursive function to insert key in subtree rooted
// with node and returns new root of subtree.
Node_AVL* insert(Node_AVL* node, int key);

//the function choose median number
int Median(Node_AVL *root);

//the function return median and stores 'num' in memory
int take2(int num);