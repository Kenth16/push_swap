/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Algorithme100.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knavarre <knavarre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 12:18:03 by knavarre          #+#    #+#             */
/*   Updated: 2024/03/04 19:51:02 by knavarre         ###   ########.fr       */
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

void	check_final(t_list **a, t_list **b, int chunk)
{
	int	compteur;
	int	value;
	int	valeur_top;
	int	valeur_bot;	

	value = chunk;
	while (ft_lstsize(*a) != 0)
	{
		compteur = ft_lstsize(*b) + 1;
		while (compteur > chunk)
			chunk = chunk + value + value;
		valeur_top = check_top(a, chunk);
		valeur_bot = check_bot(a, chunk);
		if (valeur_top <= valeur_bot)
		{
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
		else if (valeur_top > valeur_bot)
		{
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

void	init_algo5plus(t_list **a, t_list **b, int chunk)
{
	check_final(a, b, chunk);
	pa(b, a);
	while (ft_lstsize(*b) != 0)
		reverse_algo(a, b);
	remetbienstp(a);
}


// int	count_deplacement_in_a(t_list *a, t_list *b)
// {
// 	int		compteur;
// 	t_list	*tmp;

// 	compteur = 0;
// 	tmp = a;
// 	while (tmp->next != NULL)
// 	{
// 		if (b->pos > tmp->pos && b->pos < tmp->next->pos)
// 		{
// 			compteur++;
// 			break ;
// 		}
// 		if ((b->pos < a->pos && (b->pos > ft_lstlast(a)->pos
// 					|| (a)->pos == min(a)))
// 			|| (ft_lstlast(a)->pos == max(a)
// 				&& b->pos > ft_lstlast(a)->pos))
// 			break ;
// 		compteur++;
// 		tmp = tmp->next;
// 	}
// 	return (compteur);
// }

// void	reverse_algo(t_list **a, t_list **b)
// {
// 	int	compteur;

// 	compteur = count_deplacement_in_a(*a, *b);
// 	if (compteur == 0)
// 		pa(b, a);
// 	if (compteur > (ft_lstsize(*a) / 2))
// 	{
// 		while (compteur++ != ft_lstsize(*a))
// 			rra(a);
// 	}
// 	else
// 	{
// 		while (compteur-- != 0)
// 			ra(a);
// 	}
// }
