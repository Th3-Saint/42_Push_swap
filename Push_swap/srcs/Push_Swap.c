/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_Swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucifer <lucifer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 17:38:54 by mrobaii           #+#    #+#             */
/*   Updated: 2022/12/25 17:20:12 by lucifer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Push_Swap.h"

int	ft_strncmp(char *s1, char *s2, int n)
{
	int	i;

	i = 0;
	while (i < n - 1 && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

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
		if (!av[i][0])
			exit(0);
		stack->next = ft_lstadd(ft_atoi(av[i]));
		stack = stack->next;
		i++;
	}
}

int	check_sorted(t_node *stack)
{
	while (stack->next)
	{
		if (stack->num < stack->next->num)
			stack = stack->next;
		else
			return (0);
	}
	return (1);
}
