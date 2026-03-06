/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bench_strat.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine.aichi <yasmine.aichi@learner.42.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 16:12:15 by yasmine.aichi     #+#    #+#             */
/*   Updated: 2026/03/06 17:38:41 by yasmine.aichi    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BENCH_STRAT_H
# define FT_BENCH_STRAT_H
# include "ft_parser.h"
# include "ft_stack.h"
// === bench_print.c  && main_strategy.c===
void		display_bench(t_op_list *ops, char *strategy, float disorder);
void		write_disorder_fd(int fd, float disorder);
void		print_bench_ops(t_op_list *ops);
//===bench_print_utils.c===
size_t		count_op(t_op_list *ops, t_op_type type);
void		write_disorder_fd(int fd, float disorder);
void		write_int_fd(int fd, int n);
// === strategy.c ===
t_op_list	*run_algo_simple(t_stack *stk);
t_op_list	*run_algo_medium(t_stack *stk);
t_op_list	*run_algo_complex(t_stack *stk);
t_op_list	*run_algo_adaptive(t_stack *stk);
void		run_strategy(t_output_parsing *output_parser);

#endif // !ft_bench_strat
