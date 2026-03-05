/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberraho <mehdi.berraho@learner.42.tech    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 18:38:32 by yasmine.aic       #+#    #+#             */
/*   Updated: 2026/03/04 19:06:55 by yasmine.aichi    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "ft_printf.h"
# include <stdio.h>
// a remplacer une fois les pb de valgrind sur le custom printf seront regles
# include <stdlib.h>
# include "ft_stack.h"
# include "ft_parser.h"
# include "ft_algo.h"
# include "ft_printf.h"
# include <unistd.h>

// signature des algos de sort
typedef void						(*run_algo)(t_stack *a, t_stack *b,
							t_op_list *ops);

// === indexing.c ===
void								assign_indices(t_stack *stk);
// === insertion_sort.c ===
void								sort_two(t_stack *a, t_op_list *ops);
void								sort_three(t_stack *a, t_op_list *ops);
void								insertion_sort(t_stack *a, t_stack *b,
										t_op_list *ops);
// === insertion_sort_helpers.c ===
t_node								*get_node_at(t_stack *stk, size_t pos);
size_t								find_min_pos(t_stack *stk);
void								rotate_to_top(t_stack *stk, size_t pos,
										t_op_list *ops);
// === insertion_sort_utils.c ===
size_t								find_max_pos(t_stack *stk);
size_t								find_insert_pos_b(t_stack *b, size_t index);
void								push_all_to_a(t_stack *a, t_stack *b,
										t_op_list *ops);
// === insertion_sort_cost.c ===
t_cost								find_cheapest(t_stack *a, t_stack *b);
void								execute_rotations(t_stack *a, t_stack *b,
										t_op_list *ops, t_cost *c);

//== radix.x ==
void	display_bench(t_op_list *ops, char *strategy, float disorder);
void	slow_radix_sort(t_stack *a, t_stack *b, t_op_list *out, int max_bits);
void	radix_sort(t_stack *a, t_stack *b, t_op_list *out, int max_bits);
int		find_max_bit(unsigned long value);
void	radix_sort_algo(t_stack *a, t_stack *b, t_op_list *ops);
// utils sort
void								print_array(int *arr, int len);
void								bubble(int *arr, int len);
void								swap_array(int *a, int *b);
int									*copy_values(t_stack *stk);
int									*init_array(int *arr, int len, int val);
int									*lis(int *arr, int len_arr, int *len_lis);
// size_t find_index(int val, int *arr, int len);
// size_t								find_index(int *sorted, size_t len,
//  										int value);

int									add_index_node(t_stack *stk);
t_bool								is_in_lis(int val, int *arr, int len);
void								add_lis_to_nodes(t_stack *stk);
size_t								find_min_ptr_pos(t_stack *stk,
										t_node **ptr_min);
int									is_sorted_circular(t_stack *stk);
void								algo_lis(void);
void								print_array(int *arr, int len);
int									*copy_values(t_stack *stk);
// medium
void								lis_insertion_algo(t_stack *a, t_stack *b,
										t_op_list *ops);
// === strategy.c ===
t_op_list							*run_algo_simple(t_stack *stk);
t_op_list							*run_algo_medium(t_stack *stk);
t_op_list							*run_algo_complex(t_stack *stk);
t_op_list							*run_algo_adaptive(t_stack *stk);
void								run_strategy(t_output_parsing *output_parser);

#endif
