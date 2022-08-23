/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <nle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 18:05:57 by nle-bret          #+#    #+#             */
/*   Updated: 2022/08/05 16:27:22 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_findpos(t_tablist *tl, char arg, int nbr)
{
	int		pos;
	t_list	*tmp;

	if (arg == 'a')
		tmp = tl->la;
	if (arg == 'b')
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

int	ft_findlower(t_tablist *tl, char arg)
{
	t_list	*tmpi;
	t_list	*tmpj;
	int		nbr;

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

int	ft_findhigher(t_tablist *tl, char arg)
{
	t_list	*tmpi;
	t_list	*tmpj;
	int		nbr;

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
