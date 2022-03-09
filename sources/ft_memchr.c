/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <nle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 09:09:37 by nle-bret          #+#    #+#             */
/*   Updated: 2021/11/26 10:45:41 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*tmp;
	unsigned char	c_tmp;

	tmp = (unsigned char *)s;
	c_tmp = c;
	i = 0;
	while (i < n)
	{
		if (*tmp == c_tmp)
			return (tmp);
		i++;
		tmp++;
	}
	return (NULL);
}
