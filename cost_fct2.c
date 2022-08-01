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
		if (ft_howmanyover(tl->la, nbr) <= rest_nbr_box)
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
		if (ft_howmanyover(tl->la, nbr) <= rest_nbr_box)
			cost = ft_findpos(tl, 'a', nbr);
		tmp = tmp->next;
	}
	return (count_list(tl, 'a') - cost);
}

t_tablist	*ft_rotateup(t_tablist *tl, int costup, int poslowerlb)
{
	int i;

	i = 0;
	if (poslowerlb > 0 && poslowerlb < count_list(tl, 'a') / 2)
	{
		while (i < poslowerlb && i < costup)
		{
			tl = fct_rotate_arg(tl, 'r');
			i++;
		}
	}
	while (i < costup)
	{
		tl = fct_rotate_arg(tl, 'a');
		i++;
	}
	return (tl);
}

t_tablist	*ft_rotatedown(t_tablist *tl, int costdown, int poslowerlb)
{
	int i;

	i = 0;
	if (poslowerlb > count_list(tl, 'a') / 2)
		poslowerlb = count_list(tl, 'b') - poslowerlb;
	if (poslowerlb > 0 && poslowerlb < count_list(tl, 'a') / 2)
	{
		while (i < poslowerlb && i < costdown)
		{
			tl = fct_rotate_reverse_arg(tl, 'r');
			i++;
		}
	}
	while (i < costdown)
	{
		tl = fct_rotate_reverse_arg(tl, 'a');
		i++;
	}
	return (tl);
}
t_tablist	*ft_rotatelesscost(t_tablist *tl, int costup, int costdown)
{
	int nbr_la;
	int	poslowerlb;

	if (costup <= costdown)
	{
		nbr_la = ft_findnbr(tl, 'a', costup);
		//printf("costup in la : %d\n", costup);
		//printf("nbr in la : %d\n", nbr_la);
		poslowerlb = ft_findpos(tl, 'b', ft_findinferior(tl->lb, nbr_la));
		//printf("nbr inferior in lb: %d - place in lb: %d\n", ft_findinferior(tl->lb, nbr_la), poslowerlb);
		tl = ft_rotateup(tl, costup, poslowerlb);
	}
	if (costdown < costup)
	{
		nbr_la = ft_findnbr(tl, 'a', count_list(tl, 'a') - costdown);
		//printf("costdown in la : %d\n", costdown);
		//printf("nbr in la : %d\n", nbr_la);
		poslowerlb = count_list(tl, 'b') - ft_findpos(tl, 'b', ft_findinferior(tl->lb, nbr_la));
		//printf("nbr inferior in lb: %d - place in lb: %d\n", ft_findinferior(tl->lb, nbr_la), poslowerlb);
		tl = ft_rotatedown(tl, costdown, poslowerlb);
	}
	tl = fct_push_arg(tl, 'b');
	return (tl);
}
