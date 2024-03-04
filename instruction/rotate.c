/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knavarre <knavarre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:44:07 by knavarre          #+#    #+#             */
/*   Updated: 2024/03/02 19:27:42 by knavarre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_rotate(t_list **lst)
{
	t_list	*tmp;

	if (*lst == NULL || (*lst)->next == NULL)
	{
		printf("La liste est trop courte pour un échange.\n");
		return ;
	}
	tmp = *lst;
	*lst = (*lst)->next;
	tmp->next = NULL;
	ft_lstadd_back(lst, tmp);
}

void	ra(t_list **lst)
{
	ft_rotate(lst);
	write(1, "ra\n", 3);
}

void	rb(t_list **lst)
{
	ft_rotate(lst);
	write(1, "rb\n", 3);
}

void	rr(t_list **lsta, t_list **lstb)
{
	ft_rotate(lsta);
	ft_rotate(lstb);
	write(1, "rr\n", 3);
}
