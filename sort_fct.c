/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_fct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <nle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:14:38 by nle-bret          #+#    #+#             */
/*   Updated: 2022/08/05 17:10:00 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_tablist	*ft_sort_three(t_tablist *tl)
{
	char	*list_fct;

	while (tl && count_list(tl, 'a') == 3)
	{
		if (tl->la->content < tl->la->next->content
			&& tl->la->next->content < tl->la->next->next->content)
			return (tl);
		if (tl->la->content > tl->la->next->content
			&& tl->la->next->content < tl->la->next->next->content
			&& tl->la->content > tl->la->next->next->content)
			tl = fct_rotate_arg(tl, 'a');
		if (tl->la->content > tl->la->next->content
			&& tl->la->next->content < tl->la->next->next->content)
			tl = fct_swap_arg(tl, 'a');
		if (tl->la->content > tl->la->next->content
			&& tl->la->next->content > tl->la->next->next->content)
			tl = fct_rotate_arg(tl, 'a');
		if (tl->la->content < tl->la->next->content
			&& tl->la->next->content > tl->la->next->next->content)
			tl = fct_rotate_reverse_arg(tl, 'a');
	}
	return (tl);
}

t_tablist	*ft_sort_under_five(t_tablist *tl)
{
	int	len_la;

	if (ft_is_sorted(tl, 'a') == 0)
		exit(0);
	len_la = count_list(tl, 'a');
	tl = ft_lower_up(tl, 'a');
	tl = fct_push_arg(tl, 'b');
	if (len_la == 5)
	{
		tl = ft_higher_up(tl, 'a');
		tl = fct_push_arg(tl, 'b');
	}
	tl = ft_sort_three(tl);
	if (len_la == 5)
	{
		tl = fct_push_arg(tl, 'a');
		tl = fct_rotate_arg(tl, 'a');
	}
	tl = fct_push_arg(tl, 'a');
	return (tl);
}

t_tablist	*ft_sort_under_seventy(t_tablist *tl)
{
	while (count_list(tl, 'a') > 0)
		tl = ft_putinlb(tl);
	tl = ft_higher_up(tl, 'b');
	while (count_list(tl, 'b') > 0)
		tl = fct_push_arg(tl, 'a');
	return (tl);
}

t_tablist	*ft_sort_under_fivehundred(t_tablist *tl)
{
	int	box;
	int	num_up_la;
	int	len;
	int	pos_up;

	len = count_list(tl, 'a');
	box = len / 100 + 1;
	tl = ft_putnbrofbox(tl, box);
	while (count_list(tl, 'b') > 1)
		tl = ft_sortinla(tl, len);
	pos_up = ft_findpos(tl, 'a', ft_findsuperior(tl->la, tl->lb->content));
	if (pos_up < (len - 1) / 2)
	{
		while (pos_up-- > 0)
			tl = fct_rotate_arg(tl, 'a');
	}
	else
		while (pos_up++ < len - 1)
			tl = fct_rotate_reverse_arg(tl, 'a');
	tl = fct_push_arg(tl, 'a');
	tl = ft_lower_up(tl, 'a');
	return (tl);
}
