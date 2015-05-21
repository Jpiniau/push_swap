#include "libft.h"
#include "push.h"

t_duopile	*pb(t_list *pilea, t_list *pileb)
{
	t_list		*begin;
	t_list		*tmp;
	t_duopile	*piles;

	piles = init_duo(pilea, pileb);
	begin = piles->pilea;
	tmp = piles->pilea;
	if (begin->next == NULL)
	{
		ft_lstaddback(&piles->pileb, begin);
		piles->pilea = NULL;
	}
	else
	{
		while (begin->next != NULL)
			begin = begin->next;
		while (tmp->next != begin)
			tmp = tmp->next;
		ft_lstaddback(&piles->pileb, begin);
		tmp->next = NULL;
	}
	return (piles);
}

