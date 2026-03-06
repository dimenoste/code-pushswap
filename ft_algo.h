/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberraho <mehdi.berraho@learner.42.tech    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 18:10:39 by yasmine.aic       #+#    #+#             */
/*   Updated: 2026/03/05 21:44:15 by mberraho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ALGO_H
# define FT_ALGO_H
# include "ft_parser.h"
# include "ft_stack.h"

typedef struct s_cost
{
	size_t		pos_a;
	size_t		pos_b;
	int			cost_a;
	int			cost_b;
}				t_cost;

// signature des algos de sort
typedef void	(*run_algo)(t_stack *a, t_stack *b, t_op_list *ops);
// === indexing.c ===
void			assign_indices(t_stack *stk);
// === disorder.c ===
float			compute_disorder(t_stack *a);
// === insertion_sort.c ===
void			sort_two(t_stack *a, t_op_list *ops);
void			sort_three(t_stack *a, t_op_list *ops);
void			insertion_sort(t_stack *a, t_stack *b, t_op_list *ops);
// === insertion_sort_helpers.c ===
t_node			*get_node_at(t_stack *stk, size_t pos);
size_t			find_min_pos(t_stack *stk);
void			rotate_to_top(t_stack *stk, size_t pos, t_op_list *ops);
// === insertion_sort_utils.c ===
size_t			find_max_pos(t_stack *stk);
size_t			find_insert_pos_b(t_stack *b, size_t index);
void			push_all_to_a(t_stack *a, t_stack *b, t_op_list *ops);

// == simple.c
void	simple_sort(t_stack *a, t_stack *b, t_op_list *ops);

// === insertion_sort_cost.c ===
t_cost			find_cheapest(t_stack *a, t_stack *b);
void			execute_rotations(t_stack *a, t_stack *b, t_op_list *ops,
					t_cost *c);
void			set_cost_directions(t_cost *c, t_stack *a, t_stack *b);
int				total_cost(t_cost *c);
int				abs_val(int n);

//== radix.x ==

void			slow_radix_sort(t_stack *a, t_stack *b, t_op_list *out,
					int max_bits);
void			radix_sort(t_stack *a, t_stack *b, t_op_list *out,
					int max_bits);
int				find_max_bit(unsigned long value);
void			radix_sort_algo(t_stack *a, t_stack *b, t_op_list *ops);


// === bench_print.c ===
void			display_bench(t_op_list *ops, char *strategy, float disorder);
void			print_bench_ops(t_op_list *ops);


// === array_utils.c ===
int				*init_array(int *arr, int len, int val);
void			print_array(int *arr, int len);

// === sort_array.c ===
void			bubble(int *arr, int len);
void			swap_array(int *a, int *b);
int				*copy_values(t_stack *stk);

// === lis_helpers.c ===
int				*lis(int *arr, int len_arr, int *len_lis);


// === lis_utils.c ===
int	is_in_lis(int val, int *arr, size_t len);
void	mark_lis_nodes(t_stack *stk, int *lis, size_t len);
void	fill_dp(int *arr, int n, int *d, int *p);
int	find_best_index(int *d, int n);
int	*rebuild_lis(int *arr, int *p, int pos, int len);

// === lis.c ===
int	*get_lis(int *arr, int n, size_t *len_lis, size_t *best_pos);
size_t	add_lis_to_nodes(t_stack *stk, size_t *best_pos);

//  === medium_algo.c ===
typedef void	(*rotate_f)(t_stack *stack, t_op_list *ops);
void			add_index_node(t_stack *stk);
size_t			add_lis_to_nodes(t_stack *stk, size_t *best_pos);
// size_t			find_min_ptr_pos(t_stack *stk, t_node **ptr_min);
// int				is_sorted_circular(t_stack *stk);
void			algo_lis(void);
void			print_array(int *arr, int len);
int				*copy_values(t_stack *stk);
t_cost			find_cheapest_non_lis(t_stack *a, t_stack *b);
int				*get_lis(int *arr, int n, size_t *len_lis, size_t *best_pos);
size_t			find_best_lis(t_stack *stk);
void			lis_insertion_algo(t_stack *a, t_stack *b, t_op_list *ops);

// === strategy.c ===
t_op_list		*run_algo_simple(t_stack *stk);
t_op_list		*run_algo_medium(t_stack *stk);
t_op_list		*run_algo_complex(t_stack *stk);
t_op_list		*run_algo_adaptive(t_stack *stk);
void			run_strategy(t_output_parsing *output_parser);

#endif // !FT_ALGO_H
