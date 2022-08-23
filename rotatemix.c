/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotatemix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <nle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 11:28:52 by nle-bret          #+#    #+#             */
/*   Updated: 2022/08/05 17:50:37 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

t_tablist	*ft_rotatecostdownup(t_tablist *tl, t_data d)
{
	int	i;

	i = 0;
	while (i++ < d.pos)
		tl = fct_rotate_arg(tl, 'b');
	i = 0;
	while (i++ < d.up_o)
		tl = fct_rotate_reverse_arg(tl, 'a');
	return (tl);
}

t_tablist	*ft_rotatecostupdown(t_tablist *tl, t_data d)
{
	int	i;

	i = 0;
	while (i++ < d.pos)
		tl = fct_rotate_reverse_arg(tl, 'b');
	i = 0;
	while (i++ < d.up_o)
		tl = fct_rotate_arg(tl, 'a');
	return (tl);
}

//////

t_tablist	*ft_rotatedownup(t_tablist *tl, int cost, int len)
{
	t_list	*tmpb;
	t_data	d;

	tmpb = tl->lb;
	while (tmpb)
	{
		d = ft_m_d_la(tl, tmpb->content);
		if (cost == d.pos && d.pos >= d.len_la - d.up_o)
			break ;
		if (cost == d.len_la - d.up_o && d.pos <= d.len_la - d.up_o)
			break ;
		tmpb = tmpb->next;
	}
	d.up_o = d.len_la - d.up_o;
	tl = ft_rotatecostdownup(tl, d);
	return (tl);
}

t_tablist	*ft_rotateupdown(t_tablist *tl, int cost, int len)
{
	t_list	*tmpb;
	t_data	d;

	tmpb = tl->lb;
	while (tmpb)
	{
		d = ft_m_d_la(tl, tmpb->content);
		if (cost == d.len_lb - d.pos && d.len_lb - d.pos >= d.up_o)
			break ;
		if (cost == d.up_o && d.len_lb - d.pos <= d.up_o)
			break ;
		tmpb = tmpb->next;
	}
	d.pos = d.len_lb - d.pos;
	tl = ft_rotatecostupdown(tl, d);
	return (tl);
}
