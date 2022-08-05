/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_fct2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <nle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 11:28:52 by nle-bret          #+#    #+#             */
/*   Updated: 2022/08/05 17:50:37 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_findcostup(t_tablist	*tl, int rest_nbr_box)
{
	t_list	*tmp;
	int		cost;
	int		nbr;

	tmp = tl->la;
	while (tmp)
	{
		nbr = tmp->content;
		if (ft_howmanyunder(tl->la, nbr) <= rest_nbr_box)
		{
			cost = ft_findpos(tl, 'a', nbr);
			return (cost);
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
		if (ft_howmanyunder(tl->la, nbr) <= rest_nbr_box)
			cost = ft_findpos(tl, 'a', nbr);
		tmp = tmp->next;
	}
	return (count_list(tl, 'a') - cost);
}

t_tablist	*ft_rotateup(t_tablist *tl, int costup, int posunderlb)
{
	int i;
	int	len_lb;

	len_lb = count_list(tl, 'b');
	i = 0;
	if (posunderlb <= costup)
	{
		while (i < posunderlb)
		{
			tl = fct_rotate_arg(tl, 'r');
			i++;
		}
		while (i < costup)
		{
			tl = fct_rotate_arg(tl, 'a');
			i++;
		}
	}
	else if (posunderlb > costup && posunderlb - costup <= len_lb - posunderlb)
	{
		while (i < costup)
		{
			tl = fct_rotate_arg(tl, 'r');
			i++;
		}
	}
	else
	{
		while (i < costup)
		{
			tl = fct_rotate_arg(tl, 'a');
			i++;
		}
	}
	return (tl);
}

t_tablist	*ft_rotatedown(t_tablist *tl, int costdown, int posunderlb)
{
	int i;
	int	len_lb;

	len_lb = count_list(tl, 'b');
	posunderlb = len_lb - posunderlb - 1;
	i = 0;
	if (posunderlb <= costdown)
	{
		while (i < posunderlb)
		{
			tl = fct_rotate_reverse_arg(tl, 'r');
			i++;
		}
		while (i < costdown)
		{
			tl = fct_rotate_reverse_arg(tl, 'a');
			i++;
		}
	}
	else if (posunderlb > costdown && posunderlb - costdown <= len_lb - posunderlb)
	{
		while (i < costdown)
		{
			tl = fct_rotate_reverse_arg(tl, 'r');
			i++;
		}
	}
	else
	{
		while (i < costdown)
		{
			tl = fct_rotate_reverse_arg(tl, 'a');
			i++;
		}
	}
	return (tl);
}
t_tablist	*ft_rotatelesscost(t_tablist *tl, int costup, int costdown)
{
	int nbr_la;
	int	posunderlb;

	posunderlb = 0;
	if (count_list(tl, 'b') > 0)
		posunderlb = ft_findpos(tl, 'b', ft_findhigher(tl, 'b'));
	if (costup <= costdown)
	{
		nbr_la = ft_findnbr(tl, 'a', costup);
		//printf("costup in la : %d\n", costup);
		//printf("nbr in la : %d\n", nbr_la);
		//if (count_list(tl, 'b') > 1)
		//	posunderlb = ft_findpos(tl, 'b', ft_findinferior(tl->lb, nbr_la));
		//if (count_list(tl, 'b') > 0)
		//	printf("nbr superior in lb: %d - place in lb: %d\n", ft_findinferior(tl->lb, nbr_la), posunderlb);
		tl = ft_rotateup(tl, costup, posunderlb);
	}
	if (costdown < costup)
	{
		nbr_la = ft_findnbr(tl, 'a', count_list(tl, 'a') - costdown);
		//printf("costdown in la : %d\n", costdown);
		//printf("nbr in la : %d\n", nbr_la);
		//if (count_list(tl, 'b') > 1)
		//	posunderlb = ft_findpos(tl, 'b', ft_findinferior(tl->lb, nbr_la));
		//if (count_list(tl, 'b') > 0)
		//	printf("nbr superior in lb: %d - place in lb: %d\n", ft_findinferior(tl->lb, nbr_la), posunderlb);
		tl = ft_rotatedown(tl, costdown, posunderlb);
	}
	tl = fct_push_arg(tl, 'b');
	return (tl);
}
