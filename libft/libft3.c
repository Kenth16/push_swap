/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knavarre <knavarre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 18:40:04 by knavarre          #+#    #+#             */
/*   Updated: 2024/03/02 19:28:22 by knavarre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while (s1[i])
	{
		if (s1[i] == s2[i])
			i++;
		else
			return (1);
	}
	if (s2[i] == '\0')
		return (0);
	return (1);
}

int	positionlst(long value, char **avs, int i)
{
	int	compteur;

	compteur = 1;
	while (avs[i])
	{
		if (value > ft_atoi(avs[i]))
			compteur++;
		i++;
	}
	return (compteur);
}
