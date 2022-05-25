/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_Swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrobaii <mrobaii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 17:38:54 by mrobaii           #+#    #+#             */
/*   Updated: 2022/05/25 15:37:59 by mrobaii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_Swap.h"

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	ft_lstsize(t_node *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}

void	ft_put_stack(char **av, t_node *stack, int ac)
{
	int	i;

	i = 2;
	while (i < ac)
	{
		stack->next = ft_lstadd(ft_atoi(av[i]));
		stack = stack->next;
		i++;
	}
}

int	main(int ac, char **av)
{
	t_node	*stack_a;
	t_node	*stack_b;
	t_node	*head;
	int		i;

	i = 2;
	stack_b = NULL;
	if (ac < 2)
	{
		printf("ERROR\n");
		exit(0);
	}
	head = ft_lstadd(ft_atoi(av[1]));
	stack_a = head;
	ft_put_stack(av, head, ac);
	check_double(stack_a);
	indexing(stack_a);
	if (ac <= 4)
		sort_three(&stack_a, ac);
	else if (ac <= 11)
		sort_ten(&stack_a, &stack_b);
	else
		ft_sort_big(&stack_a, &stack_b);
}
