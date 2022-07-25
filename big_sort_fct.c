/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_fct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <nle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:41:12 by nle-bret          #+#    #+#             */
/*   Updated: 2022/07/25 16:47:17 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_tablist	*ft_choicerotate(t_tablist *tl, int costh, int costl)
{
	if (costh <= costl)
	{
		tl = ft_higher_up(tl, 'a');
		tl = fct_push_arg(tl, 'b');
		tl = fct_rotate_arg(tl, 'b');
	}
	else
	{
		tl = ft_lower_up(tl, 'a');
		tl = fct_push_arg(tl, 'b');
	}
	return (tl);
}

t_tablist	*ft_putinlb(t_tablist *tl)
{
	int costh;
	int costl;
	int posh;
	int posl;

	posl = ft_findpos(tl, 'a', ft_findlower(tl, 'a'));
	posh = ft_findpos(tl, 'a', ft_findhigher(tl, 'a'));

	if (posl <= count_list(tl, 'a') - posl)
		costl = posl;
	else
		costl = count_list(tl, 'a') - posl;
	if (posh <= count_list(tl, 'a') - posh)
		costh = posh;
	else
		costh = count_list(tl, 'a') - posh;
	tl = ft_choicerotate(tl, costh, costl);
	return (tl);
}
