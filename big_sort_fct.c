/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_fct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <nle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:41:12 by nle-bret          #+#    #+#             */
/*   Updated: 2022/08/05 17:50:01 by nle-bret         ###   ########.fr       */
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
	int	costh;
	int	costl;
	int	posh;
	int	posl;

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

t_tablist	*ft_putinlbalt(t_tablist *tl)
{
	int	numhigher;
	int	num;

	numhigher = ft_findhigher(tl, 'a');
	while (count_list(tl, 'a') > 2)
	{
		num = tl->la->content;
		if (num == numhigher)
			tl = fct_rotate_arg(tl, 'a');
		else
			tl = fct_push_arg(tl, 'b');
	}
	return (tl);
}

t_tablist	*ft_putnbrofbox(t_tablist *tl, int box)
{
	int	costup;
	int	len_la;
	int	rest_nbr_box;
	int	nbr_la;
	int	num_higher;

	len_la = count_list(tl, 'a');
	num_higher = ft_findhigher(tl, 'a');
	while (count_list(tl, 'a') != 2)
	{
		rest_nbr_box = count_list(tl, 'a') % (len_la / box);
		if (rest_nbr_box == 0)
			rest_nbr_box = len_la / box;
		costup = ft_findcostup(tl, rest_nbr_box);
		nbr_la = ft_findnbr(tl, 'a', costup);
		tl = ft_rotateup(tl, costup);
		if (tl->la->content == num_higher)
			tl = fct_rotate_arg(tl, 'a');
		else
			tl = fct_push_arg(tl, 'b');
	}
	return (tl);
}

t_tablist	*ft_sortinla(t_tablist *tl, int len)
{
	t_cost	cost;

	cost.updown = ft_howcostupdown(tl, len);
	cost.downup = ft_howcostdownup(tl, len);
	cost.up = ft_howcostup(tl, len);
	cost.down = ft_howcostdown(tl, len);
	tl = ft_rotatelesscost(tl, cost, len);
	return (tl);
}
