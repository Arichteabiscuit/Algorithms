#ifndef LIST_H
#define LIST_H

// List of integers

struct List;
struct ListItem;

// Creates new list
List *list_create();

// Destroys the list and frees the memory
void list_delete(List *list);

// Retrieves the first item from the list
ListItem *list_first(List *list);

// Extracts data from the list item
int list_item_data(ListItem *item);

// Returns list item following after the specified one
ListItem *list_item_next(ListItem *item);

// Returns previous element for the specified item.
// Not applicable for the singly linked lists.
ListItem *list_item_prev(ListItem *item);

// Inserts new list item into the beginning
ListItem *list_insert(List *list, int data);

// Inserts new list item after the specified item
ListItem *list_insert_after(List *list, ListItem *item, int data);

// Deletes the specified list item.
// Not applicable for the singly linked lists.
// Should be O(1)
ListItem *list_erase(List *list, ListItem *item);

// Deletes the list item following the specified one
// Should be O(1)
ListItem *list_erase_next(List *list, ListItem *item);

#endif
