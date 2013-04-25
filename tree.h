#ifndef _TREE_H
#define _TREE_H

#include "linked-list.h"

/******************************************************************************/
/*
 * Description:	Structure definition of tree_t type.
 */
typedef struct {
	void *data;
	void *root;
	void *parent;
	list_t *children;
} tree_t;

/******************************************************************************/
/*
 * Description:	Create an empty tree.
 * Return:		A pointer to created tree.
 */
tree_t *create_empty_tree(void);

/******************************************************************************/
/*
 * Description:	Create a child to informed node.
 * Parameters:	tree is the parent node.
 * 				data_size is the size in bytes to be allocated to date.
 * Return:		A pointer to the created node of tree. If the list is empty,
 *				return NULL.
 */
tree_t *create_child_to_node(tree_t *tree, unsigned int data_size);

/******************************************************************************/
/*
 * Description:	Find the first child of a node.
 * Parameters:	tree is the parent node to be searched the child.
 * Return:		A pointer to the first child. If the node has no children,
 *				return NULL.
 */
tree_t *get_first_child(tree_t *tree);

/******************************************************************************/
/*
 * Description:	Find the next brother of a node.
 * Parameters:	tree the node to be searched the next brother.
 * Return:		A pointer to the next brother. If there is no next node,
 *				return NULL.
 */
tree_t *get_next_brother(tree_t *tree);

/******************************************************************************/
/*
 * Description:	Travel trough the tree starting in an specific node.
 * Parameters:	tree is the node to start the travel.
 */
#if 0
void travel_tree(tree_t *tree);
#endif

/******************************************************************************/

#endif /* _TREE_H */
