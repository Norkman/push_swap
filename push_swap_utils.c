/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <nle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:14:38 by nle-bret          #+#    #+#             */
/*   Updated: 2022/05/11 14:51:09 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_tablist	*ft_sort_three(t_tablist *tl)
{
	char	*list_fct;
	
	while (tl && count_list(tl->la) == 3)
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
	int 	len_la;

	len_la = count_list(tl->la);
	if (ft_isbigger(tl->la) == 0)
		fct_rotate_arg(tl, 'a');
	if (len_la < 3)
		return (tl);
	if (len_la == 5)
		tl == fct_push_arg(tl, 'b');
	tl = fct_push_arg(tl, 'b');
	tl = ft_sort_three(tl);
	if (ft_is_sorted(tl->lb) == 1)
		fct_swap_arg(tl, 'b');
	while (count_list(tl->la) != len_la)
	{
		if (tl->la->content > tl->lb->content)
			fct_push_arg(tl, 'a');
		else
			fct_rotate_arg(tl, 'a');
	}
	while (ft_is_sorted(tl->la) == 1)
		fct_rotate_reverse_arg(tl, 'a');
	return (tl);
}
