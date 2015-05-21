#include <stdlib.h>
#include "push.h"
#include <stdio.h>

t_tree  *create_duo(t_duopile *piles, t_tree **node, int action)
{
        t_tree  *new_node;
	int	i;

        new_node = (t_tree *)malloc(sizeof(t_tree));
        if (new_node == NULL)
                return (NULL);
        new_node->pilea = piles->pilea;
        new_node->pileb = piles->pileb;
	if (node != NULL)
		new_node->parent = *node;
	else
		new_node->parent = NULL;
	new_node->action = action;
	i = -1;
	while (++i < 11)
	{
		new_node->child[i] = NULL;
	}
        return (new_node);
}

