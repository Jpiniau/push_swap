/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeken <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/05 16:39:37 by mdeken            #+#    #+#             */
/*   Updated: 2015/05/05 18:06:38 by mdeken           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "push.h"
#include <stdlib.h>

void	delete_node(t_tree *node)
{
	int		i;
	t_list	*tmp;

	i = -1;
	while (++i < 11)
	{
		if (node->child[i] != NULL)
			delete_node(node->child[i]);
	}
	tmp = node->pilea;
	if (tmp != NULL)
		ft_lstclr(&tmp);
	tmp = node->pileb;
	if (node->pileb != NULL)
		ft_lstclr(&tmp);
	free(node);
}
