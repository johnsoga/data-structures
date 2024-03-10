# Data Structures in C
Open Source Data Structure Library in C

## Linked List (Doubly Linked List)
As a dynmic data structure, a Linked List allows for a collection of items to be stored together in a list like order wherein each item on the list links to the previous and next item as well. The other two primary dynamic data structures the Queue and Stack can be impelemented as Linked Lists with further restrictions on how the list is manipulated.

### API

#### Create
***
Creates a new Node that holds the supplied `newItem` as its data value
```C
node_t* newNode(void* newItem);
```
**Returns:** `NULL` if unable to allocate memory for the new Node; otherwise the new Node

Creates an empty Linked List
```C
list_t* newList();
```
**Returns:** `NULL` if unable to allocate memory for the new Linked List; otherwise the new Linked List



#### Modify (Add, Remove)
***
Adds a new item to the top/beginning of the list, aka position 1
```C
int insertFirst(list_t* list, void* newItem);
```
**Returns:** `0` on failure, `1` on success

Adds a new item to bottom/end of the list, aka position (current size of the list + 1)
```C
int insertLast(list_t* list, void* newItem);
```
**Returns:** `0` on failure, `1` on success

Adds a new item at position `pos` in the list
```C
int insertAt(list_t* list, void* newItem, unsigned long pos);
```
**Returns:** `0` on failure, `1` on success

Removes and returns the first item on the list
```C
node_t* removeFirst(list_t* list);
```
**Returns:** `NULL` if the list is empty; otherwise the first item on the list

Removes and returns the last item on the list
```C
node_t* removeLast(list_t* list);
```
**Returns:** `NULL` if the list is empty; otherwise the last item on the list

Removes and returns an item at position `pos` on the list
```C
node_t* removeAt(list_t* list, unsigned long pos);
```
**Returns:** `NULL` if the list is empty; otherwise the last item at position `pos`

Removes all items of on the list, `free`s allocated memory 
```C
int destroy(list_t* list);
```
**Returns:** `0` if the list is already empty or `NULL`; otherwise `1` if sucessful



#### Observe
***
Gets the item at the top/beginning of the list
```C
node_t* getFirst(list_t* list);
```
**Returns:** A copy of the item at position 1 on the list; Caller is responsible for `free`ing this memory

Gets the item at the bottom/end of the list
```C
node_t* getLast(list_t* list);
```
**Returns:** A copy of the item at position `size` on the list; Caller is responsible for `free`ing this memory

Gets an item at position `pos` on the list
```C
node_t* getAt(list_t* list, unsigned long pos);
```
**Returns:** A copy of the item at position `pos` on the list; Caller is responsible for `free`ing this memory



#### Utility Functions
***
Creates a copy of a Node, leaving the original Node untouched. The size of the original Node's data element `dataSize` is required to ensure adequate space is reserved to copy the data value into the new Node
```C
node_t* copyNode(node_t* origNode, size_t dataSize);
```
**Returns:** `NULL` if the original Node's data element is `NULL`, if unable to allocate memory for the new Node, or if unable to copy the data value into the new Node; otherwise a copy of the original Node

Answers the question "is the list empty" by looking at the list's size parameter
```C
int isEmpty(list_t* list);
```
**Returns:** `0` if false; `1` if true


