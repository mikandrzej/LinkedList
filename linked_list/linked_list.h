#ifndef LINKED_LIST_H_INCLUDED
#define LINKED_LIST_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#define E_NULL_POINTER  1
#define E_MEM_ERROR  1

struct sLinkedList{
    struct sLinkedListNode *next;
    size_t  nodes;
};

struct sLinkedListNode{
    struct sLinkedListNode *next;
    struct sLinkedList *parent;
    int data;
};

typedef struct sLinkedList LinkedList;
typedef struct sLinkedListNode LinkedListNode;


LinkedListNode* createLinkedList(int data);
size_t deleteLinkedList(LinkedListNode *lln);

LinkedListNode* getNextLinkedList(LinkedListNode *lln);
size_t getNodesCount (LinkedListNode *lln);
size_t getNumerOfNode(LinkedListNode *lln);
LinkedListNode* getNodeWithNumber (LinkedListNode *lln, size_t number);

LinkedListNode* insertLinkedList(LinkedListNode *lln, int data);
int removeLinkedListP(LinkedListNode *plln, LinkedListNode *lln);
int removeLinkedList(LinkedListNode *lln);
int getDataLinkedList(LinkedListNode *lln);

#endif // LINKED_LIST_H_INCLUDED
