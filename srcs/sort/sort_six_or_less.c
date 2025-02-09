/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_six_or_less.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: YourName <your.email@example.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 19:41:55 by YourName          #+#    #+#             */
/*   Updated: 2025/02/06 19:55:49 by YourName         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_six_or_less(t_node **stack_a, t_node **stack_b, int size)
{
	int	min_index;
	int	pushed;

	pushed = 0;
	while (size - pushed > 3)
	{
		min_index = find_min_index(*stack_a);
		move_min_to_top(stack_a, min_index);
		pb(stack_a, stack_b);
		pushed++;
	}
	sort_three(stack_a);
	while (*stack_b)
		pa(stack_a, stack_b);
}

int	find_min_index(t_node *stack)
{
	int	min;
	int	min_index;
	int	index;

	min = stack->data;
	min_index = 0;
	index = 0;
	while (stack)
	{
		if (stack->data < min)
		{
			min = stack->data;
			min_index = index;
		}
		stack = stack->next;
		index++;
	}
	return (min_index);
}
void	move_min_to_top(t_node **stack, int min_index)
{
	int	size;

	size = get_stack_size(*stack);
	if (min_index <= size / 2)
	{
		while (min_index--)
			ra(stack);
	}
	else
	{
		while (min_index++ < size)
			rra(stack);
	}
}

int	get_stack_size(t_node *stack)
{
	int size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}