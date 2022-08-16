#include "push_swap.h"

t_tablist	*ft_rotatecostup(t_tablist *tl, t_data d)
{
	int i;

	i = 0;
	if (d.pos <= d.up_o)
	{
		while (i++ < d.pos)
			tl = fct_rotate_arg(tl, 'r');
		i = d.pos;
		while (i++ < d.up_o)
			tl = fct_rotate_arg(tl, 'a');
	}
	if (d.up_o < d.pos)
	{
		while (i++ < d.up_o)
			tl = fct_rotate_arg(tl, 'r');
		i = d.up_o;
		while (i++ < d.pos)
			tl = fct_rotate_arg(tl, 'b');
	}
	return (tl);
 }

t_tablist	*ft_rotateupalt(t_tablist *tl, int cost, int len)
{
	t_list	*tmpb;
	t_data	d;

	tmpb = tl->lb;
	while (tmpb)
	{
		d = ft_m_d_la(tl, tmpb->content);
		if (cost == d.pos && d.pos >= d.up_o)
			break ;
		if (cost == d.up_o && d.pos <= d.up_o)
			break ;
		tmpb = tmpb->next;
	}
	tl = ft_rotatecostup(tl, d);
	return (tl);
}

t_tablist	*ft_rotatecostdown(t_tablist *tl, t_data d)
{
	int i;

	d.up_o = d.len_la - d.up_o;
	d.pos = d.len_lb - d.pos;
	i = 0;
	if (d.pos <= d.up_o)
	{
		while (i++ < d.pos)
			tl = fct_rotate_reverse_arg(tl, 'r');
		i = d.pos;
		while (i++ < d.up_o)
			tl = fct_rotate_reverse_arg(tl, 'a');
	}
	if (d.up_o < d.pos)
	{
		while (i++ < d.up_o)
			tl = fct_rotate_reverse_arg(tl, 'r');
		i = d.up_o;
		while (i++ < d.pos)
			tl = fct_rotate_reverse_arg(tl, 'b');
	}
	return (tl);
}

t_tablist	*ft_rotatedownalt(t_tablist *tl, int cost, int len)
{
	t_list	*tmpb;
	t_data	d;

	tmpb = tl->lb;
	while (tmpb)
	{
		d = ft_m_d_la(tl, tmpb->content);
		if (cost == d.len_lb - d.pos && d.len_lb - d.pos >= d.len_la - d.up_o)
			break ;
		if (cost == d.len_la - d.up_o && d.len_lb - d.pos <= d.len_la - d.up_o)
			break ;
		tmpb = tmpb->next;
	}
	tl = ft_rotatecostdown(tl, d);
	return (tl);
}
