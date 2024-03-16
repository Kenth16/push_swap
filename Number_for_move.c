/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Number_for_move.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knavarre <knavarre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:51:13 by knavarre          #+#    #+#             */
/*   Updated: 2024/03/13 16:52:09 by knavarre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	nb_move(t_list *li_a, int a)
{
	int	count;

	count = 0;
	while (a <= (ft_lstsize(li_a) / 2) && a != 0)
	{
		count++;
		a--;
	}
	while (a > (ft_lstsize(li_a) / 2) && a != ft_lstsize(li_a))
	{
		count++;
		a++;
	}
	return (count);
}
