/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_lst_push_swap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <nle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 12:02:25 by nle-bret          #+#    #+#             */
/*   Updated: 2022/04/08 13:28:29 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Add a new element to linked list */
t_list	*add_list(int num, t_list *head)
{
    t_list *tmp;
    tmp = (t_list *) malloc(sizeof(t_list));
    tmp->content = num;
    tmp->next = head;
    head = tmp;
	return (head);
}

/* Print all the elements in the linked list */
void	printf_list(t_list *head)
{
    t_list *tmp;
	tmp = head;
   	while (tmp != NULL)
	{
        ft_printf("%d ", tmp->content);
        tmp = tmp->next;
	}
	ft_printf("\n");
}

/* Count the number of list in a linked list */
int	count_list(t_list *head)
{
    int cnt = 0;
    t_list *tmp; 
	tmp = head;
    while ( tmp != NULL)
	{
        cnt++;
        tmp = tmp->next;
    }
	return(cnt);
}

/* Remove the first element from a linked list */
t_list	*remove_list(int num, t_list *head)
{
    t_list *tmp = head;
	head = NULL;

	return(head);
}

void	free_list(t_list *head)
{
   t_list *tmp;

   while (head != NULL)
    {
       tmp = head;
       head = head->next;
       free(tmp);
    }

}
