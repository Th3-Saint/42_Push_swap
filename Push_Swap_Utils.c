/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_Swap_Utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrobaii <mrobaii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 19:30:38 by mrobaii           #+#    #+#             */
/*   Updated: 2022/05/28 17:09:27 by mrobaii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_Swap.h"

t_node	*ft_lstlast(t_node *stack)
{
	while (stack)
	{
		if (!stack->next)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

t_node	*ft_lstblast(t_node *stack)
{
	while (stack)
	{
		if (!stack->next->next)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

t_node	*ft_lstadd(int num)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	node->num = num;
	node->next = NULL;
	return (node);
}

int	*sort_stack(t_node *stack)
{
	int	*tab;
	int	size;
	int	i;
	int	j;

	i = 0;
	size = ft_lstsize(stack);
	tab = malloc(sizeof(int) * size);
	while (i < size)
	{
		tab[i++] = stack->num;
		stack = stack->next;
	}
	while (size > 0)
	{
		j = 0;
		while (j < size - 1)
		{
			if (tab[j] > tab[j + 1])
				ft_swap(&tab[j], &tab[j + 1]);
			j++;
		}
		size--;
	}
	return (tab);
}

void	indexing(t_node *stack)
{
	int	*tab;
	int	i;

	i = 0;
	tab = sort_stack(stack);
	while (stack)
	{
		if (stack->num == tab[i])
		{
			stack->num = i;
			i = -1;
			stack = stack->next;
		}
		i++;
	}
	free (tab);
}
