/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knavarre <knavarre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:36:33 by knavarre          #+#    #+#             */
/*   Updated: 2024/03/14 12:00:26 by knavarre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int main(int ac, char **av)
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
