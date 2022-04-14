#include "push_swap.h"

t_list	*fct_sa(t_list *list_a)
{
	int	tmp;

	tmp = list_a->content;
	list_a->content = list_a->next->content;
	list_a->next->content = tmp;
	ft_printf("sa\n");
}

t_list	*fct_sb(t_list *list_b)
{
	int	tmp;

	tmp = list_b->content;
	list_b->content = list_b->next->content;
	list_b->next->content = tmp;
	ft_printf("sb\n");
	return (list_b);
}
