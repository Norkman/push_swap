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

t_tablist	*ft_rotateup(t_tablist *tl, int costup)
{
	int i;

	i = 0;
	while (i < costup)
	{
		tl = fct_rotate_arg(tl, 'a');
		i++;
	}
	return (tl);
}
t_tablist	*ft_rotatedown(t_tablist *tl, int costdown)
{
	int i;

	i = 0;
	while (i < costdown)
	{
		tl = fct_rotate_reverse_arg(tl, 'a');
		i++;
	}
	return (tl);
}
t_tablist	*ft_rotatelesscost(t_tablist *tl, t_cost cost, int len)
{
	int nbr_la;

	if (cost.up <= cost.down && cost.up <= cost.updown && cost.up <= cost.downup)
		tl = ft_rotateupalt(tl, cost.up, len);
	else if(cost.down <= cost.up && cost.down <= cost.updown && cost.down <= cost.downup)
		tl = ft_rotatedownalt(tl, cost.down, len);
	else if(cost.updown <= cost.down && cost.updown <= cost.up && cost.updown <= cost.downup)
		tl = ft_rotateupdown(tl, cost.updown, len);
	else if(cost.downup <= cost.down && cost.downup <= cost.updown && cost.downup <= cost.up)
		tl = ft_rotatedownup(tl, cost.downup, len);
	/*
	if (cost.up <= cost.down)
	{
		tl = ft_rotateupalt(tl, cost.up, len);
	}
	if (cost.up > cost.down)
	{
		tl = ft_rotatedownalt(tl, cost.down, len);
	}
	if (cost.updown <= cost.downup)
	{
		tl = ft_rotateupdown(tl, cost.updown, len);
	}
	if (cost.downup < cost.updown)
	{
		tl = ft_rotatedownup(tl, cost.downup, len);
	}
	*/
	tl = fct_push_arg(tl, 'a');
	return (tl);
}

