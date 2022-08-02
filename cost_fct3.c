/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_fct3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <nle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 14:12:00 by nle-bret          #+#    #+#             */
/*   Updated: 2022/08/02 18:00:16 by nle-bret         ###   ########.fr       */
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
	nbr_ret = NULL;
	while (tmp)
	{
		num = tmp->content;
		if (num < nbr)
		{
			nbr_ret = num;
			//printf("first loop nbr_ret %d\n", nbr_ret);
		}
		tmp = tmp->next;
	}
	tmp = list;
	while (tmp)
	{
		num = tmp->content;
		//printf("nbr %d tmp->content %d nbr-ret%d\n", nbr, num, nbr_ret);
		if (nbr_ret < num && num < nbr)
		{
			nbr_ret = num;
			//printf("second loop nbr_ret %d\n", nbr_ret);
		}
		tmp = tmp->next;
	}
	return (nbr_ret);
}
