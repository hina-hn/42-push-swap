/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: YourName <your.email@example.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 19:49:52 by YourName          #+#    #+#             */
/*   Updated: 2025/02/06 20:02:12 by YourName         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_h
# define PUSH_SWAP_H

# include "libft.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_command
{
	int				all;
	int				ra;
	int				rra;
	int				rb;
	int				rrb;
	int				rr;
	int				rrr;
}					t_command;

typedef struct s_node
{
	int				data;
	int				index;
	t_command		command;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

/* 操作関数 */
void				sa(t_node **stack_a);
void				sb(t_node **stack_b);
void				ss(t_node **stack_a, t_node **stack_b);
void				pa(t_node **stack_a, t_node **stack_b);
void				pb(t_node **stack_a, t_node **stack_b);
void				ra(t_node **stack_a);
void				rb(t_node **stack_b);
void				rr(t_node **stack_a, t_node **stack_b);
void				rra(t_node **stack_a);
void				rrb(t_node **stack_b);
void				rrr(t_node **stack_a, t_node **stack_b);

/* ヘルパー関数 */
void				print_stack(t_node *stack, char stack_name);
void				add_to_stack(t_node **stack, int value);
void				free_stack(t_node **stack);
void				sort_three(t_node **stack);
void				sort_two(t_node **stack);
void				sort_six_or_less(t_node **stack_a, t_node **stack_b,
						int size);
void				sort_numbers(t_node **stack_a, t_node **stack_b, int size);
int					get_stack_size(t_node *stack);
void				move_min_to_top(t_node **stack, int min_index);
int					find_min_index(t_node *stack);

#endif