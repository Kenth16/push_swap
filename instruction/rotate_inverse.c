/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_inverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knavarre <knavarre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:45:59 by knavarre          #+#    #+#             */
/*   Updated: 2024/03/02 19:27:35 by knavarre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_rotate_inverse(t_list **lst)
{
	t_list	*tmp;
	t_list	*last;

	if (*lst == NULL || (*lst)->next == NULL)
	{
		printf("La liste est trop courte pour un échange.\n");
		return ;
	}
	tmp = *lst;
	last = ft_lstlast(tmp);
	del_back_list(lst);
	ft_lstadd_front(lst, last);
}

void	rra(t_list **lst)
{
	ft_rotate_inverse(lst);
	write(1, "rra\n", 4);
}

void	rrb(t_list **lst)
{
	ft_rotate_inverse(lst);
	write(1, "rrb\n", 4);
}

void	rrr(t_list **lsta, t_list **lstb)
{
	ft_rotate_inverse(lsta);
	ft_rotate_inverse(lstb);
	write(1, "rrr\n", 4);
}
