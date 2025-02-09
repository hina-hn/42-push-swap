/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: YourName <your.email@example.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 20:25:13 by YourName          #+#    #+#             */
/*   Updated: 2025/02/06 18:02:20 by YourName         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_node **stack_a)
{
	t_node *last, *second_last;
	if (!(*stack_a) || !(*stack_a)->next)
		return ;
	last = *stack_a;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = *stack_a;
	last->prev = NULL;
	(*stack_a)->prev = last;
	*stack_a = last;
	write(1, "rra\n", 4);
}

void	rrb(t_node **stack_b)
{
	t_node *last, *second_last;
	if (!(*stack_b) || !(*stack_b)->next)
		return ;
	last = *stack_b;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = *stack_b;
	last->prev = NULL;
	(*stack_b)->prev = last;
	*stack_b = last;
	write(1, "rrb\n", 4);
}
void	rrr(t_node **stack_a, t_node **stack_b)
{
	if ((*stack_a) && (*stack_a)->next)
		rra(stack_a);
	if ((*stack_b) && (*stack_b)->next)
		rrb(stack_b);
	write(1, "rrr\n", 4);
}
