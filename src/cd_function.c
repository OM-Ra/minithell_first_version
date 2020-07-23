/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_function.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 11:58:15 by mdelphia          #+#    #+#             */
/*   Updated: 2019/10/03 11:58:18 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_flags(char **args)
{
	size_t i;

	i = 0;
	if (args[1] && args[1][i++] == '-')
		while (args[1][i])
		{
			if (args[1][i] != '-' || args[1][i] != 'L' || args[1][i] != 'P' ||
				i > 2)
			{
				ft_putstr_fd("cd: string not in pwd: ", 2);
				ft_putstr_fd(args[1], 2);
				ft_putchar_fd('\n', 2);
				return (1);
			}
			i++;
		}
	return (0);
}

static void	go_pwd_args(void)
{
	char *buf;

	buf = ft_strdup(getenv("OLDPWD"));
	setenv("OLDPWD", getenv("PWD"), 1);
	if ((chdir(buf) == -1))
	{
		setenv("OLDPWD", buf, 1);
		free(buf);
		ft_putstr_fd("cd: no such file or directory: ", 2);
		ft_putstr_fd(buf, 2);
		ft_putchar_fd('\n', 2);
	}
	else
	{
		ft_putstr(buf);
		ft_putchar('\n');
	}
	free(buf);
	buf = getcwd(NULL, 32240);
	setenv("PWD", buf, 1);
	free(buf);
}

static int	minus_args(char **args)
{
	int	flag_minus;

	flag_minus = 0;
	if (args[1] && args[1][0] == '-' && !args[1][1])
		flag_minus = 1;
	else if (args[2] && args[2][0] == '-' && !args[2][1])
		flag_minus = 1;
	if (flag_minus)
		go_pwd_args();
	return (flag_minus);
}

static int	check_and_find_args(char **args)
{
	size_t i;

	i = 0;
	while (args[i + 1])
		i++;
	if (i > 2)
	{
		ft_putstr_fd("cd: many arguments\n", 2);
		return (-1);
	}
	if (check_flags(args))
		return (-1);
	if (minus_args(args))
		return (-1);
	if (args[1] && args[1][0] != '-')
		return (1);
	else
		return (2);
}

int			cd_function(char **args)
{
	char		*new_pos;
	int			num_args;
	char		*buf;

	if ((num_args = check_and_find_args(args)) == -1)
		return (0);
	if (args[num_args][0] != '/')
		new_pos = ft_str3str(getenv("PWD"), "/", args[num_args]);
	else
		new_pos = ft_strdup(args[num_args]);
	if ((chdir(new_pos) == -1))
	{
		ft_putstr_fd("cd: no such file or directory: ", 2);
		ft_putstr_fd(args[num_args], 2);
		ft_putchar_fd('\n', 2);
		return (0);
	}
	setenv("OLDPWD", getenv("PWD"), 1);
	buf = getcwd(NULL, 32240);
	setenv("PWD", buf, 1);
	free(new_pos);
	free(buf);
	return (0);
}
