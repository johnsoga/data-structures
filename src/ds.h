#include <stddef.h>

typedef struct node {
    struct node* next;
    struct node* prev;
    void* data;

} node_t;

typedef struct list {
    node_t* head;
    node_t* tail;
    unsigned long size;

} list_t;

node_t* newNode(void* newItem);
node_t* copyNode(node_t* origNode, size_t dataSize);
list_t* newList();
int isEmpty(list_t* list);
int destroy(list_t* list);
int insertFirst(list_t* list, void* newItem);
int insertLast(list_t* list, void* newItem);
int insertAt(list_t* list, void* newItem, unsigned long pos);
node_t* removeFirst(list_t* list);
node_t* removeLast(list_t* list);
node_t* removeAt(list_t* list, unsigned long pos);
node_t* getFirst(list_t* list);
node_t* getLast(list_t* list);
node_t* getAt(list_t* list, unsigned long pos);
