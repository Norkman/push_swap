/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <nle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 08:02:40 by nle-bret          #+#    #+#             */
/*   Updated: 2021/11/30 14:00:35 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_dst;
	size_t	len_src;
	size_t	k;

	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	k = 0;
	if (size <= len_dst)
		return (size + len_src);
	while (src[k] != '\0' && k + len_dst < size - 1)
	{
		dst[k + len_dst] = src[k];
		k++;
	}
	dst[k + len_dst] = '\0';
	return (len_src + len_dst);
}
