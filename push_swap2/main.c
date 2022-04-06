/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <nle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 14:06:25 by nle-bret          #+#    #+#             */
/*   Updated: 2022/03/09 14:50:17 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
int	main(int argc, char **argv)
{
	ft_printf("let's go !\n\n");
	ft_printf("%d\n\n", ft_atoi(argv[1]));
	push_swap(argc, argv);
	return (0);
}
