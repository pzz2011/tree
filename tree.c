#include "tree.h"

/******************************************************************************/

tree_t *create_empty_tree(void)
{
	tree_t *tree = malloc(sizeof(tree_t));

	tree->data = NULL;
	tree->root = NULL;
	tree->parent = NULL;
	tree->children = NULL;

	return tree;
}

/******************************************************************************/

tree_t *create_child_to_node(tree_t *tree, unsigned int data_size)
{
	tree_t *new;
	void *data;

	/* If it's a empty tree, it's the first and there is no previous */
	if (tree->root == NULL) {
		new = malloc(sizeof(tree_t));
		new->root = new;
		new->parent = NULL;
		new->children = create_empty_list();
	}
	else {
		/* Create a new node to parent's children list */
		tree->children = create_node_to_list(tree->children, sizeof(tree_t));
		new = ((list_t *)(tree->children))->data;

		new->root = tree->root;
		new->parent = tree;
	}

	/* Allocate memory to data */
	data = malloc(data_size);
	new->data = data;

	new->children = create_empty_list();

	return new;
}

/******************************************************************************/

tree_t *get_first_child(tree_t *tree)
{
	tree_t *aux;
	list_t *list_aux;

	/* If it's an invalid node, get out */
	if (tree == NULL)
		return NULL;

	list_aux = tree->children;
	list_aux = list_aux->first;

	/* If there are no children, get out */
	if (list_aux == NULL)
		return NULL;

	aux = list_aux->data;
}

/******************************************************************************/

tree_t *get_next_brother(tree_t *tree)
{
	tree_t *aux;
	list_t *list_aux;

	/* If it's an invalid node, get out */
	if (tree == NULL)
		return NULL;

	aux = tree->parent;

	/* If there is no parent, get out */
	if (aux == NULL)
		return NULL;

	list_aux = aux->children;
	list_aux = list_aux->first;
	aux = get_first_child(aux);

	/* Search current node */
	while (aux != tree)
	{
		list_aux = list_aux->next;
		aux = list_aux->data;
	}

	/* The next is the next of me */
	if (list_aux->next == NULL)
		return NULL;

	list_aux = list_aux->next;
	aux = list_aux->data;

	return aux;
}

/******************************************************************************/

#if 0
void travel_tree(tree_t *tree)
{
	tree_t *trav;

	trav = tree;

	/* If it's an invalid node, get out */
	if (trav == NULL)
		return;

	printf("%3d - %p\r\n", ((s_t *)(trav->data))->peso, trav);

	/* Travel through the children by recursion */
	trav = get_first_child(trav);
	travel_tree(trav);

	/* Travel through the brothers */
	trav = tree;
	trav = get_next_brother(trav);
	travel_tree(trav);

	return;
}
#endif

/******************************************************************************/

