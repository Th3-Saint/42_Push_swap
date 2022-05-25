/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrobaii <mrobaii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 16:58:42 by mrobaii           #+#    #+#             */
/*   Updated: 2022/05/25 00:42:39 by mrobaii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_Swap.h"

void	check_double(t_node	*stack)
{
	int	*tab;
	int	size;
	int	i;

	i = 0;
	tab = sort_stack(stack);
	size = ft_lstsize(stack);
	while (i < size - 1)
	{
		if (tab[i] == tab[i + 1])
		{
			free(tab);
			write (1, "ERROR\n", 6);
			exit (0);
		}
		i++;
	}
	free(tab);
}

void	check_degit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (i > 0)
	{
		write(1, "ERROR\n", 6);
		exit(0);
	}
}
