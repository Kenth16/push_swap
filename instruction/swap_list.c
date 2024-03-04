/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knavarre <knavarre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:48:07 by knavarre          #+#    #+#             */
/*   Updated: 2024/03/02 19:27:44 by knavarre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_list(t_list **lst)
{
	t_list	*tmp;

	if (*lst == NULL || (*lst)->next == NULL)
	{
		printf("La liste est trop courte pour un échange.\n");
		return ;
	}
	tmp = (*lst)->next;
	(*lst)->next = tmp->next;
	tmp->next = *lst;
	*lst = tmp;
}

void	sa(t_list **list_a)
{
	swap_list(list_a);
	write(1, "sa\n", 3);
}

void	sb(t_list **list_b)
{
	swap_list(list_b);
	write(1, "sb\n", 3);
}

void	ss(t_list **list_a, t_list **list_b)
{
	swap_list(list_a);
	swap_list(list_b);
	write(1, "ss\n", 3);
}
