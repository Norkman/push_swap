/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <nle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 09:48:28 by nle-bret          #+#    #+#             */
/*   Updated: 2022/07/26 12:57:28 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_howmanyover(t_list *list, int nbr)
{
	t_list	*tmp;
	int		i;

	i = 0;

	tmp = list;
	while (tmp)
	{
		if (nbr < tmp->content)
			i++;
		tmp = tmp->next;
	}
	return (i);
}

int	ft_med_list(t_tablist *tl)
{
	int		nbr;
	int		len;
	t_list	*tmp;

	len = count_list(tl, 'a');
	tmp = tl->la;
	while (tmp)
	{
		nbr = tmp->content;
		//printf("num : %d --> %d\n", nbr, ft_howmanyover(tl->la, nbr));
			if (ft_howmanyover(tl->la, nbr) == len / 2)
				return (nbr);
		tmp = tmp->next;
	}
	return (0);
}

t_tablist	*ft_putbox(t_tablist *tl, int box)
{
	int		i;
	t_list	*tmp;

	tmp = tl->la;
	i = 1;
	while (i <= box)
	{
		tl = ft_putnbrofbox(tl, box);
		i++;
	}
	return (tl);
}
