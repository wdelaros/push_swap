/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdelaros <wdelaros@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 07:35:58 by wdelaros          #+#    #+#             */
/*   Updated: 2023/03/20 09:44:15 by wdelaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_pile *a, int bool)
{
	int	tmp;
	int	arraytmp;

	tmp = a->nbr;
	arraytmp = a->array;
	while (a->next != NULL)
	{
		a->nbr = a->next->nbr;
		a->array = a->next->array;
		a = a->next;
	}
	a->nbr = tmp;
	a->array = arraytmp;
	if (bool)
		write(1, "ra\n", 3);
}

void	rb(t_pile *b, int bool)
{
	int	tmp;
	int	arraytmp;

	tmp = b->nbr;
	arraytmp = b->array;
	while (b->next != NULL)
	{
		b->nbr = b->next->nbr;
		b->array = b->next->array;
		b = b->next;
	}
	b->nbr = tmp;
	b->array = arraytmp;
	if (bool)
		write(1, "rb\n", 3);
}

void	rr(t_pile *a, t_pile *b)
{
	ra(a, 0);
	rb(b, 0);
	write(1, "rr\n", 3);
}
