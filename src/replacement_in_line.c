/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replacement_in_line.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 10:20:18 by mdelphia          #+#    #+#             */
/*   Updated: 2019/10/24 10:20:20 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_only_varible(t_args *largs_nuw)
{
	size_t	i;
	size_t	j;
	int		flag_variable;

	i = 0;
	while (largs_nuw->args[i])
	{
		j = 0;
		flag_variable = 0;
		while (largs_nuw->args[i][j])
		{
			if (largs_nuw->args[i][j] == '=' && j > 0)
			{
				flag_variable = 1;
				break ;
			}
			j++;
		}
		if (!flag_variable)
			return (0);
		i++;
	}
	return (largs_nuw->flag_dol_variable = 1);
}

void		replacement_in_line(t_dol **ldol, t_args **largs_nuw)
{
	size_t i;

	i = 0;
	if ((*largs_nuw)->args)
	{
		check_only_varible(*largs_nuw);
		while ((*largs_nuw)->args[i])
		{
			tilda(&((*largs_nuw)->args[i]));
			dollar(&((*largs_nuw)->args[i]), ldol, largs_nuw);
			i++;
		}
	}
}
