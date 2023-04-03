/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdelaros <wdelaros@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 07:34:35 by wdelaros          #+#    #+#             */
/*   Updated: 2023/03/20 09:43:49 by wdelaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_pile **a, t_pile **b, int bool)
{
	t_pile	*tmp;

	tmp = (*b)->next;
	if ((*a) == NULL)
	{
		(*a) = (*b);
		(*a)->next = NULL;
		(*a)->previous = NULL;
	}
	else
	{
		(*a)->previous = (*b);
		(*b)->next = (*a);
		(*a) = (*a)->previous;
	}
	(*b) = tmp;
	if (ft_pilesize(*b) >= 1)
		(*b)->previous = NULL;
	if (bool)
		write(1, "pa\n", 3);
}

void	pb(t_pile **a, t_pile **b, int bool)
{
	t_pile	*tmp;

	tmp = (*a)->next;
	if ((*b) == NULL)
	{
		(*b) = (*a);
		(*b)->next = NULL;
		(*b)->previous = NULL;
	}
	else
	{
		(*b)->previous = (*a);
		(*a)->next = (*b);
		(*b) = (*b)->previous;
	}
	(*a) = tmp;
	if (ft_pilesize(*a) >= 1)
		(*a)->previous = NULL;
	if (bool)
		write(1, "pb\n", 3);
}
