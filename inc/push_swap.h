/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuba <hmatsuba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 17:33:45 by hmatsuba          #+#    #+#             */
/*   Updated: 2025/02/05 18:25:35 by hmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_h
#define PUSH_SWAP_H

#include "libft.h"
#include<limits.h>
#include<stdlib.h>
#include<unistd.h>

typedef struct s_command{
    int all;
    int ra;
    int rra;
    int rb;
    int rrb;
    int rr;
    int rrr;
} t_command;

typedef struct s_node{
    int data;
    int index;
    t_command command;
    struct s_node *next;
    struct s_node *prev;
} t_node;


#endif