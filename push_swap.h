/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberraho <mehdi.berraho@learner.42.tech    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 18:38:32 by yasmine.aic       #+#    #+#             */
/*   Updated: 2026/03/04 17:10:55 by mberraho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "ft_printf.h"
# include <stdio.h>
// a remplacer une fois les pb de valgrind sur le custom printf seront regles
# include <stdlib.h>
# include <unistd.h>

typedef struct implement_handlers	t_states;
typedef enum state_name				t_enum_state_name;
typedef struct s_interface			t_state_interface;
typedef struct s_stack				t_stack;
typedef struct s_ctx				t_context;

//////////STATE MACHINE FOR PARSING///////////
typedef enum state_name
{
	InStart,
	InDash,
	InOption,
	InSpace,
	InInvalid,
	InNumber,
	InSuccess
}									t_enum_state_name;

typedef struct s_result_parsing
{
	t_enum_state_name				name_state;
	char							*option_found;
	char							*bench_found;
	t_stack							*stack_a;
}									t_output_parsing;

/*to avoid passing to many arguments
as function parameters because of the norme */
typedef struct validate_args_inner_loop
{
	t_context						*ptr_parser;
	t_states						*mystates;
	t_output_parsing				*output;
}									t_vars_pars_loop;

// 1) Context
typedef struct s_ctx
{
	t_state_interface				*interface;
	t_enum_state_name				name_state;
	char							*mystring;
	char							*addr_first_dash;
	char							*start_number;
	int								nber_digits;
	char							*option_found;
	int								candidate_number;
	char							*bench_found;
	int								nber_dash;
	t_stack							*stack_a;
}									t_context;

// initialize the struct parser
void								init_parser_arg(t_states *mystates,
										t_context *ptr_parser, char *s,
										t_stack *stk);
int									validate_args(int argc, char *argv[],
										t_output_parsing *output);
t_output_parsing					*run_parser(int argc, char *argv[]);

// 2) State Interface
typedef struct s_interface
{
	void							(*handler_letter)(t_context *,
									t_states *mystates);
	void							(*handler_space)(t_context *,
									t_states *mystates);
	void							(*handler_digit)(t_context *,
									t_states *mystates);
	void							(*handler_dash)(t_context *,
									t_states *mystates);
	void							(*handler_other)(t_context *,
									t_states *mystates);
	void							(*handler_end)(t_context *,
									t_states *mystates);
}									t_state_interface;

// 3) struct to initialize the implemtations of
// the reactions to events (piointer of function that implement the handlers)
typedef struct implement_handlers
{
	t_state_interface				*ptr_in_start_state;
	t_state_interface				*ptr_in_dash_state;
	t_state_interface				*ptr_in_option_state;
	t_state_interface				*ptr_in_space_state;
	t_state_interface				*ptr_in_invalid_state;
	t_state_interface				*ptr_in_number_state;
	t_state_interface				*ptr_in_success_state;
}									t_states;

// iniatilize the implementations of the interfaces
t_state_interface					*init_start_state(void);
t_state_interface					*init_dash_state(void);
t_state_interface					*init_space_state(void);
t_state_interface					*init_option_state(void);
t_state_interface					*init_number_state(void);
t_state_interface					*init_invalid_state(void);
t_state_interface					*init_success_state(void);
t_states							*init_states(void);
void								free_mystates(t_states *mystates);

// delarations of implementations for InStart
void								letter_when_in_start(t_context *currState,
										t_states *mystates);
void								space_when_in_start(t_context *currState,
										t_states *mystates);
void								digit_when_in_start(t_context *currState,
										t_states *mystates);
void								dash_when_in_start(t_context *currState,
										t_states *mystates);
void								other_when_in_start(t_context *currState,
										t_states *mystates);
void								end_when_in_start(t_context *currState,
										t_states *mystates);
// delarations of implementations for InDash
void								letter_when_in_dash(t_context *currState,
										t_states *mystates);
void								space_when_in_dash(t_context *currState,
										t_states *mystates);
void								digit_when_in_dash(t_context *currState,
										t_states *mystates);
void								dash_when_in_dash(t_context *currState,
										t_states *mystates);
void								other_when_in_dash(t_context *currState,
										t_states *mystates);
void								end_when_in_dash(t_context *currState,
										t_states *mystates);
// delarations of implementations for InOption
void								letter_when_in_option(t_context *currState,
										t_states *mystates);
void								space_when_in_option(t_context *currState,
										t_states *mystates);
void								digit_when_in_option(t_context *currState,
										t_states *mystates);
void								dash_when_in_option(t_context *currState,
										t_states *mystates);
void								other_when_in_option(t_context *currState,
										t_states *mystates);
void								end_when_in_option(t_context *currState,
										t_states *mystates);
// delarations of implementations for InSpace
void								letter_when_in_space(t_context *currState,
										t_states *mystates);
void								space_when_in_space(t_context *currState,
										t_states *mystates);
void								digit_when_in_space(t_context *currState,
										t_states *mystates);
void								dash_when_in_space(t_context *currState,
										t_states *mystates);
