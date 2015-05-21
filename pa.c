#include "libft.h"
#include "push.h"

t_duopile	*pa(t_list *pilea, t_list *pileb)
{
	t_list		*begin;
	t_list		*tmp;
	t_duopile	*piles;

	piles = init_duo(pilea, pileb);
	begin = piles->pileb;
	tmp = piles->pileb;
	if (begin->next == NULL)
	{
		ft_lstaddback(&piles->pilea, begin);
		piles->pileb = NULL;
	}
	else
	{
		while (begin->next != NULL)
			begin = begin->next;
		while (tmp->next != begin)
			tmp = tmp->next;
		ft_lstaddback(&piles->pilea, begin);
		tmp->next = NULL;
	}
	return (piles);
}
