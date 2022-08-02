/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_fct2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <nle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 11:28:52 by nle-bret          #+#    #+#             */
/*   Updated: 2022/08/02 18:28:12 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		if (ft_howmanyover(tl->la, nbr) <= rest_nbr_box)
			cost = ft_findpos(tl, 'a', nbr);
		tmp = tmp->next;
	}
	return (count_list(tl, 'a') - cost);
}

t_tablist	*ft_rotateup(t_tablist *tl, int costup, int poslowerlb)
{
	int i;
	int	len_lb;

	len_lb = count_list(tl, 'b');
	i = 0;
	if (poslowerlb <= costup)
	{
		while (i < poslowerlb)
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
	else if (poslowerlb > costup && poslowerlb - costup <= len_lb - poslowerlb)
	{
		while (i < costup)
		{
			tl = fct_rotate_arg(tl, 'r');
			i++;
		}
		while (i < poslowerlb)
		{
			tl = fct_rotate_arg(tl, 'b');
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

t_tablist	*ft_rotatedown(t_tablist *tl, int costdown, int poslowerlb)
{
	int i;
	int	len_lb;

	len_lb = count_list(tl, 'b');
	poslowerlb = len_lb - poslowerlb -1;
	i = 0;
	if (poslowerlb <= costdown)
	{
		while (i < poslowerlb)
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
	else if (poslowerlb > costdown && poslowerlb - costdown <= len_lb - poslowerlb)
	{
		while (i < costdown)
		{
			tl = fct_rotate_reverse_arg(tl, 'r');
			i++;
		}
		while (i < poslowerlb)
		{
			tl = fct_rotate_reverse_arg(tl, 'b');
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
	/*
	else if (poslowerlb > costdown && poslowerlb - costdown > len_lb - poslowerlb)
	{
		while (i < costdown)
		{
			tl = fct_rotate_reverse_arg(tl, 'a');
			i++;
		}
		i = 0;
		while (i < poslowerlb)
		{
			tl = fct_rotate_arg(tl, 'b');
			i++;
		}
	}
	*/
	/*
	if (poslowerlb > 0)
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
	*/
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
		if (count_list(tl, 'b') < 2)
			poslowerlb = 0;
		else
			poslowerlb = ft_findpos(tl, 'b', ft_findinferior(tl->lb, nbr_la));
		//printf("nbr inferior in lb: %d - place in lb: %d\n", ft_findinferior(tl->lb, nbr_la), poslowerlb);
		tl = ft_rotateup(tl, costup, poslowerlb);
	}
	if (costdown < costup)
	{
		nbr_la = ft_findnbr(tl, 'a', count_list(tl, 'a') - costdown);
		//printf("costdown in la : %d\n", costdown);
		//printf("nbr in la : %d\n", nbr_la);
		if (count_list(tl, 'b') < 2)
			poslowerlb = 0;
		else
			poslowerlb = ft_findpos(tl, 'b', ft_findinferior(tl->lb, nbr_la));
		//printf("nbr inferior in lb: %d - place in lb: %d\n", ft_findinferior(tl->lb, nbr_la), poslowerlb);
		tl = ft_rotatedown(tl, costdown, poslowerlb);
	}
	tl = fct_push_arg(tl, 'b');
	return (tl);
}
