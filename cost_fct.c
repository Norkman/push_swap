/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_fct.                                          :+:      :+:    :+:   */
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

int	ft_howcostup(t_tablist *tl, int len)
{
	t_list	*tmpb;
	int		costall;
	int		cost;
	t_data	d;

	costall = len;
	cost = len;
	tmpb = tl->lb;
	while (tmpb)
	{
		d = ft_m_d_la(tl, tmpb->content);
		if (costall > d.pos + d.up_o)
		{
			costall = d.pos + d.up_o;
			if (d.pos >= d.up_o)
				cost = d.pos;
			else
				cost = d.up_o;
		}
		tmpb = tmpb->next;
	}
	return (cost);
}

int	ft_howcostdown(t_tablist *tl, int len)
{
	t_list	*tmpb;
	int		costall;
	int		cost;
	t_data	d;

	costall = len;
	cost = len;
	tmpb = tl->lb;
	while (tmpb)
	{
		d = ft_m_d_la(tl, tmpb->content);
		if (costall > len - (d.pos + d.up_o))
		{
			costall = len - (d.pos + d.up_o);
			if (d.len_lb - d.pos >= d.len_la - d.up_o)
				cost = d.len_lb - d.pos;
			else
				cost = d.len_la - d.up_o;
		}
		tmpb = tmpb->next;
	}
	return (cost);
}
