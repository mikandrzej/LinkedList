#include "linked_list.h"


LinkedListNode* createLinkedList(int data){
    LinkedList *ll = malloc(sizeof(LinkedList));
    if(ll == NULL)
        return NULL;

    ll->nodes = 1;

    LinkedListNode *lln = malloc(sizeof(LinkedListNode));
    ll->next = lln;
    lln->parent = ll;
    lln->next = NULL;
    lln->data = data;

    return lln;
}

 size_t deleteLinkedList(LinkedListNode *lln){
    if(lln == NULL)
        return E_NULL_POINTER;
    LinkedList *parent = lln->parent;
    LinkedListNode *iter = parent->next;
    while(iter != NULL)
    {
        LinkedListNode * temp = iter->next;
        free(iter);
        iter = temp;
    }
    free(parent);
    return 0;
}

LinkedListNode* getNextLinkedList(LinkedListNode *lln){
    if(lln == NULL)
        return NULL;
    return lln->next;
}

size_t getNodesCount (LinkedListNode *lln){
    if(lln == NULL)
        return 0;
    return lln->parent->nodes;
}

size_t getNumerOfNode(LinkedListNode *lln)
{
    size_t nodes = getNodesCount(lln);
    LinkedListNode *iter = lln->parent->next;
    for(int k=0; k<nodes; k++){
        if(iter == lln)
            return k;
        iter = iter->next;
    }
    return 0;
}

LinkedListNode* getNodeWithNumber (LinkedListNode *lln, size_t number){
    size_t nodes = getNodesCount(lln);
    LinkedListNode *iter = lln->parent->next;
    for(int k=1; k<nodes; k++){
        iter = iter->next;
    }
    return iter;
}

LinkedListNode* insertLinkedList(LinkedListNode *lln, int data){
    if(lln == NULL)
        return NULL;
    LinkedListNode *nlln = malloc(sizeof(LinkedListNode));
    if(nlln == NULL)
        return NULL;

    nlln->next = lln->next;
    lln->next = nlln;
    nlln->parent = lln->parent;
    nlln->parent->nodes++;
    nlln->data = data;

    return nlln;
}

int removeLinkedListP(LinkedListNode *plln, LinkedListNode *lln){
    if(lln == NULL)
        return E_NULL_POINTER;
    if(plln == NULL)
        return E_NULL_POINTER;

    plln->next = lln->next;
    lln->parent->nodes--;
    free(lln);

    return 0;
}

int removeLinkedList(LinkedListNode *lln){
    LinkedListNode *iter = lln->parent->next;
    size_t nodes = lln->parent->nodes;
    for(int k=0; k<nodes; k++){
        if(iter->next == lln)
            break;
        iter = iter->next;
    }
    return removeLinkedListP(iter, lln);
}

int getDataLinkedList(LinkedListNode *lln){
    if(lln == NULL)
        return 0;
    return lln->data;
}
