/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <nle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:14:38 by nle-bret          #+#    #+#             */
/*   Updated: 2022/04/08 13:26:48 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list *ft_make_list(int len_list, char **nbr_char)
{
	t_list	*list;
	int	new_content;
	int	i;

	list = NULL;
	i = len_list - 1;
	while (i >= 1)
	{
		new_content = ft_atoi(nbr_char[i]);
		list = add_list(new_content, list);
		i--;
	}
	return (list);
}