void								other_when_in_space(t_context *currState,
										t_states *mystates);
void								end_when_in_space(t_context *currState,
										t_states *mystates);
// delarations of implementations for InInvalid(
void								stay_in_invalid(t_context *currState,
										t_states *mystates);

// delarations of implementations for InNumber
void								letter_when_in_number(t_context *currState,
										t_states *mystates);
void								space_when_in_number(t_context *currState,
										t_states *mystates);
void								digit_when_in_number(t_context *currState,
										t_states *mystates);
void								dash_when_in_number(t_context *currState,
										t_states *mystates);
void								other_when_in_number(t_context *currState,
										t_states *mystates);
void								end_when_in_number(t_context *currState,
										t_states *mystates);

// 4) Transitions functions
// transitions
void								toin_start_state(t_context *currState,
										t_states *mystates);
void								toin_dash_state(t_context *currState,
										t_states *mystates);
void								toin_option_state(t_context *currState,
										t_states *mystates);
void								toin_space_state(t_context *currState,
										t_states *mystates);
void								toin_invalid_state(t_context *currState,
										t_states *mystates);
void								toin_number_state(t_context *currState,
										t_states *mystates);
void								to_end_success(t_context *currState,
										t_states *mystates);

//
///////////UTILS FOR PARSING/////////
typedef struct vars_ft_patol
{
	int								max;
	int								min;
	int								i;
	int								n;
	int								sign;
}									t_vars_ft_patols;

typedef struct nber_struct
{
	int								number;
	int								error;
}									t_number;

t_number							ft_patol(char *s);
int									ft_strcmp_space(char *s1, char *s2);
char								*get_strat_selector(char *s);
char								*get_bench_selector(char *s);
const char							*get_state_name(t_enum_state_name enum_name);
void								classify_input(t_context *curr_state,
										t_states *mystates);
int									extract_option_in_state(t_context *currState);
int									extract_bench_in_state(t_context *currState);
void								clear_output(t_output_parsing **out);
int									validate_output(int argc, char *argv[],
										t_output_parsing *output);

////////////STRUCTURE OF STACK ////
typedef enum e_bool
{
	FALSE,
	TRUE
}									t_bool;
typedef enum e_stack_name
{
	A,
	B
}									t_stack_name;
typedef enum e_op_type
{
	OP_SA,
	OP_SB,
	OP_SS,
	OP_PA,
	OP_PB,
	OP_RA,
	OP_RB,
	OP_RR,
	OP_RRA,
	OP_RRB,
	OP_RRR
}									t_op_type;

typedef struct s_node
{
	int								value;
	size_t							index;
	t_bool							is_lis;
	struct s_node					*next;
	struct s_node					*previous;
}									t_node;

typedef struct s_stack
{
	t_node							*head;
	t_node							*tail;
	size_t							length;
	t_stack_name					name;
}									t_stack;

typedef struct s_op_list
{
	t_op_type						*operations;
	size_t							count;
	size_t							capacity;
}									t_op_list;

/// === stack_init.c file ===
t_node								*new_node(int value);
t_stack								*new_stack(t_stack_name name);
void								clear_stack(t_stack **stk);
// === stack_ops.c file ===
void								stack_add_back(t_stack *stk, t_node *node);
void								stack_add_front(t_stack *stk, t_node *node);
t_node								*stack_pop_front(t_stack *from);
//=== operations.c file ===
void								swap(t_stack *stack, t_op_list *ops);
void								swap_both(t_stack *a, t_stack *b,
										t_op_list *ops);
void								push(t_stack *from, t_stack *to,
										t_op_list *ops);
//=== operations_rotate.c ===
void								rotate(t_stack *stack, t_op_list *ops);
void								rotate_both(t_stack *a, t_stack *b,
										t_op_list *ops);
void								reverse_rotate(t_stack *stack,
										t_op_list *ops);
void								reverse_rotate_both(t_stack *a, t_stack *b,
										t_op_list *ops);
// === operations_list.c file ===
t_op_list							*new_op_list(void);
void								add_operation(t_op_list *list,
										t_op_type op);
void								print_operations(t_op_list *list);
void								clear_op_list(t_op_list **list);
// stack_helpers.c (utils and fast for debugging during algorithms deployment)
t_bool								is_empty_stack(t_stack *stk);
size_t								stack_length(t_stack *stk);
int									stack_top_peek(t_stack *stk);
t_node								*stack_last(t_stack *stk);
t_node								*stack_first(t_stack *stk);
// stack_helpers.c functions
void								print_stack(t_stack *stack,
										const char *name);

void								print_index_stack(t_stack *stack,
										const char *name);
void								print_lis_stack(t_stack *stack,
										const char *name);

int									is_node_unique(t_stack *stk, t_node *node);
int									is_in_order(t_stack *stk);
// === disorder.c ===
float								compute_disorder(t_stack *a);

// === reduce le nb des ops for insertion sort ===
typedef struct s_cost
{
	size_t							pos_a;
	size_t							pos_b;
	int								cost_a;
	int								cost_b;
}									t_cost;

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
