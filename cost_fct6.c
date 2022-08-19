#include "push_swap.h"

t_tablist	*ft_rotatecostdownup(t_tablist *tl, t_data d)
{
	int i;

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
	int i;

	i = 0;
	while (i++ < d.pos)
		tl = fct_rotate_reverse_arg(tl, 'b');
	i = 0;
	while (i++ < d.up_o)
		tl = fct_rotate_arg(tl, 'a');
	return (tl);
 }
