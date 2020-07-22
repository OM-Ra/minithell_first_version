/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_norm_envlist.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 14:35:34 by mdelphia          #+#    #+#             */
/*   Updated: 2019/10/11 14:35:36 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_write_flags_ivup(t_envlist *envlist, char *args)
{
	size_t i;

	i = 1;
	if (args[0] == '-')
		while (args[i])
		{
			if (args[i] != 'i' && args[i] != 'u' && args[i] != 'P')
			{
				ft_putstr_fd("env: illegal option -- ", 2);
				ft_putchar_fd(args[i], 2);
				ft_putstr_fd("\nusage: env [-i] [-P utilpath] [-u name]\n"
				"           [name=value ...] [utility [argument ...]]\n", 2);
				return (1);
			}
			else if (args[i] == 'u')
				(envlist->num_u)++;
			else if (args[i] == 'i')
				envlist->i = 1;
			else if (args[i] == 'P')
				(envlist->p_big)++;
			i++;
		}
	return (0);
}

static int	check_ivup(t_envlist *envlist, t_args *largs_nuw)
{
	size_t j;

	j = 1;
	while (largs_nuw->args[j])
	{
		if (check_write_flags_ivup(envlist, largs_nuw->args[j]))
			return (1);
		j++;
	}
	return (0);
}

static int	env_write_pathfind(t_envlist *envlist, t_args *largs_nuw)
{
	size_t i;
	size_t line_as;

	i = 0;
	line_as = 0;
	if (!(envlist->dirname = (char **)malloc(sizeof(char *) *
			(envlist->p_big + 1))))
		return (1);
	while (((int)i < envlist->p_big) && largs_nuw->args[line_as])
	{
		while (largs_nuw->args[line_as])
			if (!ft_strcmp(largs_nuw->args[line_as++], "-P"))
				break ;
		if (largs_nuw->args[line_as])
			if (!(envlist->dirname[i++] = ft_strdup(largs_nuw->args[line_as])))
				return (1);
	}
	envlist->dirname[i] = NULL;
	return (0);
}

int			check_norm_envlist(t_envlist *envlist, t_args *largs_nuw)
{
	envlist->i = 0;
	envlist->p_big = 0;
	envlist->num_u = 0;
	envlist->line_as = 0;
	envlist->dirname = NULL;
	if (check_ivup(envlist, largs_nuw))
		return ((largs_nuw->status = 1));
	if (envlist->p_big)
		if (env_write_pathfind(envlist, largs_nuw))
			return ((largs_nuw->status = 1));
	return (0);
}
