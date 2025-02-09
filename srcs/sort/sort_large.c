/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: YourName <your.email@example.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 12:53:53 by YourName          #+#    #+#             */
/*   Updated: 2025/02/09 15:26:09 by YourName         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h> //////////////////////////////////////////////

void	sort_large(t_node **stack_a, t_node **stack_b, int size)
{
	int	pivot;
	int	pushed;

	if (size <= 1)
		return ;
	pivot = find_pivot(*stack_a, size);
	printf("pivot:%d\n", pivot);
	pushed = push_lower_pivot(stack_a, stack_b, pivot);
	printf(" ok");
	move_b_to_a_sorted(stack_a, stack_b, pushed);
	if (pushed > 1)
		sort_large(stack_b, stack_a, pushed);
	// push_a_to_b(stack_a, stack_b, size - pushed);
}

int	find_pivot(t_node *stack, int size)
{
	int		first;
	int		m;
	int		l;
	int		i;
	t_node	*mid;
	t_node	*last;

	first = stack->data;
	mid = stack;
	i = 0;
	while (i++ < size / 2)
		mid = mid->next;
	last = mid;
	while (last->next)
		last = last->next;
	m = mid->data;
	l = last->data;
	if ((first > m && first < l) || (first < m && first > l))
		return (first);
	else if ((m > first && m < l) || (m < first && m > l))
		return (m);
	else
	{
		return (l);
	}
}

int	push_lower_pivot(t_node **stack_a, t_node **stack_b, int pivot)
{
	int	count;
	int	original_size;
	int	i;

	count = 0;
	i = 0;
	original_size = get_stack_size(*stack_a);
	while (i < original_size)
	{
        if(!*stack_a)
            break;
		if ((*stack_a)->data < pivot)
		{
			pb(stack_a, stack_b);
			*stack_a = (*stack_a)->next;
			count++;
		}
		else
		{
			ra(stack_a);
		}
		i++;
	}
	return (count);
}

void	move_b_to_a_sorted(t_node **stack_a, t_node **stack_b, int count)
{
	int	i;
	int	min_index;

	i = 0;
	while (i < count)
	{
		min_index = find_min_index(*stack_b);
		move_min_to_top(stack_b, min_index);
		pa(stack_a, stack_b);
		// if (get_stack_size(*stack_a) > 1
		// 	&& (*stack_a)->data > (*stack_a)->next->data)
		// 	ra(stack_a);
		i++;
	}
}

void	push_a_to_b(t_node **stack_a, t_node **stack_b, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		pb(stack_a, stack_b);
		i++;
	}
}
