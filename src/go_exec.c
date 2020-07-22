/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 10:29:03 by mdelphia          #+#    #+#             */
/*   Updated: 2019/11/07 10:29:07 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	write_path_name(char *path_name, size_t *i)
{
	char	*path_env;
	size_t	j;

	j = 0;
	if (!(path_env = getenv("PATH")))
		return (1);
	if (!path_env[*i])
		return (1);
	while (path_env[*i])
	{
		if (path_env[*i] == ':')
		{
			(*i)++;
			break ;
		}
		path_name[j++] = path_env[(*i)++];
	}
	path_name[j] = '\0';
	return (0);
}

int			go_exec(t_args *largs_nuw)
{
	char		path_name[320000];
	size_t		i;
	extern char	**environ;

	i = 0;
	while (1)
	{
		if (write_path_name(path_name, &i))
			return (1);
		ft_strcat(path_name, "/");
		ft_strcat(path_name, largs_nuw->args[0]);
		execve(path_name, largs_nuw->args, environ);
	}
}
