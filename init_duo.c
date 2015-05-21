#include "libft.h"
#include "push.h"
#include <stdlib.h>

t_duopile	*init_duo(t_list *pilea, t_list *pileb)
{
	t_duopile	*tmp;

	tmp = (t_duopile *)malloc(sizeof(t_duopile));
	if (tmp == NULL)
		return (NULL);
//	tmp->pilea = (t_list *)malloc(sizeof(t_list));
//	tmp->pileb = (t_list *)malloc(sizeof(t_list));
	tmp->pilea = NULL;
	tmp->pileb = NULL;
	while (pilea != NULL)
	{
		ft_lstaddback(&tmp->pilea, ft_lstnewcust(pilea->content, sizeof(pilea->content)));
		pilea = pilea->next;
	}
	while (pileb != NULL)
	{
		ft_lstaddback(&tmp->pileb, ft_lstnewcust(pileb->content, sizeof(pileb->content)));
		pileb = pileb->next;
	}
	return (tmp);
}


