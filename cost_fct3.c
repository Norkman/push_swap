/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_fct3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <nle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 14:12:00 by nle-bret          #+#    #+#             */
/*   Updated: 2022/08/05 16:06:41 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
int	ft_findnbr(t_tablist *tl, char arg, int pos)
{
	t_list	*tmp;
	int		i;

	i = 0;
	if (arg == 'a')
		tmp = tl->la;
	if (arg == 'b')
		tmp = tl->lb;
	while (i < pos)
	{
		tmp = tmp->next;
		i++;
	}
	return (tmp->content);
}

int	ft_findinferior(t_list *list, int nbr)
{
	t_list	*tmp;
	int		i;
	int		nbr_ret;
	int		num;

	i = 0;
	tmp = list;
	while (tmp)
	{
		num = tmp->content;
		if (num < nbr)
			nbr_ret = num;
		tmp = tmp->next;
		i++;
	}
	tmp = list;
	while (tmp)
	{
		num = tmp->content;
		if (nbr_ret < num && num < nbr)
			nbr_ret = num;
		tmp = tmp->next;
	}
	if (i == 0)
		nbr_ret = list->content;
	return (nbr_ret);
}

int	ft_findsuperior(t_list *list, int nbr)
{
	t_list	*tmp;
	int		i;
	int		nbr_ret;
	int		num;

	i = 0;
	tmp = list;
	while (tmp)
	{
		num = tmp->content;
		if (num > nbr)
			nbr_ret = num;
		tmp = tmp->next;
		i++;
	}
	tmp = list;
	while (tmp)
	{
		num = tmp->content;
		if (nbr_ret > num && num > nbr)
			nbr_ret = num;
		tmp = tmp->next;
	}
	if (i == 0)
		nbr_ret = list->content;
	return (nbr_ret);
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
	//printf("pos in lb : %d - pos in la under : %d\n", d.pos, d.up_o);
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
			if (d.len_la - d.pos <= d.len_lb - d.up_o)
				cost = d.len_lb - d.pos;
			else 
				cost = d.len_la - d.up_o;
		}
		tmpb = tmpb->next;
	}
	return (cost);
}
