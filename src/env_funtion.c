/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_funtion.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 13:02:48 by mdelphia          #+#    #+#             */
/*   Updated: 2019/10/11 13:02:51 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	free_envlist(t_envlist *envlist, int sig)
{
	size_t i;

	i = 0;
	if (!envlist->dirname)
		return (sig);
	while (envlist->dirname[i])
		free(envlist->dirname[i++]);
	free(envlist->dirname);
	return (sig);
}

static void	put_environ(void)
{
	extern char	**environ;
	size_t		i;

	i = 0;
	while (environ[i])
	{
		ft_putstr(environ[i]);
		ft_putchar('\n');
		i++;
	}
}

static void	go_dirname(t_envlist *envlist, t_args *largs_nuw, char *nameproc)
{
	char	*buf;
	size_t	i;

	i = 0;
	buf = largs_nuw->args[envlist->line_as];
	while (envlist->dirname[i])
	{
		if (envlist->dirname)
			largs_nuw->args[envlist->line_as] =
					ft_str3str(envlist->dirname[i++], "/", nameproc);
		if (buf)
			free(buf);
		buf = largs_nuw->args[envlist->line_as];
		if (!(access(buf, 0)))
			execvp(buf, &largs_nuw->args[envlist->line_as]);
	}
}

static void	start_env(t_envlist *envlist, t_args *largs_nuw)
{
	char	nameproc[320001];

	ft_strcpy(nameproc, largs_nuw->args[envlist->line_as]);
	if (!ft_strcmp(largs_nuw->args[envlist->line_as], "env"))
	{
		put_environ();
		exit(free_envlist(envlist, 0));
	}
	if (envlist->dirname)
		go_dirname(envlist, largs_nuw, nameproc);
	else
		execvp(nameproc, &largs_nuw->args[envlist->line_as]);
	ft_putstr_fd("env: ", 2);
	ft_putstr_fd(nameproc, 2);
	ft_putstr_fd(": No such file or directory\n", 2);
	exit(free_envlist(envlist, 127));
}

int			env_funtion(t_args *largs_nuw)
{
	pid_t		pid;
	t_envlist	envlist;

	pid = fork();
	if (pid == -1)
	{
		ft_putstr_fd("env: error fork", 2);
		ft_putchar_fd('\n', 2);
	}
	if (!pid)
	{
		if (check_norm_envlist(&envlist, largs_nuw))
			return (free_envlist(&envlist, 0));
		if (env_delet_environ(&envlist, largs_nuw))
			return (free_envlist(&envlist, 0));
		env_write_environ(largs_nuw);
		env_find_executable_file(&envlist, largs_nuw);
		start_env(&envlist, largs_nuw);
	}
	else
		waitpid(pid, &(largs_nuw->status), WUNTRACED);
	return (0);
}
