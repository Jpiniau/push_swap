#include "libft.h"
#include <stdlib.h>

static t_list   *init_tmpile(t_list *pile)
{
        t_list  *tmpile;

        if (!(tmpile = (t_list *)malloc(sizeof(t_list))))
                return (NULL);
        tmpile = NULL;
        while (pile != NULL)
        {
                ft_lstaddback(&tmpile, ft_lstnew(pile->content, sizeof(pile->content)));
                pile = pile->next;
        }
        return (tmpile);
}

t_list	*rra(t_list *pile)
{
	t_list	*end;
	t_list	*begin;
	t_list  *tmpile;
	
	tmpile = init_tmpile(pile);
	end = tmpile;
	begin = tmpile;
	while (end->next != NULL)
		end = end->next;
	ft_lstadd(&begin, end);
	while (tmpile->next != end)
	   tmpile = tmpile->next;
	tmpile->next = NULL;
	tmpile = begin;
	return (tmpile);
}
