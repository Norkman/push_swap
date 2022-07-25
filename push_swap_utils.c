#include "push_swap.h"

int	ft_howmanyover(t_list *list, int nbr)
{
	t_list	*tmp;
	int		i;

	i = 0;

	tmp = list;
	while (tmp)
	{
		if (nbr < tmp->content)
			i++;
		tmp = tmp->next;
	}
	return (i);
}

int	ft_med_list(t_tablist *tl)
{
	int		nbr;
	int		len;
	t_list	*tmp;

	len = count_list(tl, 'a');
	tmp = tl->la;
	while (tmp)
	{
		nbr = tmp->content;
		printf("num : %d --> %d\n", nbr, ft_howmanyover(tl->la, nbr));
			if (ft_howmanyover(tl->la, nbr) == len / 2
				|| ft_howmanyover(tl->la, nbr) == len / 2)
			{
				return (nbr);
			}
		tmp = tmp->next;
	}
	/*
	i = 0;
	head = tl->la;
	tmpi = head;
	tmpj = head;
	while(tmpi)
	{
		nbr = tmpi->content;
		printf("-- %d",nbr);
		while (tmpj)
		{
			if (nbr > tmpj->content)
				i++;
			printf(" --> %d\n", i);
			tmpj = tmpj->next;
		}
		if (i == count_list(tl, 'a') / 2)
				return(nbr);
		tmpj = head;
		tmpi = tmpi->next;
	}
	*/
	return (0);
}
