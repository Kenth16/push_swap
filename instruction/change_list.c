/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knavarre <knavarre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:47:32 by knavarre          #+#    #+#             */
/*   Updated: 2024/03/02 19:27:37 by knavarre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	change_list(t_list **lstsrc, t_list **lstdst)
{
	t_list	*tmp;

	tmp = *lstsrc;
	del_front_list(lstsrc);
	ft_lstadd_front(lstdst, tmp);
}

void	pb(t_list **a, t_list **b)
{
	change_list(a, b);
	write(1, "pb\n", 3);
}

void	pa(t_list **b, t_list **a)
{
	change_list(b, a);
	write(1, "pa\n", 3);
}
