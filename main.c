/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knavarre <knavarre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:45:58 by knavarre          #+#    #+#             */
/*   Updated: 2024/03/14 12:00:31 by knavarre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(long value, int placement)
{
	t_list	*s;

	s = (t_list *)malloc(sizeof(t_list));
	if (!s)
		return (NULL);
	s->value = value;
	s->pos = placement;
	s->next = NULL;
	return (s);
}

void	free_stack(t_list **lst)
{
	t_list	*tmp;
	t_list	*next;

	tmp = *lst;
	while (tmp != NULL)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
}

void	start(t_list **a, t_list **b)
{
	int		taille;
	int		chunk;

	if (is_sorted(a))
	{
		taille = ft_lstsize(*a);
		if (taille <= 3)
			init_algo3(a);
		else if (taille <= 5)
			init_algo5(a, b);
		else if (taille > 5 && taille <= 100)
		{
			chunk = taille / 3;
			init_algo5plus(a, b, chunk);
		}
		else if (taille > 100)
		{
			chunk = taille / 5;
			init_algo5plus(a, b, chunk);
		}
	}
}

int	main(int ac, char **av)
{
	t_list	*li_a;
	t_list	*li_b;
	char	**avs;
	int		i;

	li_b = NULL;
	li_a = NULL;
	i = 0;
	if (ac == 2)
		avs = ft_split(av[1], ' ');
	else
	{
		avs = av;
		i++;
	}
	if (isok(avs, i))
		init_stack(avs, i, &li_a, &li_b);
	else
		write(2, "Error\n", 6);
	if (ac == 2)
		free_split(avs, i);
}

// void	print_list(t_list *li)
// {
// 	t_list	*temp;

// 	if (!li)
// 	{
// 		printf("Rien a afficher, la liste est vide\n");
// 		return ;
// 	}
// 	printf("\nIndex :  ");
// 	temp = li;
// 	while (temp != NULL)
// 	{
// 		printf("[%d] ", temp->pos);
// 		temp = temp->next;
// 	}
// 	printf("\n");
// 	printf("\n");
// }