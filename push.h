#ifndef PUSH_H
# define PUSH_H

# include "libft.h"

typedef struct		s_tree
{
	t_list		*pilea;
	t_list		*pileb;
	int		action;
	struct s_tree	*parent;
	struct s_tree	*child[11];
}			t_tree;

typedef struct	s_duopile
{
	t_list	*pilea;
	t_list	*pileb;
}		t_duopile;

enum	e_function{SA, SB, SS, PA, PB, RA, RB, RR, RRA, RRB, RRR};

t_list		*sa(t_list *pile);
t_duopile	*pa(t_list *pilea, t_list *pileb);
t_duopile	*pb(t_list *pilea, t_list *pileb);
t_list		*ra(t_list *pile);
t_list		*rra(t_list *pile);
t_tree		*create_node(t_list *pilea, t_list *pileb, t_tree **node, int action);
t_tree		*create_duo(t_duopile *piles, t_tree **node, int action);
void		parkour_node(t_tree *tree);
t_list		*ft_lstnewcust(void const *content, size_t content_size);
t_duopile	*init_duo(t_list *pilea, t_list *pileb);
void		delete_node(t_tree *node);

#endif
