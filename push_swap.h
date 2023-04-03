/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdelaros <wdelaros@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 07:31:34 by wdelaros          #+#    #+#             */
/*   Updated: 2023/03/28 07:46:39 by wdelaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>

typedef struct s_parse
{
	int			*num;
	char		**tmp;
}					t_parse;

typedef struct s_pile
{
	int				nbr;
	int				array;
	struct s_pile	*previous;
	struct s_pile	*next;
}					t_pile;

/*push.c*/
void	pa(t_pile **a, t_pile **b, int bool);
void	pb(t_pile **a, t_pile **b, int bool);

/*swap.c*/
void	sa(t_pile *a, int bool);
void	sb(t_pile *b, int bool);
void	ss(t_pile *a, t_pile *b); /*sa && sb*/

/*rotate.c*/
void	ra(t_pile *a, int bool);
void	rb(t_pile *b, int bool);
void	rr(t_pile *a, t_pile *b); /*ra && rb*/

/*reverse.c*/
void	rra(t_pile *a, int bool);
void	rrb(t_pile *b, int bool);
void	rrr(t_pile *a, t_pile *b);/*rra && rrb*/

/*push_swap.c*/
t_pile	*check_number(t_parse *p, int argc, t_pile **current);
char	**parse(char **argv, int *argc, char **tmp, int i);
char	**parse2(char **argv, char **tmp, int i, int j);
char	**ft_free_null(char **array);

/*exit.c*/
void	ft_exit(t_pile *a, t_pile *current, t_parse *p, int error);

/*min_max.c*/
int		max_index(t_pile *pile);
int		min_index(t_pile *pile);
int		max_number(t_pile *pile);
int		min_number(t_pile *pile);

/*list.c*/
t_pile	*create_node(int num);
int		ft_pilesize(t_pile *pile);

/*random.c*/
void	random3(t_pile *a);
void	random_min(t_pile **a, t_pile **b);
void	random_max(t_pile **a, t_pile **b);
void	random5(t_pile **a, t_pile **b);

/*sort.c*/
void	sort(t_pile **a, t_pile **b);
void	sort_1(t_pile **a, t_pile **b, int j);
void	sort_2(t_pile **a, t_pile **b, int k, int max);
void	sort_3(t_pile **a, t_pile **b);

/*bucket.c*/
void	bucket(t_pile **a, int bnbr, int i);
int		number_bucket(t_pile *a, int nbr, int array);
double	max_bucket(t_pile *a, int bucket);
double	min_bucket(t_pile *a, int bucket);
int		min_index_bucket(t_pile *a, int nbr, int nbrmax);

/*verif.c*/
int		verif_pileb(t_pile *b);
int		verif_pilea(t_pile *a, int bool);
int		verif_number(t_pile *a, t_pile *b);

#endif
