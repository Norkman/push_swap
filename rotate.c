/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <nle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 11:28:52 by nle-bret          #+#    #+#             */
/*   Updated: 2022/08/05 17:50:37 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_tablist	*ft_rotateup(t_tablist *tl, int costup)
{
	int	i;

	i = 0;
	while (i < costup)
	{
		tl = fct_rotate_arg(tl, 'a');
		i++;
	}
	return (tl);
}

t_tablist	*ft_rotatedown(t_tablist *tl, int costdown)
{
	int	i;

	i = 0;
	while (i < costdown)
	{
		tl = fct_rotate_reverse_arg(tl, 'a');
		i++;
	}
	return (tl);
}

t_tablist	*ft_lower_up(t_tablist *tl, char arg)
{
	int		pos;
	int		len;

	if (arg == 'a')
		len = count_list(tl, 'a');
	else if (arg == 'b')
		len = count_list(tl, 'b');
	pos = ft_findpos(tl, arg, ft_findlower(tl, arg));
	if (pos <= len - pos)
	{
		while (pos-- > 0)
			tl = fct_rotate_arg(tl, arg);
	}
	else
	{
		while (pos++ < len)
			tl = fct_rotate_reverse_arg(tl, arg);
	}
	return (tl);
}

t_tablist	*ft_higher_up(t_tablist *tl, char arg)
{
	int		pos;
	int		len;

	if (arg == 'a')
		len = count_list(tl, 'a');
	else if (arg == 'b')
		len = count_list(tl, 'b');
	pos = ft_findpos(tl, arg, ft_findhigher(tl, arg));
	if (pos <= len - pos)
	{
		while (pos-- > 0)
			tl = fct_rotate_arg(tl, arg);
	}
	else
	{
		while (pos++ < len)
			tl = fct_rotate_reverse_arg(tl, arg);
	}
	return (tl);
}

t_tablist	*ft_rotatelesscost(t_tablist *tl, t_cost cost, int len)
{
	int	nbr_la;

	if (cost.up <= cost.down
		&& cost.up <= cost.updown
		&& cost.up <= cost.downup)
		tl = ft_rotateupalt(tl, cost.up, len);
	else if (cost.down <= cost.up
		&& cost.down <= cost.updown
		&& cost.down <= cost.downup)
		tl = ft_rotatedownalt(tl, cost.down, len);
	else if (cost.updown <= cost.down
		&& cost.updown <= cost.up
		&& cost.updown <= cost.downup)
		tl = ft_rotateupdown(tl, cost.updown, len);
	else if (cost.downup <= cost.down
		&& cost.downup <= cost.updown
		&& cost.downup <= cost.up)
		tl = ft_rotatedownup(tl, cost.downup, len);
	tl = fct_push_arg(tl, 'a');
	return (tl);
}
