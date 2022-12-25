/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucifer <lucifer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 19:21:24 by mrobaii           #+#    #+#             */
/*   Updated: 2022/12/25 17:20:12 by lucifer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Push_Swap.h"

void	sa(t_node **stack_a, int n)
{
	int		size;
	t_node	*tmp;
	t_node	*head;

	size = ft_lstsize(*stack_a);
	if (size >= 2)
	{
		head = *stack_a;
		tmp = head->next;
		head->next = tmp->next;
		tmp->next = head;
		*stack_a = tmp;
		if (n)
			write(1, "sa\n", 3);
	}
}

// void	sb(t_node **stack_b)
// {
// 	int		size;
// 	t_node	*head;
// 	t_node	*tmp;
// 	size = ft_lstsize(*stack_b);
// 	if (size >= 2)
// 	{
// 		head = *stack_b;
// 		tmp = head->next;
// 		head->next = tmp->next;
// 		tmp->next = head;
// 		*stack_b = tmp;	
// 		write(1, "sb\n", 3);
// 	}
// }

void	pa(t_node **stack_a, t_node **stack_b, int n)
{
	t_node	*head;
	t_node	*tmp;

	if (*stack_b)
	{
		head = *stack_b;
		*stack_b = head->next;
		head->next = *stack_a;
		*stack_a = head;
		if (n)
			write(1, "pa\n", 3);
	}
}

void	pb(t_node **stack_a, t_node **stack_b, int n)
{
	t_node	*head;
	t_node	*tmp;

	if (*stack_a)
	{
		head = *stack_a;
		*stack_a = head->next;
		head->next = *stack_b;
		*stack_b = head;
		if (n)
			write(1, "pb\n", 3);
	}
}

void	ra(t_node **stack_a, int n)
{
	t_node	*head;
	t_node	*last;
	int		size;

	size = ft_lstsize(*stack_a);
	if (size >= 2)
	{
		last = ft_lstlast(*stack_a);
		head = *stack_a;
		*stack_a = head->next;
		last->next = head;
		head->next = NULL;
		if (n)
			write (1, "ra\n", 3);
	}
}

void	rb(t_node **stack_b, int n)
{
	t_node	*head;
	t_node	*last;
	int		size;

	size = ft_lstsize(*stack_b);
	if (size >= 2)
	{
		last = ft_lstlast(*stack_b);
		head = *stack_b;
		*stack_b = head->next;
		last->next = head;
		head->next = NULL;
		if (n)
			write(1, "rb\n", 3);
	}
}
