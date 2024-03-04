/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knavarre <knavarre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 18:54:19 by knavarre          #+#    #+#             */
/*   Updated: 2024/03/03 13:02:34 by knavarre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	max(t_list *li)
{
	int		max;
	t_list	*tmp;

	tmp = li;
	max = tmp->pos;
	while (tmp != NULL)
	{
		if (tmp->pos > max)
			max = tmp->pos;
		tmp = tmp->next;
	}
	return (max);
}

int	min(t_list *li)
{
	int		min;
	t_list	*tmp;

	tmp = li;
	min = tmp->pos;
	while (tmp != NULL)
	{
		if (tmp->pos < min)
			min = tmp->pos;
		tmp = tmp->next;
	}
	return (min);
}

int	ft_lstsize(t_list *lst)
{
	int	n;

	n = 0;
	while (lst)
	{
		lst = lst->next;
		n++;
	}
	return (n);
}

t_list	*ft_lstbeforelast(t_list *a, t_list *last)
{
	t_list	*tmp;

	tmp = a;
	while (tmp->next != NULL)
	{
		if (tmp->next->pos == last->pos)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

long	ft_atoi(char *str)
{
	int		i;
	long	neg;
	long	res;

	i = 0;
	res = 0;
	neg = 1;
	if (str[i] == '-')
	{
		neg *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res * neg);
}
