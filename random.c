/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdelaros <wdelaros@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 20:35:52 by wdelaros          #+#    #+#             */
/*   Updated: 2023/03/20 09:56:30 by wdelaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	random3(t_pile *a)
{
	if (verif_pilea(a, 0))
		return ;
	if (a->next->next->nbr == max_number(a))
		sa(a, 1);
	else if (a->nbr == max_number(a) && a->next->next->nbr == min_number(a))
	{
		sa(a, 1);
		rra(a, 1);
	}
	else if (a->nbr == max_number(a) && a->next->next->nbr != min_number(a))
		ra(a, 1);
	else if (a->nbr == min_number(a))
	{
		sa(a, 1);
		ra(a, 1);
	}
	else if (a->nbr != max_number(a) && a->next->next->nbr == min_number(a))
		rra(a, 1);
}

void	random_min(t_pile **a, t_pile **b)
{
	if ((*a)->nbr == min_number(*a))
		pb(a, b, 1);
	else
	{
		while (!min_index(*a) && (*a)->nbr != min_number(*a) \
		&& !verif_pilea(*a, 0))
			rra(*a, 1);
		while (min_index(*a) && (*a)->nbr != min_number(*a) \
		&& !verif_pilea(*a, 0))
			ra(*a, 1);
		if (verif_number(*a, *b))
			return ;
		if (!verif_pilea(*a, 0))
			pb(a, b, 1);
	}
}

void	random_max(t_pile **a, t_pile **b)
{
	if ((*a)->nbr == max_number(*a) && !verif_pilea(*a, 0))
		pb(a, b, 1);
	else
	{
		while (!max_index(*a) && (*a)->nbr != max_number(*a) \
		&& !verif_pilea(*a, 0))
			rra(*a, 1);
		while (max_index(*a) && (*a)->nbr != max_number(*a) \
		&& !verif_pilea(*a, 0))
			ra(*a, 1);
		if (verif_number(*a, *b))
			return ;
		if (!verif_pilea(*a, 0))
			pb(a, b, 1);
	}
}

void	random5(t_pile **a, t_pile **b)
{
	if (ft_pilesize(*a) == 5 || ft_pilesize(*a) == 4)
		random_min(a, b);
	if (ft_pilesize(*a) == 4)
		random_max(a, b);
	if (!verif_pilea(*a, 0))
		random3(*a);
	if (ft_pilesize(*b))
		pa(a, b, 1);
	if (ft_pilesize(*b))
	{
		ra(*a, 1);
		pa(a, b, 1);
	}
}
