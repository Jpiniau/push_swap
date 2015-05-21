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


t_list	*ra(t_list *pile)
{
	t_list	*begin;
        t_list  *tmpile;

        tmpile = init_tmpile(pile);
	begin = tmpile;
	ft_lstaddback(&tmpile, begin);
	tmpile = tmpile->next;
	begin->next = NULL;
	return (tmpile);
}
