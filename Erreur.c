/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Erreur.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knavarre <knavarre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:45:59 by knavarre          #+#    #+#             */
/*   Updated: 2024/03/03 13:02:12 by knavarre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	okintokdup(char **str, int i)
{
	int		j;
	long	tmp;

	tmp = ft_atoi(str[i]);
	if (tmp > 2147483647 || tmp < -2147483648)
		return (0);
	j = i + 1;
	while (str[j])
	{
		if (!(ft_strcmp(str[i], str[j])))
			return (0);
		j++;
	}
	return (1);
}

int	isok(char **avs, int i)
{
	int	j;

	while (avs[i])
	{
		j = 0;
		while (avs[i][j])
		{
			if (avs[i][j] == '-')
				j++;
			if (avs[i][j] >= '0' && avs[i][j] <= '9')
			{
				while (avs[i][j] >= '0' && avs[i][j] <= '9')
					j++;
			}
			else
				return (0);
		}
		if (!(okintokdup(avs, i)))
			return (0);
		i++;
	}
	return (1);
}

void	init_stack(char **avs, int i, t_list **li_a)
{
	t_list	*new;
	int		pos;
	int		index;

	new = NULL;
	index = i;
	while (avs[i])
	{
		pos = positionlst(ft_atoi(avs[i]), avs, index);
		new = ft_lstnew(ft_atoi(avs[i]), pos);
		ft_lstadd_back(li_a, new);
		i++;
	}
}

int	is_sorted(t_list **a)
{
	t_list	*tmp;

	if (!*a)
		return (0);
	tmp = *a;
	while (tmp->next != NULL)
	{
		if (tmp->pos > tmp->next->pos)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
