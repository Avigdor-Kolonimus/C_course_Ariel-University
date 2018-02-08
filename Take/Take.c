/**
*C file for hidden of question 1.a from assignment 4
*Author Alexey Titov
*Version 1.0
**/
//library
#include "Take.h"
//global variable
int flag=0;
LinkedList list;
/** 
 * create a Node
 */
Node* createNode (int item) {
    Node* node = (Node*) malloc (sizeof(Node));
	if (node==NULL)
		exit(1);
    node->item = item;
    node->next = NULL;
    return node;
}
/** 
 * create a LinkedList
 */
LinkedList createLinkedList () {
    LinkedList list;
    list.head = NULL;
    list.mid=NULL;
    list.tail = NULL;
    list.size=0;
    return list;
}
/** 
 * add item to tail and return middle item
 */
int addLast (LinkedList* _this, int item) {
    Node* newNode =createNode(item);
    Node* head = _this->head;
    Node* tail = _this->tail;
    // list is empty
    if (head == NULL)
    {
        _this->head = newNode;
        _this->mid=_this->head ;
    }
    else { // has item(s)
        Node* lastNode = tail;
        if (tail == NULL) // only head node
            lastNode = head;
        lastNode->next = newNode;
        _this->tail = newNode;
    }
    _this->size++;
    if (_this->size%2==0)
        _this->mid=_this->mid->next;
    return _this->mid->item;
}
/** 
 * display the items in the list
 */
void display (LinkedList* _this) {
     int i, size = _this->size;
     if (size == 0)
        printf("no item\n\n");
     else {
        printf("has %d items\n", size);
        Node* node = _this->head;
        for (i = 0; i < size; i++) {
            if (i > 0)
                printf(", ");
            printf("%d", node->item);
            node = node->next;
        }
        printf("\n\n");
    }
}
//the function gets a number and returns the middle number
int take(int num)
{
    if (flag==0)
    {
        list = createLinkedList();
        flag++;
    }
    num=addLast(&list,num);
    return num;
}