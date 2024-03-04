/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_testfonction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knavarre <knavarre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 22:08:30 by knavarre          #+#    #+#             */
/*   Updated: 2024/03/04 21:51:19 by knavarre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pushpush(t_list **li_a, t_list **li_b, int a, int b)
{
	int	count;

	count = 0;
	printf("[[========================]]\n");
	printf("||       OPEN PUSHPUSH    ||\n");
	printf("[[========================]]\n");
	while (b <= (ft_lstsize(*li_b) / 2) && b != 0)
	{
		printf("\ncond 1\n");
		if (a < (ft_lstsize(*li_a) / 2) && a != 0)
		{
			rr(li_a, li_b);
			a--;
		}
		else
			rb(li_b);
		b--;
	}
	while (a <= (ft_lstsize(*li_a) / 2) && a != 0)
	{
		ra(li_a);
		a--;
	}
	while (b > (ft_lstsize(*li_b) / 2) && b != ft_lstsize(*li_b))
	{
		printf("\ncond 2\n");
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
}

int	count_a(t_list *a, t_list *b)
{
	int		compteur;
	t_list	*tmp;

	compteur = 0;
	tmp = a;
	if ((b->pos < a->pos && (b->pos > ft_lstlast(a)->pos
				|| (a)->pos == min(a)))
		|| (ft_lstlast(a)->pos == max(a)
			&& b->pos > ft_lstlast(a)->pos))
		return (0);
	while (tmp->next != NULL)
	{
		if ((b->pos > tmp->pos && b->pos < tmp->next->pos)
			|| (tmp->pos == max(a) && b->pos > tmp->pos)
			|| (tmp->next->pos == min(a) && b->pos < tmp->next->pos))
		{
			compteur++;
			break ;
		}
		compteur++;
		tmp = tmp->next;
	}
	printf("[%d]  ", compteur);
	return (compteur);
}

int	count_same(t_list *li_a, t_list *li_b, int a, int b)
{
	int	count;

	count = 0;
	while (b <= (ft_lstsize(li_b) / 2) && b != 0)
	{
		if (a < (ft_lstsize(li_a) / 2) && a != 0)
		{
			a--;
			count++;
		}
		b--;
	}
	while (b > (ft_lstsize(li_b) / 2) && b != ft_lstsize(li_b))
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


int	count_b(t_list *a, t_list *b)
{
	t_list	*tmp;
	int		count;

	tmp = b;
	count = 0;
	if ((b->pos < a->pos && (b->pos > ft_lstlast(a)->pos
				|| (a)->pos == min(a)))
		|| (ft_lstlast(a)->pos == max(a)
			&& b->pos > ft_lstlast(a)->pos))
		return (0);
	while (tmp->next != NULL)
	{
		if ((tmp->pos > a->pos && tmp->pos < a->next->pos)
			|| (a->pos == max(a) && tmp->pos > a->pos)
			|| (a->next->pos == min(a) && tmp->pos < a->next->pos))
		{
			count++;
			break ;
		}
		count++;
		tmp = tmp->next;
	}
	printf("[%d]  ", count);
	return (count);
}

int	count_total(t_list *a, t_list *b, int *i_a, int *i_b)
{
	t_list	*tmp;
	int		count;
	int		new;
	int		index;

	index = 0;
	tmp = b;
	count = 0;
	new = count_a(a, b) + count_b(a, b)
		- count_same(a, b, count_a(a, b), count_b(a, b));
	printf("\nA = [%d]  B = [%d]\n", *i_a, *i_b);
	while (tmp->next != NULL)
	{
		if (count_a(a, tmp) + count_b(a, tmp)
			- count_same(a, b, count_a(a, tmp), count_b(a, tmp)) < new)
		{
			new = count_a(a, tmp) + count_b(a, tmp)
				- count_same(a, b, count_a(a, tmp), count_b(a, tmp));
			*i_a = count_a(a, tmp);
			*i_b = count_b(a, tmp);
			printf("\nA = [%d]  B = [%d]\n", *i_a, *i_b);
			index = count;
		}
		tmp = tmp->next;
		count++;
	}
	return (index);
}

void	reverse_algo(t_list **a, t_list **b)
{
	int	i_total;
	int	i_a;
	int	i_b;

	printf("\n[[========================]]\n");
	printf("||       OK START NOW     ||\n");
	printf("[[========================]]\n");
	i_a = count_a(*a, *b);
	i_b = count_b(*a, *b);
	i_total = count_total(*a, *b, &i_a, &i_b);
	printf("A = [%d]  B = [%d]\n", i_a, i_b);
	printf("TOTAL = [%d] \n", i_total);
	if (i_total == 0)
		pa(b, a);
	else
		pushpush(a, b, i_a, i_b);


	print_list(*a);
	print_list(*b);
}


// count_total(a, b, count_a(a, tmp), count) < *deplacement_total)
// 		{
// 			*deplacement_a = count_a(a, tmp);
// 			*deplacement_total = count_total(a, b, count_a(a, tmp), index);
// 			index = count;