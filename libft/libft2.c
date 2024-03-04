/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knavarre <knavarre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:02:37 by knavarre          #+#    #+#             */
/*   Updated: 2024/03/02 19:28:20 by knavarre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!new)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		last = ft_lstlast(*lst);
		last->next = new;
	}
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	new->next = *lst;
	*lst = new;
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	while (tmp)
	{
		if (tmp->next == NULL)
			return (tmp);
		tmp = tmp->next;
	}
	return (tmp);
}

void	del_front_list(t_list **li)
{
	if (!*li)
	{
		printf("Rien a Supprimer, la liste est deja vide.\n");
		return ;
	}
	if ((*li)->next == NULL)
		*li = NULL;
	else
		*li = (*li)->next;
}

void	del_back_list(t_list **li)
{
	t_list	*tmp;

	if (!*li)
	{
		printf("Rien a Supprimer, la liste est deja vide.\n");
		return ;
	}
	if ((*li)->next == NULL)
		*li = NULL;
	else
	{
		tmp = *li;
		while (tmp->next != NULL)
		{
			if (tmp->next->next == NULL)
				tmp->next = NULL;
			else
				tmp = tmp->next;
		}
	}
}
