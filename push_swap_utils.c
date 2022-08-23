/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <nle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 09:48:28 by nle-bret          #+#    #+#             */
/*   Updated: 2022/08/03 17:32:10 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_data	ft_m_d_la(t_tablist *tl, int nbr)
{
	t_data	data;
	int		num;
	int		num_sup;

	num = nbr;
	data.pos = ft_findpos(tl, 'b', num);
	num_sup = ft_findsuperior(tl->la, nbr);
	data.up_o = ft_findpos(tl, 'a', num_sup);
	data.len_la = count_list(tl, 'a');
	data.len_lb = count_list(tl, 'b');
	return (data);
}

int	ft_howmanyunder(t_list *list, int nbr)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = list;
	while (tmp)
	{
		if (nbr > tmp->content)
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
		if (ft_howmanyunder(tl->la, nbr) == len / 2)
			return (nbr);
		tmp = tmp->next;
	}
	return (0);
}
