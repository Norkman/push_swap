#include "push_swap.h"

int	ft_findcostup(t_tablist	*tl, int rest_nbr_box)
{
	t_list	*tmp;
	int		cost;
	int		nbr;
	int		nbr_over;

	tmp = tl->la;
	while (tmp)
	{
		nbr = tmp->content;
		if (ft_howmanyover(tl->la, nbr) < rest_nbr_box)
		{
			cost = ft_findpos(tl, 'a', nbr);
			break;
		}
		tmp = tmp->next;
	}
	return (cost);
}

int	ft_findcostdown(t_tablist *tl, int rest_nbr_box)
{
	t_list	*tmp;
	int		cost;
	int		nbr;

	tmp = tl->la;
	while (tmp)
	{
		nbr = tmp->content;
		if (ft_howmanyover(tl->la, nbr) < rest_nbr_box)
			cost = ft_findpos(tl, 'a', nbr);
		tmp = tmp->next;
	}
	return (count_list(tl, 'a') - cost);
}

t_tablist	*ft_rotatelesscost(t_tablist *tl, int costup, int costdown)
{
	int	i;

	i = 0;
	if (costup <= costdown)
	{
		while (i < costup)
		{
			tl = fct_rotate_arg(tl, 'a');
			i++;
		}
	}
	if (costdown < costup)
	{
		while (i < costdown)
		{
			tl = fct_rotate_reverse_arg(tl, 'a');
			i++;
		}
	}
	tl = fct_push_arg(tl, 'b');
	ft_printf("\nnum : %d\n", tl->lb->content);
	return (tl);
}
