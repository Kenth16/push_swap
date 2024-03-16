/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   For_algo5plus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knavarre <knavarre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 12:18:03 by knavarre          #+#    #+#             */
/*   Updated: 2024/03/13 16:45:57 by knavarre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_top(t_list **a, int chunk)
{
	int		index;
	t_list	*tmp;

	tmp = *a;
	index = 0;
	while (tmp->pos > chunk && index < (ft_lstsize(*a) / 2))
	{
		index++;
		tmp = tmp->next;
	}
	return (index);
}

int	check_bot(t_list **a, int chunk)
{
	int		index;
	t_list	*tmp;

	tmp = ft_lstlast(*a);
	index = 0;
	while (tmp->pos > chunk && index < (ft_lstsize(*a) / 2))
	{
		index++;
		tmp = ft_lstbeforelast(*a, tmp);
	}
	return (index + 1);
}

void	check_cond1(t_list **a, t_list **b, int chunk, int value)
{
	int	valeur_top;

	valeur_top = check_top(a, chunk);
	while (valeur_top-- != 0)
		ra(a);
	if ((*a)->pos < (chunk - value))
	{
		pb(a, b);
		rb(b);
	}
	else
		pb(a, b);
}

void	check_cond2(t_list **a, t_list **b, int chunk, int value)
{
	int	valeur_bot;

	valeur_bot = check_bot(a, chunk);
	while (valeur_bot-- != 0)
		rra(a);
	if ((*a)->pos < (chunk - value))
	{
		pb(a, b);
		rb(b);
	}
	else
		pb(a, b);
}

void	check_final(t_list **a, t_list **b, int chunk)
{
	int	compteur;
	int	value;
	int	valeur_bot;	

	value = chunk;
	while (ft_lstsize(*a) != 3)
	{
		compteur = ft_lstsize(*b) + 1;
		while (compteur > chunk)
			chunk = chunk + value + value;
		valeur_bot = check_bot(a, chunk);
		if (check_top(a, chunk) <= check_bot(a, chunk))
			check_cond1(a, b, chunk, value);
		else if (check_top(a, chunk) > check_bot(a, chunk))
			check_cond2(a, b, chunk, value);
	}
}

// void	check_final(t_list **a, t_list **b, int chunk)
// {
// 	int	compteur;
// 	int	value;
// 	int	valeur_top;
// 	int	valeur_bot;	

// 	value = chunk;
// 	while (ft_lstsize(*a) != 0)
// 	{
// 		compteur = ft_lstsize(*b) + 1;
// 		while (compteur > chunk)
// 			chunk = chunk + value;
// 		valeur_top = check_top(a, chunk);
// 		valeur_bot = check_bot(a, chunk);
// 		if (valeur_top <= valeur_bot)
// 		{
// 			while (valeur_top-- != 0)
// 				ra(a);
// 		}
// 		else if (valeur_top > valeur_bot)
// 		{
// 			while (valeur_bot-- != 0)
// 				rra(a);
// 		}
// 		pb(a, b);
// 	}
// }