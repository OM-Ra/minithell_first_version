/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_find_executable_file.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 13:43:15 by mdelphia          #+#    #+#             */
/*   Updated: 2019/10/17 13:43:19 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_name_equally(char *name)
{
	size_t i;

	i = 0;
	while (name[i])
		if (name[i++] == '=')
			return (1);
	return (0);
}

static int	chaeck_name_pu(char *name)
{
	size_t i;

	i = 1;
	while (name[i])
	{
		if (name[i] == 'P' || name[i] == 'u')
			return (1);
		i++;
	}
	return (0);
}

static int	check_name_i(char *name)
{
	size_t i;

	i = 0;
	if (name[0] == '-')
		while (name[i])
			if (name[i++] == 'i')
				return (1);
	return (0);
}

void		env_find_executable_file(t_envlist *envlist, t_args *largs_nuw)
{
	size_t	i;
	char	*bufname;

	i = 1;
	while (largs_nuw->args[i])
	{
		bufname = largs_nuw->args[i];
		if (bufname[0] == '-' && chaeck_name_pu(bufname))
			i += 2;
		else if (check_name_equally(bufname) || check_name_i(bufname))
			i++;
		else
		{
			envlist->line_as = i;
			break ;
		}
	}
}
