/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdelaros <wdelaros@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 07:36:53 by wdelaros          #+#    #+#             */
/*   Updated: 2023/03/20 09:43:59 by wdelaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_pile *a, int bool)
{
	int	tmp;
	int	arraytmp;

	while (a->next != NULL)
		a = a->next;
	tmp = a->nbr;
	arraytmp = a->array;
	while (a->previous != NULL)
	{
		a->nbr = a->previous->nbr;
		a->array = a->previous->array;
		a = a->previous;
	}
	a->nbr = tmp;
	a->array = arraytmp;
	if (bool)
		write(1, "rra\n", 4);
}

void	rrb(t_pile *b, int bool)
{
	int	tmp;
	int	arraytmp;

	while (b->next != NULL)
		b = b->next;
	tmp = b->nbr;
	arraytmp = b->array;
	while (b->previous != NULL)
	{
		b->nbr = b->previous->nbr;
		b->array = b->previous->array;
		b = b->previous;
	}
	b->nbr = tmp;
	b->array = arraytmp;
	if (bool)
		write(1, "rrb\n", 4);
}

void	rrr(t_pile *a, t_pile *b)
{
	rra(a, 0);
	rrb(b, 0);
	write(1, "rrr\n", 4);
}
