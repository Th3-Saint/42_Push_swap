/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_Swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrobaii <mrobaii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 19:24:03 by mrobaii           #+#    #+#             */
/*   Updated: 2022/05/25 15:42:20 by mrobaii          ###   ########.fr       */
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
void	sa(t_node **stack_a);
void	pa(t_node **stack_a, t_node **stack_b);
void	pb(t_node **stack_a, t_node **stack_b);
void	ra(t_node **stack_a);
void	rb(t_node **stack_b);
void	rra(t_node **stack_a);
void	rrb(t_node **stack_b);
t_node	*ft_lstadd(int num);
int		*sort_stack(t_node *stack);
void	indexing(t_node *stack);
int		chunks_index(t_node *stack, int start, int end);
void	chunks_approximity(t_node **stack_a, int start, int end);
int		get_index(t_node *stack, int number);
void	sort_three(t_node **stack_a, int ac);
int		get_min(t_node *stack_a);
void	sort_ten(t_node **stack_a, t_node **stack_b);
int		get_max(t_node *stack_a);
void	ft_sort_big(t_node **stack_a, t_node **stack_b);
int		ft_atoi(char *str);
void	check_double(t_node	*stack);
void	check_degit(char *str);
void	ft_swap(int *a, int *b);
#endif