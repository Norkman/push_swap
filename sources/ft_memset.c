/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <nle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 08:00:44 by nle-bret          #+#    #+#             */
/*   Updated: 2021/11/26 08:00:46 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned long int	i;
	unsigned char		a;
	unsigned char		*arr;

	a = (unsigned char)c;
	arr = s;
	i = 0;
	while (i < n)
	{
		arr[i] = a;
		i++;
	}
	return (s);
}
