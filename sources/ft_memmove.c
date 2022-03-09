/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <nle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 08:01:21 by nle-bret          #+#    #+#             */
/*   Updated: 2021/12/03 17:44:27 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	is_upper(unsigned char *dst2, unsigned char *src2, size_t len)
{
	long int	i;

	i = (long int)len - 1;
	while (i >= 0)
	{		
		dst2[i] = src2[i];
		i--;
	}
}

static void	is_under_egal(unsigned char *dst2, unsigned char *src2, size_t len)
{
	long int	i;

	i = 0;
	while (i < (unsigned int)len)
	{
		dst2[i] = src2[i];
		i++;
	}
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst2;
	unsigned char	*src2;

	if (dst == 0 && src == 0)
		return (NULL);
	dst2 = (unsigned char *)dst;
	src2 = (unsigned char *)src;
	if (dst2 > src2)
		is_upper(dst2, src2, len);
	else
		is_under_egal(dst2, src2, len);
	return (dst);
}
