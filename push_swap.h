/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knavarre <knavarre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:50:10 by knavarre          #+#    #+#             */
/*   Updated: 2024/03/13 22:55:15 by knavarre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

typedef struct s_list
{
	long			value;
	int				pos;
	struct s_list	*next;
}		t_list;

/******************* Algo + Algo5plus + ReverseAlgo *************************/

void	put_in_order(t_list **a);
void	init_algo3(t_list **l);
void	init_algo5(t_list **a, t_list **b);
void	init_algo5plus(t_list **a, t_list **b, int chunk);
int		check_top(t_list **a, int chunk);
int		check_bot(t_list **a, int chunk);
void	check_cond2(t_list **a, t_list **b, int chunk, int value);
void	check_cond1(t_list **a, t_list **b, int chunk, int value);
void	check_final(t_list **a, t_list **b, int chunk);
void	reverse_algo(t_list **a, t_list **b);
int		nb_move(t_list *li_a, int a);
void	pushpush(t_list **li_a, t_list **li_b, int a, int b);
int		count_a(t_list *a, t_list *b);
int		count_same(t_list *li_a, t_list *li_b, int a, int b);
int		count_total(t_list *a, t_list *b, int *i_a, int *i_b);
void	push_cond1(t_list **li_a, t_list **li_b, int *a, int *b);

/******************************** libft ************************************/

char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *str);
int		ft_count_words(char const *str, char c);
void	write_table(char **tab, char const *s, char c);
char	**ft_split(char const *s, char c);
int		max(t_list *li);
int		min(t_list *li);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstbeforelast(t_list *a, t_list *last);
long	ft_atoi(char *str);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
void	del_front_list(t_list **li);
void	del_back_list(t_list **li);
int		ft_strcmp(char *s1, char *s2);
int		positionlst(long value, char **avs, int i);
void	free_split(char **avs, int i);

/****************************** instruction ***********************************/

void	ft_rotate_inverse(t_list **lst);
void	rra(t_list **lst);
void	rrb(t_list **lst);
void	rrr(t_list **lsta, t_list **lstb);
void	ft_rotate(t_list **lst);
void	ra(t_list **lst);
void	rb(t_list **lst);
void	rr(t_list **lsta, t_list **lstb);
void	swap_list(t_list **lst);
void	sa(t_list **list_a);
void	sb(t_list **list_b);
void	ss(t_list **list_a, t_list **list_b);
void	change_list(t_list **lstsrc, t_list **lstdst);
void	pb(t_list **a, t_list **b);
void	pa(t_list **b, t_list **a);

/******************************** ft_error ************************************/

void	init_stack(char **avs, int i, t_list **li_a, t_list **li_b);
int		isok(char **avs, int i);
int		okintokdup(char **str, int i);
int		is_sorted(t_list **a);

/******************************** main ************************************/

t_list	*ft_lstnew(long value, int placement);
int		main(int ac, char **av);
void	print_list(t_list *li);
void	free_stack(t_list **lst);
void	start(t_list **a, t_list **b);

#endif