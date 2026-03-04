/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine.aichi <yasmine.aichi@learner.42.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 18:10:39 by yasmine.aichi     #+#    #+#             */
/*   Updated: 2026/03/02 18:14:23 by yasmine.aichi    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ALGO_H
# define FT_ALGO_H
# include "ft_stack.h"

typedef struct s_cost
{
	size_t	pos_a;
	size_t	pos_b;
	int		cost_a;
	int		cost_b;
}			t_cost;

// === indexing.c ===
void		assign_indices(t_stack *stk);
// === insertion_sort.c ===
void		sort_two(t_stack *a, t_op_list *ops);
void		sort_three(t_stack *a, t_op_list *ops);
void		insertion_sort(t_stack *a, t_stack *b, t_op_list *ops);
// === insertion_sort_helpers.c ===
t_node		*get_node_at(t_stack *stk, size_t pos);
size_t		find_min_pos(t_stack *stk);
void		rotate_to_top(t_stack *stk, size_t pos, t_op_list *ops);
// === insertion_sort_utils.c ===
size_t		find_max_pos(t_stack *stk);
size_t		find_insert_pos_b(t_stack *b, size_t index);
void		push_all_to_a(t_stack *a, t_stack *b, t_op_list *ops);
// === insertion_sort_cost.c ===
t_cost		find_cheapest(t_stack *a, t_stack *b);
void		execute_rotations(t_stack *a, t_stack *b, t_op_list *ops,
				t_cost *c);
// === disorder.c ===
float	compute_disorder(t_stack *a);
//=== radix.c ===
void    slow_radix_sort(t_stack *a, t_stack *b, t_op_list *out, int max_bits);
int    find_max_bit(unsigned long value);
void	radix_sort_algo(t_stack *a, t_stack *b, t_op_list *ops);
void    radix_sort(t_stack *a, t_stack *b, t_op_list *out, int max_bits);
// utils sort
void		print_array(int *arr, int len);
void		bubble(int *arr, int len);
void		swap_array(int *a, int *b);
int			*copy_values(t_stack *stk);
int			*init_array(int *arr, int len, int val);
int			*lis(int *arr, int len_arr, int *len_lis);
// === Algo de mehdi
void		add_index_node(t_stack *stk);
t_bool		is_in_lis(int val, int *arr, int len);
void		add_lis_to_nodes(t_stack *stk);
size_t		find_min_ptr_pos(t_stack *stk, t_node **ptr_min);
int			is_sorted_circular(t_stack *stk);
void		algo_lis(void);
void		print_array(int *arr, int len);
int			*copy_values(t_stack *stk);
#endif // !FT_ALGO_H
