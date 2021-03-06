/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <nle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 12:29:56 by nle-bret          #+#    #+#             */
/*   Updated: 2022/04/05 16:22:28 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(int content)
{
	t_list	*chain;

	chain = (t_list *)malloc(sizeof(*chain));
	if (chain == NULL)
		return (NULL);
	chain->content = content;
	chain->next = NULL;
	return (chain);
}
