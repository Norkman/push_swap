
#include "push_swap.h"

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
	//d.pos = d.len_lb - d.pos;
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
	//d.up_o = d.len_la - d.up_o;
	d.pos = d.len_lb - d.pos;
	tl = ft_rotatecostupdown(tl, d);
	return (tl);
}

int	ft_howcostupdown(t_tablist *tl, int len)
{
	t_list	*tmpb;
	int		costall;
	int		cost;
	t_data	d;

	costall = len;
	cost = len;
	tmpb = tl->lb;
	while (tmpb)
	{
		d = ft_m_d_la(tl, tmpb->content);
		if (costall > d.up_o + (d.len_lb - d.pos))
		{
			costall = d.up_o + (d.len_lb - d.pos);
			if (d.len_lb - d.pos >= d.up_o)
				cost = d.len_lb - d.pos;
			else 
				cost = d.up_o;
		}
		tmpb = tmpb->next;
	}
	return (cost);
}

int	ft_howcostdownup(t_tablist *tl, int len)
{
	t_list	*tmpb;
	int		costall;
	int		cost;
	t_data	d;

	costall = len;
	cost = len;
	tmpb = tl->lb;
	while (tmpb)
	{
		d = ft_m_d_la(tl, tmpb->content);
		if (costall > d.pos + (d.len_la - d.up_o))
		{
			costall = d.pos + (d.len_la - d.up_o);
			if (d.pos >= d.len_la - d.up_o)
				cost = d.pos;
			else 
				cost = d.len_la - d.up_o;
		}
		tmpb = tmpb->next;
	}
	return (cost);
}
