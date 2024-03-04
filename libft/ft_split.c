/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knavarre <knavarre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:35:47 by knavarre          #+#    #+#             */
/*   Updated: 2024/03/02 19:28:14 by knavarre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	if (ft_strlen(s) < start)
		len = 0;
	else if (ft_strlen(s) < (start + len))
		len = ft_strlen(s) - start;
	str = (char *)malloc(sizeof(*s) * (len + 1));
	if (!str)
		return (0);
	while (i < len)
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}

int	ft_count_words(char const *str, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != c && (str[i + 1] == c || str[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

void	write_table(char **tab, char const *s, char c)
{
	size_t	compteur;
	size_t	i;
	size_t	len_word;

	compteur = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			len_word = 0;
			while (s[i + len_word] != c && s[i + len_word])
			len_word++;
			tab[compteur] = ft_substr(s, i, len_word);
			i = i + len_word;
			compteur++;
		}
	}
}

char	**ft_split(char const *s, char c)
{
	size_t	count;
	char	**tab;

	if (!s)
		return (0);
	count = ft_count_words(s, c) + 1;
	tab = (char **)malloc(sizeof(char *) * count);
	if (!tab)
		return (0);
	write_table(tab, s, c);
	tab[count - 1] = NULL;
	return (tab);
}
