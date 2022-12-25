/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_Swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrobaii <mrobaii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 19:24:03 by mrobaii           #+#    #+#             */
/*   Updated: 2022/05/29 16:41:31 by mrobaii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct node
{
	struct node	*next;
	int			num;
}	t_node;
int		ft_lstsize(t_node *lst);
t_node	*ft_lstlast(t_node *stack);
t_node	*ft_lstblast(t_node *stack);
void	sa(t_node **stack_a, int n);
void	pa(t_node **stack_a, t_node **stack_b, int n);
void	pb(t_node **stack_a, t_node **stack_b, int n);
void	ra(t_node **stack_a, int n);
void	rb(t_node **stack_b, int n);
void	rra(t_node **stack_a, int n);
void	rrb(t_node **stack_b, int n);
t_node	*ft_lstadd(int num);
int		*sort_stack(t_node *stack);
void	indexing(t_node *stack);
int		chunks_index(t_node *stack, int start, int end);
void	chunks_approximity(t_node **stack_a, int start, int end, int n);
int		get_index(t_node *stack, int number);
void	sort_three(t_node **stack_a, int ac, int n);
int		get_min(t_node *stack_a);
void	sort_ten(t_node **stack_a, t_node **stack_b, int n);
int		get_max(t_node *stack_a);
void	ft_sort_big(t_node **stack_a, t_node **stack_b, int n);
int		ft_atoi(char *str);
void	check_double(t_node	*stack);
void	check_degit(char *str);
void	ft_swap(int *a, int *b);
void	ft_put_stack(char **av, t_node *stack, int ac);
int		ft_strncmp(char *s1, char *s2, int n);
int		check_sorted(t_node *stack);
void	ss(t_node **stack_a, t_node **stack_b);
void	rrr(t_node **stack_a, t_node **stack_b);
#endif