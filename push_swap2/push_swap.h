/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <nle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 13:42:09 by nle-bret          #+#    #+#             */
/*   Updated: 2022/04/08 13:16:16 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "sources/libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

t_list	*ft_make_list(int len_list, char **nbr_char);
t_list	*add_list(int num, t_list *head);
void	printf_list(t_list *head);
int		count_list(t_list *head);
t_list	*remove_list(int num, t_list *head);
void	lst_printf(t_list *list);
void	free_list(t_list *head);
int		push_swap(int argc, char **argv);
void	fct_sa(int *la);
void	fct_sb(int *lb);
void	fct_ss(int *la, int *lb);
void	fct_pa(int *la, int *lb);
void	fct_pb(int *la, int *lb);

#endif
