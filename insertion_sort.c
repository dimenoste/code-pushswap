/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberraho <mehdi.berraho@learner.42.tech    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 23:08:07 by yasmine.aic       #+#    #+#             */
/*   Updated: 2026/03/05 15:20:23 by mberraho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// j'ai vraiment besoin d'expliquer ?
void	sort_two(t_stack *a, t_op_list *ops)
{
	if (a->head->value > a->head->next->value)
		swap(a, ops);
}

void	sort_three(t_stack *a, t_op_list *ops)
{
	long	first;
	long	second;
	long	last;

	// imagine on a first=1, second=3, third=2
	first = a->head->value;
	second = a->head->next->value;
	last = a->tail->value;
	if (first > second && second < last && first < last)
		swap(a, ops);
	else if (first > second && second > last)
	{
		swap(a, ops);
		reverse_rotate(a, ops);
	}
	else if (first > second && first > last)
		rotate(a, ops);
	else if (first < second && second > last && first < last)
	{
		swap(a, ops); // [1,3,2] → sa → [3,1,2]
		rotate(a, ops);
	}
	else if (first < second && second > last)
		reverse_rotate(a, ops); //[2,3,1] → rra → [1,2,3]
}

// on choisit l'element de a qui coute le moins cher a envoyer dans b
// find_cheapest = strategie (qui, ou, combien)
// execute_rotations = on place a et b au bon endroit
// push = on fait enfin le pb au lieu d'en faire 4065545456
static void	push_cheapest_to_b(t_stack *a, t_stack *b, t_op_list *ops)
{
	t_cost	best;

	best = find_cheapest(a, b);
	execute_rotations(a, b, ops, &best);
	push(a, b, ops);
}
// 1) gerer les petits cas direct
// 2) envoyer presque tout dans b intelligemment (b decroissante)
// 3) trier les 3 restants dans a
// 4) reinserer tout depuis b dans a proprement
void	insertion_sort(t_stack *a, t_stack *b, t_op_list *ops)
{
	if (a->length <= 1)
		return ;
	if (a->length == 2)
	{
		sort_two(a, ops);
		return ;
	}
	if (a->length == 3)
	{
		sort_three(a, ops); // petit tri hardcode
		return ;
	}
	add_index_node(a);
	// assign_indices(a);// normalise en 0..n-1 (plus simple a comparer) voir indexing.c
	// on envoie des elements de a vers b tant qu'il en reste plus de 3
	// pourquoi 3 ?
	// parce que trier 3 elements c'est ultra simple et quasi gratuit (max 2 ops)
	// donc au lieu de continuer a calculer des couts compliques,
	// on garde une base petite et facile a trier direct.
	//
	// cette boucle ne trie PAS a.
	// elle fait juste descendre a a 3 elements.
	// les 3 restants peuvent etre dans n'importe quel ordre.
	//
	// c'est pour ca qu'on appelle sort_three juste apres,
	// pour repartir sur une base propre avant de reinserer b.
	while (a->length > 3)
		push_cheapest_to_b(a, b, ops);
	// construit b en ordre decroissant tout le coeur du truc
	sort_three(a, ops); // trie les 3 derniers
	push_all_to_a(a, b, ops);
}
