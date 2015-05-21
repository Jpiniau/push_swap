#include "push.h"
#include "libft.h"

t_list	*create_pile(int ac, char **av)
{
	int	i;
	int	tmp;
	t_list	*list;

	list = NULL;
	i = 0;
	while (++i < ac)
	{
		tmp = ft_atoi(av[i]);
		ft_lstaddback(&list, ft_lstnew(&tmp, sizeof(int)));
	}
	return (list);
}

int	main(int ac, char **av)
{
	t_list *pilea;
	t_list *pileb;
	t_tree	*tree;
//	t_duopile *duo;
//	int	*tmp;

	pileb = NULL;
	pilea = create_pile(ac ,av);
	tree = create_node(pilea, pileb, NULL, -1);
	parkour_node(tree);
/*	pilea = sa(pilea);
	duo = pb(pilea, pileb);
	duo = pb(duo->pilea, duo->pileb);
	duo->pileb = sa(duo->pileb);
	duo = pa(duo->pilea, duo->pileb);
//	duo = pa(duo->pilea, duo->pileb);
//	duo = pa(duo->pilea, duo->pileb);
	pilea = duo->pilea;
	pileb = duo->pileb;
	while (pilea != NULL)
	{
		tmp = (int *)pilea->content;
		ft_putnbr(*tmp);
		pilea = pilea->next;
	}
	ft_putchar('\n');
	while (pileb != NULL)
	{
		tmp = (int *)pileb->content;
		ft_putnbr(*tmp);
		pileb = pileb->next;
	}*/
	return (0);
}
