#include "ds.h"
#include <stdlib.h>
#include <string.h>

node_t* newNode(void* newItem) {
    
    node_t* newNode = (node_t*)malloc(sizeof(node_t));

    if(newNode != NULL) {
        newNode->data = newItem;
        newNode->next = NULL;
        newNode->prev = NULL;
    }

    return newNode;    
}
node_t* copyNode(node_t* origNode, size_t dataSize) {

    node_t* dstNode;
    void* dstData;

    if(origNode->data == NULL) {
        return NULL;
    } 
    
    dstData = malloc(dataSize);
    if(dstData == NULL) {
        return NULL;
    }

    memcpy(dstData, origNode->data, dataSize);
    dstNode = newNode(dstData);

    if(dstNode != NULL) {
        return dstNode;
    }

    return NULL;
}
list_t* newList() {
    
    list_t* newList = (list_t*)malloc(sizeof(list_t));

    if(newList != NULL) {
        newList->size = 0;
        newList->head = NULL;
        newList->tail = NULL;
    }

    return newList;
}
int isEmpty(list_t* list) {

    if(list->size == 0) {
        return 1;
    }

    return 0;
}
int destroy(list_t* list) {

    node_t* curr;
    node_t* tmp; 

    if(isEmpty(list) || list == NULL) {
        return 0;
    }

    curr = list->head;
    while(curr != NULL) {

        if(curr->data != NULL) {
            free(curr->data);
        }
        tmp = curr;
        curr = curr->next;
        free(tmp);
    }

    list->head = NULL;
    list->tail = NULL;
    list->size = 0;

    return 1;
}
int insertFirst(list_t* list, void* newItem) {
    
    node_t* tmpNode = newNode(newItem);

    if(tmpNode != NULL) {
        if(isEmpty(list)) {
            list->head = tmpNode;
            list->tail = tmpNode;
        } else {
            tmpNode->next = list->head;
            list->head->prev = tmpNode;
            list->head = tmpNode;
        }

        list->size++;

	    return 1;
    }
    return 0;
}
int insertLast(list_t* list, void* newItem) {
   
    node_t* tmpNode = newNode(newItem);

    if(tmpNode != NULL) {
        if(isEmpty(list)) {
            list->tail = tmpNode;
            list->head = tmpNode;
        } else {
            tmpNode->prev = list->tail;
            list->tail->next = tmpNode;
            list->tail = tmpNode;
        }

        list->size++;

	    return 1;
    }
    return 0;
}
int insertAt(list_t* list, void* newItem, unsigned long pos) {

    node_t* tmpNode;

    if((pos > list->size+1) || (pos <= 0)) {
        return 0;
    } else if(pos == 1) {
        return insertFirst(list, newItem);
    } else if(pos == list->size+1) {
        return insertLast(list, newItem);
    }

    tmpNode = newNode(newItem);
    if(tmpNode != NULL) {

        node_t* curr = list->head;
	    unsigned long counter = 1;
        while(counter < pos-1) {

            curr = curr->next;
            counter++;
        }
        tmpNode->next = curr->next;
        tmpNode->prev = curr;
        curr->next->prev = tmpNode;
        curr->next = tmpNode;
        list->size++;

	    return 1;
    }
    return 0;
}
node_t* removeFirst(list_t* list) {

    node_t* returnNode;

    if(isEmpty(list)) {
        return NULL;
    }

    returnNode = list->head;
    list->head = list->head->next;

    if(list->size == 1) {
        list->tail = NULL;
    } else {
        list->head->prev = NULL;
    }

    list->size--;

    return returnNode;
}
node_t* removeLast(list_t* list) {

    node_t* returnNode;

    if(isEmpty(list)) {
        return NULL;
    }

    returnNode = list->tail;
    list->tail = list->tail->prev;

    if(list->size == 1) {
        list->head = NULL;
    } else {
        list->tail->next = NULL;
    }

    list->size--;

    return returnNode;
}
node_t* removeAt(list_t* list, unsigned long pos) {

    node_t* returnNode;
    node_t* curr;

    if((pos > list->size) || (pos <= 0)) {
        return NULL;
    }

    if(pos == 1) {
	    return removeFirst(list);
    } else if (pos == list->size) {
        return removeLast(list);
    }

    curr = list->head;
    unsigned long counter = 1;
    while(counter < pos-1) {
        curr = curr->next;
        counter++;
    }
    returnNode = curr->next;
    curr->next = returnNode->next;
    returnNode->next->prev = curr;

    list->size--;

    return returnNode;
}
node_t* getFirst(list_t* list) {

    node_t* rtnNode = copyNode(list->head, sizeof(list->head->data));
    return rtnNode;
}
node_t* getLast(list_t* list) {
    
    node_t* rtnNode = copyNode(list->tail, sizeof(list->tail->data));
    return rtnNode;
}
node_t* getAt(list_t* list, unsigned long pos) {

    node_t* rtnNode;

    if((pos > list->size) || (pos <= 0)) {
        return NULL;
    }

    if(isEmpty(list)) {
        return NULL;
    }

    if(pos == 1) {
        return getFirst(list);
    } else if(pos == list->size) {
        return getLast(list);
    }

    node_t* curr = list->head;
    unsigned long counter = 1;
    while(counter < pos) {
        curr = curr->next;
        counter++;
    }

    rtnNode = copyNode(curr, sizeof(curr->data));
    return rtnNode;
}
