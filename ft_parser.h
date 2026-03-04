/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine.aichi <yasmine.aichi@learner.42.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 17:50:17 by yasmine.aichi     #+#    #+#             */
/*   Updated: 2026/03/04 16:27:45 by yasmine.aichi    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSER_H
# define FT_PARSER_H
# include "ft_stack.h"

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

// === PARSER UTILS
t_number							ft_patol(char *s);
int									ft_strcmp_space(char *s1, char *s2);
char								*get_strat_selector(char *s);
char								*get_bench_selector(char *s);
const char							*get_state_name(t_enum_state_name enum_name);
void								classify_input(t_context *curr_state,
										t_states *mystates);
int									extract_option_in_state(t_context *currState);
int									extract_bench_in_state(t_context *currState);

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

#endif
