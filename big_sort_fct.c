/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_fct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <nle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:41:12 by nle-bret          #+#    #+#             */
/*   Updated: 2022/07/29 17:50:33 by nle-bret         ###   ########.fr       */
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

t_tablist	*ft_putnbrofbox(t_tablist *tl, int box, int rest_box)
{
	int	costup;
	int costdown;
	int	len_la;
	int rest_nbr_box;
	int poslowerlb;

	len_la = count_list(tl, 'a');
	while (count_list(tl, 'a') != 0)
	{
		rest_nbr_box = count_list(tl, 'a') % (len_la / box);
			if (rest_nbr_box == 0)
				rest_nbr_box = len_la / box;
			if (rest_nbr_box < (len_la / box) / 4)
				rest_nbr_box = (len_la / box) / 4;
		costup = ft_findcostup(tl, rest_nbr_box);
		costdown = ft_findcostdown(tl, rest_nbr_box);
		if (count_list(tl, 'b') == 0)
			poslowerlb = 0;
		else
			//poslowerlb = 0;
			poslowerlb = ft_findpos(tl, 'b', ft_findlower(tl, 'b'));
		//printf_list(tl->la);
		//ft_printf("rest : %d -- nbr per box : %d\n", rest_nbr_box, len_la / box);
		//ft_printf("cost down : %d - cost up : %d - cost up for lb : %d\n", costdown, costup, poslowerlb);
		tl = ft_rotatelesscost(tl, costup, costdown, poslowerlb);
		//ft_printf("num : %d\n", tl->lb->content);
	}
	return (tl);
}
