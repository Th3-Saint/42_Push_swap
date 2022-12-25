/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrobaii <mrobaii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 19:16:25 by mrobaii           #+#    #+#             */
/*   Updated: 2022/05/29 16:43:10 by mrobaii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_Swap.h"

void	rra(t_node **stack_a, int n)
{
	t_node	*last;
	t_node	*blast;
	int		size;

	size = ft_lstsize(*stack_a);
	if (size >= 2)
	{
		last = ft_lstlast(*stack_a);
		blast = ft_lstblast(*stack_a);
		blast->next = NULL;
		last->next = *stack_a;
		*stack_a = last;
		if (n)
			write(1, "rra\n", 4);
	}
}

void	rrb(t_node **stack_b, int n)
{
	t_node	*last;
	t_node	*blast;
	int		size;

	size = ft_lstsize(*stack_b);
	if (size >= 2)
	{
		last = ft_lstlast(*stack_b);
		blast = ft_lstblast(*stack_b);
		blast->next = NULL;
		last->next = *stack_b;
		*stack_b = last;
		if (n)
			write(1, "rrb\n", 4);
	}
}

void	ss(t_node **stack_a, t_node **stack_b)
{
	sa(stack_a, 0);
	sa(stack_b, 0);
}

void	rrr(t_node **stack_a, t_node **stack_b)
{
	ra(stack_a, 0);
	rb(stack_b, 0);
}
