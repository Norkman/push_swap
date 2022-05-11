/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <nle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 18:05:57 by nle-bret          #+#    #+#             */
/*   Updated: 2022/05/11 18:57:37 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_findhigher(t_list *list)
{
	t_list	*tmpi;
	t_list	*tmpj;
	int	nbr;

	tmpi = list;
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

int	ft_findpos(t_list *list, int nbr)
{
	int	pos;
	t_list	*tmp;

	tmp = list;
	pos = 0;
	while (list)
	{
		if (tmp->content == nbr)
			return (pos);
		pos++;
		tmp = tmp->next;
	}
	return (pos);
}

t_list *ft_higher_up(t_list *list)
{
	int		nbr;
	int		len;
	int		pos;
	t_list	*tmp;

	tmp = list;
	len = count_list(list);
	nbr = ft_findhigher(list);
	pos = ft_findpos(list, nbr);
	if (pos <= len - pos)
	{
		while (pos > 0)
		{
			list = fct_rotate(list);
			pos--;
		}
	}
	else
	{
		while (pos < len)
		{
			list = fct_rotate_reverse(list);
			pos ++;
		}
	}
	return (list);
}
