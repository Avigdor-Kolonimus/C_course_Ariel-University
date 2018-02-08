/**
*c file for hidden of question 2 from assignment 4
*Author Alexey Titov
*Version 1.0
**/
//library
#include "IsStringBalanced.h"

//the function create new node 
struct StackNode* newNode(char data)
{
    struct StackNode* stackNode =
              (struct StackNode*) malloc(sizeof(struct StackNode));
	if (stackNode==NULL)
		exit(1);
    stackNode->data = data;
    stackNode->next = NULL;
    return stackNode;
}
//the function check if stack is empty
int isEmpty(struct StackNode *root)
{
    return !root;
}
//the function enters a new character to stack
void push(struct StackNode** root, char data)
{
    struct StackNode* stackNode = newNode(data);
    stackNode->next = *root;
    *root = stackNode;
}
//the function returns from stack the character that is the first to exit.
char pop(struct StackNode** root)
{
    if (isEmpty(*root))
        return ' ';
    struct StackNode* temp = *root;
    *root = (*root)->next;
    char popped = temp->data;
    free(temp);
 
    return popped;
}
//the function returns the character that is the first to exit
char peek(struct StackNode* root)
{
    if (isEmpty(root))
        return ' ';
    return root->data;
}
//the function checks if the correct placement of the brackets
bool isStringBalanced(char** sentence, int size) 
{
    struct StackNode* root = NULL;
    for (int i=0;i<size;i++)
    {
        char *tmp_s=sentence[i];
        while(*tmp_s!='\0')
        {
            char tmp=*tmp_s;
            switch(tmp)
            {
                case '{':
                case '(':
                case '[':
                    push(&root, tmp);
                    break;
                case '}':
                case ')':
                case ']':
                if (isEmpty(root))
                    return false;
                if (tmp-peek(root)!=1 && tmp-peek(root)!=2)     //'('-40 ')'-41; '['-91 ']'-93; '{'-123 '}'-125
                    return false;  
                else
                    pop(&root);
            }
            tmp_s++;
        }
    }
    if (isEmpty(root))
        return true;
    return false;
}