/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Algorithme.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knavarre <knavarre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 12:30:45 by knavarre          #+#    #+#             */
/*   Updated: 2024/03/04 13:14:39 by knavarre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	remetbienstp(t_list **a)
{
	t_list	*tmp;
	int		compteur;

	compteur = 0;
	tmp = *a;
	while (tmp->next != NULL)
	{
		if (tmp->pos == 1)
			break ;
		compteur++;
		tmp = tmp->next;
	}
	if (compteur > (ft_lstsize(*a) / 2))
	{
		while (compteur++ != ft_lstsize(*a))
			rra(a);
	}
	else
	{
		while (compteur-- != 0)
			ra(a);
	}
}

void	init_algo3(t_list **l)
{
	if (ft_lstsize(*l) == 3)
	{
		if (((*l)->pos > (*l)->next->pos && (*l)->pos != max(*l))
			|| ((*l)->pos < (*l)->next->next->pos
				&& (*l)->next->pos == max(*l))
			|| ((*l)->pos == max(*l)
				&& (*l)->next->pos > (*l)->next->next->pos))
			sa(l);
		if ((*l)->next->pos == max(*l))
			rra(l);
		if ((*l)->pos == max(*l))
			ra(l);
	}
	else
	{
		if ((*l)->pos > (*l)->next->pos)
			sa(l);
	}
}

void	init_algo5(t_list **a, t_list **b)
{
	t_list	*tmp;

	while (ft_lstsize(*a) != 3)
		pb(a, b);
	init_algo3(a);
	while (ft_lstsize(*b) != 0)
	{
		tmp = ft_lstlast(*a);
		if (((*b)->pos > max(*a) && tmp->pos == max(*a))
			|| ((*b)->pos < (*a)->pos && (*b)->pos > tmp->pos)
			|| ((*b)->pos < min(*a) && (*a)->pos == min(*a)))
			pa(b, a);
		else
			ra(a);
	}
	remetbienstp(a);
}
