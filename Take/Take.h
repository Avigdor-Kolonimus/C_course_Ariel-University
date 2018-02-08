/**
*hidden file for question 1.a from assignment 4
*Author Alexey Titov
*Version 1.0
**/
//libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//define variable
#define MAXLENGTH 10                   //maximum string length

/**
 * The Node struct,
 * contains item and the pointers that point to next node.
 */ 
typedef struct Node {
    int item; 
    struct Node* next; 
} Node; 

 /**
 * The LinkedList struct, contains the pointers that
 * point to first node, last node and middle node, the size of the LinkedList.
 */
typedef struct LinkedList {
    Node *head;
    Node *tail;
    Node *mid;
    unsigned int size;
}LinkedList;

/** 
 * create a Node
 */
Node* createNode (int item);
/** 
 * create a LinkedList
 */
LinkedList createLinkedList ();
/** 
 * add item to tail and return middle item
 */
int addLast (LinkedList* _this, int item);
/** 
 * display the items in the list
 */
void display (LinkedList* _this);
//the function gets a number and returns the middle number
int take(int num);