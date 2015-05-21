#include "push.h"
#include "stdio.h"

static int	is_sort(t_list *pile, t_list *pileb)
{
	int	*tmp1;
	int	*tmp2;

	if (pileb != NULL)
		return (0);
	while (pile->next != NULL)
	{

		tmp1 = (int *)pile->content;
		tmp2 = (int *)pile->next->content;
		if ( *tmp1 < *tmp2)
			return (0);
		pile = pile->next;
	}
	return (1);
}

static void	create_children(t_tree **node)
{

	if ((*node)->pilea != NULL)
	{
		if ((*node)->action != PA)
			(*node)->child[PB] = create_duo(pb((*node)->pilea, (*node)->pileb), node, PB);
		if ((*node)->pilea->next != NULL)
		{
			if ((*node)->action != SA)
				(*node)->child[SA] = create_node(sa((*node)->pilea), (*node)->pileb, node, SA);
			if ((*node)->action != RRA)
				(*node)->child[RA] = create_node(ra((*node)->pilea), (*node)->pileb, node, RA);
			if ((*node)->action != RA)
				(*node)->child[RRA] = create_node(rra((*node)->pilea), (*node)->pileb, node, RRA);
			
		}
	}
	if ((*node)->pileb != NULL)
	{
		if ((*node)->action != PB)
			(*node)->child[PA] = create_duo(pa((*node)->pilea, (*node)->pileb), node, PA);
		if ((*node)->pileb->next != NULL)
		{
			if ((*node)->action != SB)
				(*node)->child[SB] = create_node((*node)->pilea , sa((*node)->pileb), node, SB);
			if ((*node)->action != RRB)
				(*node)->child[RB] = create_node((*node)->pilea, ra((*node)->pileb), node, RB);
			if ((*node)->action != RB)
				(*node)->child[RRB] = create_node((*node)->pilea, rra((*node)->pileb), node, RRB);
		}
	}
	if ((*node)->pilea != NULL && (*node)->pilea->next != NULL
			&& (*node)->pileb != NULL && (*node)->pileb->next != NULL)
	{
		if ((*node)->action != RRR && (*node)->action != RRB && (*node)->action != RRA )
			(*node)->child[RR] = create_node(ra((*node)->pilea), ra((*node)->pileb), node, RR);
		if ((*node)->action != RR && (*node)->action != RB && (*node)->action != RA )
			(*node)->child[RRR] = create_node(rra((*node)->pilea), rra((*node)->pileb), node, RRR);
		if ((*node)->action != SS)
			(*node)->child[SS] = create_node(sa((*node)->pilea), sa((*node)->pileb), node, SS);
	}
}

static void	print_parkour(t_tree *node)
{
	if (node->parent != NULL)
		print_parkour(node->parent);
	if (node->action == SA)
		ft_putstr("sa");
	else if (node->action == SB)
		ft_putstr("sb");
	else if (node->action == SS)
		ft_putstr("ss");
	else if (node->action == PA)
		ft_putstr("pa");
	else if (node->action == PB)
		ft_putstr("pb");
	else if (node->action == RA)
		ft_putstr("ra");
	else if (node->action == RB)
		ft_putstr("rb");
	else if (node->action == RR)
		ft_putstr("rr");
	else if (node->action == RRA)
		ft_putstr("rra");
	else if (node->action == RRB)
		ft_putstr("rrb");
	else if (node->action == RRR)
		ft_putstr("rrr");
	if (!is_sort(node->pilea, node->pileb) && node->parent != NULL)
		ft_putchar(' ');
}

void	parkour_node(t_tree *tree)
{
	t_list	*file;
	t_tree	*node;
	t_list *tmp;
	int *tmp1;
	int	i;

	file = ft_lstnewcust(tree, sizeof(tree));
	node = tree;
	while (file != NULL && !is_sort(node->pilea, node->pileb))
	{	
		node = file->content;
		file = file->next;
/*		tmp = node->pilea;
		ft_putendl("Pile A");
		while (tmp != NULL)
		{
			tmp1 = (int *)tmp->content;
			ft_putnbr(*tmp1);
			tmp = tmp->next;
		}
		ft_putendl("Pile B");
		tmp = node->pileb;
		while (tmp != NULL)
		{
			tmp1 = (int *)tmp->content;
			ft_putnbr(*tmp1);
			tmp = tmp->next;
		}*/
//		printf("adresse node : %p\n", node);
//		printf("action : %d\n", node->action);
	//	ft_putchar('\n');
	//	ft_putchar('q');
		/*		while (++i <= PB)
				printf("%p\n", node->child[i]);*/
		create_children(&node);
	//	ft_putchar('a');
		i = -1;
		while (++i <= RRR)
		{
	//		printf("%p\n", node->child[i]);
			if (node->child[i] != NULL)
			{
				ft_lstaddback(&file, ft_lstnewcust(node->child[i], sizeof(t_tree)));
			}
		}
	}
	tmp = node->pilea;
	ft_putendl("Pile A");
	while (tmp != NULL)
	{
		tmp1 = (int *)tmp->content;
		ft_putnbr(*tmp1);
		tmp = tmp->next;
	}
	tmp = node->pileb;
	ft_putendl("Pile B");
	while (tmp != NULL)
	{
		tmp1 = (int *)tmp->content;
		ft_putnbr(*tmp1);
		tmp = tmp->next;
	}
	print_parkour(node);
	ft_putchar('\n');
	delete_node(tree);
}
