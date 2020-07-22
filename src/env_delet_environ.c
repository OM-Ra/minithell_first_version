/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_delet_environ.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 13:05:09 by mdelphia          #+#    #+#             */
/*   Updated: 2019/10/15 13:05:12 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_unset_name(char *unsetname)
{
	size_t i;

	i = 0;
	while (unsetname[i])
	{
		if (unsetname[i] == '=')
		{
			ft_putstr_fd("env: unsetenv ", 2);
			ft_putstr_fd(unsetname, 2);
			ft_putstr_fd(": Invalid argument", 2);
			ft_putchar_fd('\n', 2);
			return (1);
		}
		i++;
	}
	return (0);
}

int			env_delet_environ(t_envlist *envlist, t_args *largs_nuw)
{
	size_t		i;
	extern char	**environ;

	i = 0;
	if (envlist->i)
	{
		environ = NULL;
		return (0);
	}
	else if (envlist->num_u)
		while (largs_nuw->args[i])
			if (!ft_strcmp(largs_nuw->args[i++], "-u"))
			{
				if (check_unset_name(largs_nuw->args[i]))
					return ((largs_nuw->status = 1));
				unsetenv(largs_nuw->args[i++]);
			}
	return (0);
}
