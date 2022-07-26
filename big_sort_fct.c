/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_fct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <nle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:41:12 by nle-bret          #+#    #+#             */
/*   Updated: 2022/07/26 09:48:43 by nle-bret         ###   ########.fr       */
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

t_tablist	*ft_putnbrofbox(t_tablist *tl, int box)
{
	int	costup;
	int costdown;
	int	len_la;
	int	i;

	i = 0;
	len_la = count_list(tl, 'a');
	while (i < len_la)
	{
		costup = ft_findcostup(tl, box, len_la);
		costdown = ft_findcostdown(tl, box, len_la);
		tl = ft_rotatelesscost(tl, costup, costdown);
		i++;
	}
	return (tl);
}
