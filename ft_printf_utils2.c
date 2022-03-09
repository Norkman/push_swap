/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <nle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 16:27:19 by nle-bret          #+#    #+#             */
/*   Updated: 2022/01/07 16:02:11 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	fct_d(va_list args)
{
	int		v_int;
	char	*str;
	int		len_str;

	v_int = va_arg(args, int);
	str = ft_itoa(v_int);
	ft_putstr_fd(str, 1);
	len_str = ft_strlen(str);
	free(str);
	return (len_str);
}

int	fct_u(va_list args)
{
	int		v_unsint;
	char	*str;
	int		len_str;

	v_unsint = va_arg(args, int);
	str = ft_utoa(v_unsint);
	ft_putstr_fd(str, 1);
	len_str = ft_strlen(str);
	free(str);
	return (len_str);
}

int	fct_perc(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}
