/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_write_environ.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 13:06:56 by mdelphia          #+#    #+#             */
/*   Updated: 2019/10/15 13:06:59 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_namewrite(char *name)
{
	size_t i;

	i = 0;
	while (name[i])
		if (name[i++] == '=')
			return (1);
	return (0);
}

static int	check_flags(char *name)
{
	size_t i;

	i = 0;
	if (name[i++] == '-')
		while (name[i])
		{
			if (name[i] == 'P' || name[i] == 'u')
				return (0);
			i++;
		}
	return (1);
}

void		env_write_environ(t_args *largs_nuw)
{
	size_t i;

	i = 0;
	while (largs_nuw->args[i])
	{
		if (check_namewrite(largs_nuw->args[i]) &&
				check_flags(largs_nuw->args[i - 1]))
			putenv(largs_nuw->args[i]);
		i++;
	}
}
