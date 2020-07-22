/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 11:11:39 by mdelphia          #+#    #+#             */
/*   Updated: 2019/09/26 11:11:42 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	error_execvp(char *args)
{
	ft_putstr_fd("minishell: command not found: ", 2);
	ft_putstr_fd(args, 2);
	ft_putchar_fd('\n', 2);
	exit(0);
}

static void	go_funktions(pid_t pid, t_args *largs_nuw)
{
	if (pid == -1)
		error_execvp(largs_nuw->args[0]);
	else if (!pid)
	{
		if (go_exec(largs_nuw))
			error_execvp(largs_nuw->args[0]);
	}
	else if (pid > 0)
		waitpid(pid, &(largs_nuw->status), WUNTRACED);
	largs_nuw->pid = (pid == -2) ? 0 : pid;
}

void		minishell(t_args *largs)
{
	pid_t	pid;
	t_args	*largs_nuw;
	t_dol	*ldol;

	ldol = NULL;
	write_shell();
	while (1)
	{
		ft_putstr(getenv("PS1"));
		if (!(largs = pars_args(&largs, &ldol)))
			exit(1);
		largs_nuw = largs;
		while (1)
		{
			pid = -2;
			largs_nuw = last_run_largs(largs_nuw);
			if (largs_nuw->run_cmd)
				break ;
			if (check_args(largs, largs_nuw, ldol))
				pid = fork();
			largs_nuw->run_cmd = 1;
			go_funktions(pid, largs_nuw);
		}
	}
}
