/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   For_reverse_algo.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knavarre <knavarre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 22:08:30 by knavarre          #+#    #+#             */
/*   Updated: 2024/03/13 17:46:04 by knavarre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_cond1(t_list **li_a, t_list **li_b, int *a, int *b)
{
	if (*a < (ft_lstsize(*li_a) / 2) && *a != 0)
	{
		rr(li_a, li_b);
		(*a)--;
	}
	else
		rb(li_b);
	(*b)--;
}

void	pushpush(t_list **li_a, t_list **li_b, int a, int b)
{
	while (b <= (ft_lstsize(*li_b) / 2) && b != 0)
		push_cond1(li_a, li_b, &a, &b);
	while (a <= (ft_lstsize(*li_a) / 2) && a != 0)
	{
		ra(li_a);
		a--;
	}
	while (b > (ft_lstsize(*li_b) / 2) && b != ft_lstsize(*li_b))
	{
		if (a > (ft_lstsize(*li_a) / 2) && a != ft_lstsize(*li_a))
		{
			rrr(li_a, li_b);
			a++;
		}
		else
			rrb(li_b);
		b++;
	}
	while (a > (ft_lstsize(*li_a) / 2) && a != ft_lstsize(*li_a))
	{
		rra(li_a);
		a++;
	}
	pa(li_b, li_a);
}

int	count_a(t_list *a, t_list *b)
{
	int	compteur;
	int	min_a;
	int	last;
	int	max_a;

	min_a = min(a);
	max_a = max(a);
	compteur = 0;
	last = ft_lstlast(a)->pos;
	if ((b->pos < a->pos && (b->pos > last || (a)->pos == min_a))
		|| (last == max_a && b->pos > last))
		return (0);
	while (a->next != NULL)
	{
		if ((b->pos > a->pos && b->pos < a->next->pos)
			|| (a->pos == max_a && b->pos > a->pos)
			|| (a->next->pos == min_a && b->pos < a->next->pos))
		{
			compteur++;
			break ;
		}
		compteur++;
		a = a->next;
	}
	return (compteur);
}

int	count_same(t_list *li_a, t_list *li_b, int a, int b)
{
	int	count;
	int	size_b;

	size_b = ft_lstsize(li_b);
	count = 0;
	while (b <= (size_b / 2) && b != 0)
	{
		if (a <= (ft_lstsize(li_a) / 2) && a != 0)
		{
			a--;
			count++;
		}
		b--;
	}
	while (b > (size_b / 2) && b != size_b)
	{
		if (a > (ft_lstsize(li_a) / 2) && a != ft_lstsize(li_a))
		{
			a++;
			count++;
		}
		b++;
	}
	return (count);
}

int	count_total(t_list *a, t_list *b, int *i_a, int *i_b)
{
	t_list	*tmp;
	int		count;
	int		new;
	int		index;
	int		total_moves;

	index = 0;
	tmp = b;
	count = 0;
	new = 1000;
	while (tmp != NULL)
	{
		total_moves = nb_move(a, count_a(a, tmp)) + nb_move(b, count)
			- count_same(a, b, count_a(a, tmp), count);
		if (total_moves < new)
		{
			new = total_moves;
			*i_a = count_a(a, tmp);
			*i_b = count;
			index = count;
		}
		tmp = tmp->next;
		count++;
	}
	return (new);
}
