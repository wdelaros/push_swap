/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdelaros <wdelaros@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 13:06:44 by wdelaros          #+#    #+#             */
/*   Updated: 2023/03/23 13:30:30 by wdelaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_exit(t_pile *a, t_pile *current, t_parse *p, int error)
{
	if (error == 1)
		write(2, "Error\n", 6);
	if (current)
	{
		while (current->previous != NULL)
		{
			current = current->previous;
			free(current->next);
		}
	}
	if (p)
		if (p->tmp)
			ft_free_null(p->tmp);
	if (p)
		if (p->num)
			free(p->num);
	p = NULL;
	if (a)
		free(a);
	exit (0);
}
