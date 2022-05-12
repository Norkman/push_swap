/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <nle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:41:12 by nle-bret          #+#    #+#             */
/*   Updated: 2022/05/12 16:07:02 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_tablist	*ft_putinlb(t_tablist *tl)
{
	int costh;
	int costl;

	if (ft_findlower(tl, 'a') <= count_list(tl, 'a') - ft_findlower(tl, 'a'))
		costl = ft_findlower(tl, 'a');
	else
		costl = ft_findlower(tl, 'a') - ft_findlower(tl, 'a');
	if (ft_findhigher(tl, 'a') <= count_list(tl, 'a') - ft_findhigher(tl, 'a'))
		costh = ft_findhigher(tl, 'a');
	else
		costh = ft_findhigher(tl, 'a') - ft_findhigher(tl, 'a');
	if (costh <= costl)
	{
		tl = ft_higher_up(tl, 'a');
		tl = fct_push_arg(tl, 'b');
	}
	else
	{
		tl =ft_lower_up(tl, 'a');
		tl = fct_push_arg(tl, 'b');
		tl = fct_rotate_arg(tl, 'b');
	}
	return (tl);
}
