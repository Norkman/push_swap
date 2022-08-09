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
	int		pos_under_lb;
	int		num_under_lb;
	int		posinlb;
	int		cost;

	cost = len;
	tmpb = tl->lb;
	posinlb = 0;
	while (tmpb)
	{
		num_under_lb = ft_findsuperior(tl->la, tl->lb->content);
		pos_under_lb = ft_findpos(tl, 'a', num_under_lb);
			if (cost > (posinlb + pos_under_lb))
				cost = posinlb + pos_under_lb;
		tmpb = tmpb->next;
		posinlb++;
	}
	return (cost);
}

int	ft_howcostdown(t_tablist *tl, int len)
{
	t_list	*tmpb;
	int		pos_under_lb;
	int		num_under_lb;
	int		posinlb;
	int		cost;

	cost = len;
	tmpb = tl->lb;
	posinlb = 0;
	while (tmpb)
	{
		num_under_lb = ft_findsuperior(tl->la, tl->lb->content);
		pos_under_lb = ft_findpos(tl, 'a', num_under_lb);
			if (cost > len - (posinlb + pos_under_lb) - 1)
				cost = len - (posinlb + pos_under_lb - 1);
		tmpb = tmpb->next;
		posinlb++;
	}
	return (cost);
}
