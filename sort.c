/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdelaros <wdelaros@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 09:49:04 by wdelaros          #+#    #+#             */
/*   Updated: 2023/03/20 10:23:37 by wdelaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_1(t_pile **a, t_pile **b, int j)
{
	if (verif_pilea(*a, 1) == 2)
		rra(*a, 1);
	while (ft_pilesize(*a) > 0 && verif_pilea(*a, 0) == 0)
	{
		while (min_bucket(*a, j) != 1.5 && ft_pilesize(*a) > 1)
		{
			while (!min_index_bucket(*a, min_bucket(*a, j), max_bucket(*a, j)) \
			&& (*a)->nbr != min_bucket(*a, j) && (*a)->nbr != max_bucket(*a, j) \
			&& !verif_pilea(*a, 0))
				rra(*a, 1);
			while (min_index_bucket(*a, min_bucket(*a, j), max_bucket(*a, j)) \
			&& (*a)->nbr != min_bucket(*a, j) && (*a)->nbr != max_bucket(*a, j) \
			&& !verif_pilea(*a, 0))
				ra(*a, 1);
			if ((*a)->nbr == min_bucket(*a, j) || \
			(*a)->nbr == max_bucket(*a, j))
				pb(a, b, 1);
		}
		j++;
	}
}

void	sort_2(t_pile **a, t_pile **b, int k, int max)
{
	while (ft_pilesize(*b) > 1)
	{
		k = max_index(*b);
		if (ft_pilesize(*b) != 0)
			max = max_number(*b);
		if ((*b)->next->nbr == max)
			sb(*b, 1);
		else if (k && (*b)->nbr != max)
			rb(*b, 1);
		else if (!k && (*b)->nbr != max)
			rrb(*b, 1);
		else if ((*b)->nbr == max)
			pa(a, b, 1);
	}
}

void	sort_3(t_pile **a, t_pile **b)
{
	if (ft_pilesize(*b) > 0)
		pa(a, b, 1);
	while (verif_number(*a, *b) == 0)
	{
		while (verif_pilea(*a, 0) == 0)
		{
			if (!min_index(*a) && (*a)->nbr != min_number(*a))
				rra(*a, 1);
			else if (min_index(*a) && (*a)->nbr != min_number(*a))
				ra(*a, 1);
			else if ((*a)->nbr == min_number(*a))
				pb(a, b, 1);
		}
		if (ft_pilesize(*b) > 0)
			pa(a, b, 1);
	}
}

void	sort(t_pile **a, t_pile **b)
{
	int	j;

	j = 1;
	if (verif_number(*a, *b) == 0 && ft_pilesize(*a) + ft_pilesize(*b) <= 5)
	{
		if (ft_pilesize(*a) + ft_pilesize(*b) == 2)
			sa(*a, 1);
		else if (ft_pilesize(*a) + ft_pilesize(*b) == 3)
			random3(*a);
		else if ((ft_pilesize(*a) + ft_pilesize(*b) == 5 || ft_pilesize(*a) \
		+ ft_pilesize(*b) == 4) && !verif_pilea(*a, 0))
			random5(a, b);
		return ;
	}
	sort_1(a, b, j);
	sort_2(a, b, 0, 0);
	sort_3(a, b);
}
