/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdelaros <wdelaros@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 07:33:07 by wdelaros          #+#    #+#             */
/*   Updated: 2023/03/28 07:46:15 by wdelaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**ft_free_null(char **array)
{
	size_t	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (NULL);
}

t_pile	*check_number(t_parse *p, int argc, t_pile **current)
{
	t_pile	*a;
	int		i;
	int		j;

	i = 0;
	p->num[0] = ft_atoi(p->tmp[0]);
	a = create_node(p->num[0]);
	(*current) = a;
	while (++i < argc)
	{
		if (!ft_isnumber(p->tmp[i]) || ft_atoi(p->tmp[i]) == 1.5)
			ft_exit(a, (*current), p, 1);
		j = 0;
		while (j < i && i < argc)
		{
			if (p->num[j] == ft_atoi(p->tmp[i]))
				ft_exit(a, (*current), p, 1);
			j++;
		}
		p->num[i] = ft_atoi(p->tmp[i]);
		(*current)->next = create_node(p->num[i]);
		(*current)->next->previous = (*current);
		(*current) = (*current)->next;
	}
	return (a);
}

char	**parse2(char **argv, char **tmp, int i, int j)
{
	char	*tmp1;
	int		k;

	k = 0;
	while (argv[j])
	{
		k += ft_strlen(argv[j]);
		j++;
	}
	tmp1 = ft_calloc(j + k, sizeof(char));
	k = 0;
	j = 1;
	while (argv[j])
	{
		if (i != 0)
			tmp1[i++] = ' ';
		while (argv[j][k])
			tmp1[i++] = argv[j][k++];
		k = 0;
		j++;
	}
	tmp = ft_split(tmp1, 32);
	free(tmp1);
	return (tmp);
}

char	**parse(char **argv, int *argc, char **tmp, int i)
{
	char	*tmp1;

	if (*argc == 2)
	{
		tmp1 = ft_calloc(ft_strlen(argv[1]) + 1, sizeof(char));
		while (argv[1][i])
		{
			tmp1[i] = argv[1][i];
			i++;
		}
		tmp = ft_split(tmp1, 32);
		free(tmp1);
	}
	else
		tmp = parse2(argv, tmp, i, 1);
	i = 0;
	while (tmp[i])
		i++;
	(*argc) = i;
	return (tmp);
}

int	main(int argc, char *argv[])
{
	t_parse	p;
	t_pile	*a;
	t_pile	*b;
	t_pile	*current;

	if (argc == 1 || (argc == 2 && !argv[1][0]))
		ft_exit(NULL, NULL, NULL, 0);
	p.tmp = parse(argv, &argc, NULL, 0);
	p.num = ft_calloc(argc, sizeof(int));
	if (!ft_isnumber(p.tmp[0]) || ft_atoi(p.tmp[0]) == 1.5)
		ft_exit(NULL, NULL, &p, 1);
	if (argc == 1)
		ft_exit(NULL, NULL, &p, 0);
	current = NULL;
	a = check_number(&p, argc, &current);
	b = NULL;
	if (ft_pilesize(a) > 5)
		bucket(&a, 5, 0);
	sort(&a, &b);
	ft_exit(a, current, &p, 0);
}
