#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

#include <stdlib.h>

/******************************************************************************/
/*
 * Description:	Structure definition of list_t type.
 */
typedef struct {
	void *data;
	void *first;
	void *next;
	void *previous;
} list_t;

/******************************************************************************/
/*
 * Description:	Create an empty list. The values are NULL.
 * Return:		A pointer to created list.
 */
list_t *create_empty_list(void);

/******************************************************************************/
/*
 * Description:	Find the last node of a list.
 * Parameters:	list is a pointer to a list.
 * Return:		A pointer to the last node of list. If the list is empty,
 *				return NULL.
 */
list_t *get_last_from_list(list_t *list);

/******************************************************************************/
/*
 * Description:	Create a new node to the list.
 * Parameters:	list is a pointer to a list which will be appended.
				data_size is the size (in bytes) to the data which will be used
				inside of node.
 * Return:		A pointer to created node.
 */
list_t *create_node_to_list(list_t *list, unsigned int data_size);

/******************************************************************************/
/*
 * Description:	Create a new empty node to the list.
 * Parameters:	list is a pointer to a list which will be appended.
 * Return:		A pointer to created node.
 */
list_t *create_empty_node_to_list(list_t *list);

/******************************************************************************/
/*
 * Description:	Remove a specific node
 * Parameters:	node is a pointer to the node to be removed.
 * Return:		A pointer to the first node of list. If the list is empty,
 *				return NULL.
 */
list_t *remove_node_from_list(list_t *node);

/******************************************************************************/

#endif /* _LINKED_LIST_H */

