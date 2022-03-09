/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <nle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 09:17:12 by nle-bret          #+#    #+#             */
/*   Updated: 2021/12/03 17:13:24 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_element;
	t_list	*tmp_lst;

	new_lst = NULL;
	tmp_lst = lst;
	while (tmp_lst)
	{
		new_element = ft_lstnew(f(tmp_lst->content));
		if (new_element == NULL)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_element);
		tmp_lst = tmp_lst->next;
	}
	return (new_lst);
}
