#include "push_swap.h"

t_tablist	*ft_rotatecostup(t_tablist *tl, int posinlb, int pos_under_lb)
{
	int i;

	i = 0;
	if (posinlb <= pos_under_lb)
	{
		while (i++ < posinlb)
			tl = fct_rotate_arg(tl, 'r');
		i = posinlb;
		while (i++ < pos_under_lb)
			tl = fct_rotate_arg(tl, 'a');
	}
	i = 0;
	if (pos_under_lb < posinlb)
	{
		while (i++ < pos_under_lb)
			tl = fct_rotate_arg(tl, 'r');
		while (i++ < posinlb)
			tl = fct_rotate_arg(tl, 'b');
	}
	return (tl);
 }

t_tablist	*ft_rotateupalt(t_tablist *tl, int cost, int len)
{
	t_list	*tmpb;
	int		pos_und;
	int		posinlb;

	tmpb = tl->lb;
	posinlb = 0;
	while (tmpb)
	{
		pos_und = ft_findpos(tl, 'a', ft_findsuperior(tl->la, tl->lb->content));
		if (cost == posinlb && posinlb >= pos_und)
			break ;
		if (cost == pos_und && posinlb <= pos_und)
			break ;
		tmpb = tmpb->next;
		posinlb++;
	}
	//printf("posinlb : %d - pos_und : %d\n", posinlb, pos_und);
	tl = ft_rotatecostup(tl, posinlb, pos_und);
	return (tl);
}

t_tablist	*ft_rotatecostdown(t_tablist *tl, int posinlb, int pos_under_lb)
{
	int i;

	//posinlb = count_list(tl, 'b') - posinlb;
	pos_under_lb = count_list(tl, 'a') - pos_under_lb;
	//printf("posinlb : %d - pos_under_lb : %d\n", posinlb, pos_under_lb);
	i = 0;
	if (posinlb <= pos_under_lb)
	{
		while (i++ < posinlb)
			tl = fct_rotate_reverse_arg(tl, 'r');
		i = posinlb;
		while (i++ < pos_under_lb)
			tl = fct_rotate_reverse_arg(tl, 'a');
	}
	i = 0;
	if (pos_under_lb < posinlb)
	{
		while (i++ < pos_under_lb)
			tl = fct_rotate_reverse_arg(tl, 'r');
		while (i++ < posinlb)
			tl = fct_rotate_reverse_arg(tl, 'b');
	}
	return (tl);
}

t_tablist	*ft_rotatedownalt(t_tablist *tl, int cost, int len)
{
	t_list	*tmpb;
	int		pos_und;
	int		posinlb;
	int		costall;

	tmpb = tl->lb;
	posinlb = 0;
	costall = len;
	while (tmpb)
	{
		pos_und = ft_findpos(tl, 'a', ft_findsuperior(tl->la, tl->lb->content));
		if (cost == count_list(tl, 'b') - posinlb
			&& count_list(tl, 'b') - posinlb >= count_list(tl, 'a') - pos_und)
			break ;
		if (cost == count_list(tl, 'a') - pos_und
			&& count_list(tl, 'b') - posinlb >= count_list(tl, 'a') - pos_und)
			break ;
		tmpb = tmpb->next;
		posinlb++;
	}
	//printf("posinlb : %d - pos_und : %d\n", posinlb, count_list(tl, 'a') - pos_und);
	tl = ft_rotatecostdown(tl, posinlb, pos_und);
	return (tl);
}
