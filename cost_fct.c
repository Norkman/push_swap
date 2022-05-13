/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <nle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 18:05:57 by nle-bret          #+#    #+#             */
/*   Updated: 2022/05/12 08:57:37 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_findpos(t_tablist *tl, char arg, int nbr)
{
	int	pos;
	t_list	*tmp;

	if (arg == 'a')
		tmp = tl->la;
	else if (arg == 'b')
		tmp = tl->lb;
	pos = 0;
	while (tmp)
	{
		if (tmp->content == nbr)
			return (pos);
		pos++;
		tmp = tmp->next;
	}
	return (pos);
}

int ft_findlower(t_tablist *tl, char arg)
{
	t_list	*tmpi;
	t_list	*tmpj;
	int	nbr;

	if (arg == 'a')
		tmpi = tl->la;
	if (arg == 'b')
		tmpi = tl->lb;
	nbr = tmpi->content;
	while (tmpi->next)
	{
		tmpj = tmpi->next;
		while (tmpj)
		{
			if (nbr > tmpj->content)
				nbr = tmpj->content;
			tmpj = tmpj->next;
		}
		tmpi = tmpi->next;
	}
	return (nbr);
}

int ft_findhigher(t_tablist *tl, char arg)
{
	t_list	*tmpi;
	t_list	*tmpj;
	int	nbr;

	if (arg == 'a')
		tmpi = tl->la;
	if (arg == 'b')
		tmpi = tl->lb;
	nbr = tmpi->content;
	while (tmpi->next)
	{
		tmpj = tmpi->next;
		while (tmpj)
		{
			if (nbr < tmpj->content)
				nbr = tmpj->content;
			tmpj = tmpj->next;
		}
		tmpi = tmpi->next;
	}
	return (nbr);
}

t_tablist *ft_lower_up(t_tablist *tl, char arg)
{
	int		pos;
	int		len;

	if (arg == 'a')
		len = count_list(tl, 'a');
	else if (arg == 'b')
		len = count_list(tl, 'a');
	pos = ft_findpos(tl, arg, ft_findlower(tl, arg));
	if (pos <= len - pos)
	{
		while (pos-- > 0)
			tl = fct_rotate_arg(tl, arg);
	}
	else
	{
		while (pos++ < len)
			tl = fct_rotate_reverse_arg(tl, arg);
	}
	return (tl);
}

t_tablist *ft_higher_up(t_tablist *tl, char arg)
{
	int		pos;
	int		len;

	if (arg == 'a')
		len = count_list(tl, 'a');
	else if (arg == 'b')
		len = count_list(tl, 'b');
	pos = ft_findpos(tl, arg, ft_findhigher(tl, arg));
	if (pos <= len - pos)
	{
		while (pos-- > 0)
			tl = fct_rotate_arg(tl, arg);
	}
	else
	{
		while (pos++ < len)
			tl = fct_rotate_reverse_arg(tl, arg);
	}
	return (tl);
}
