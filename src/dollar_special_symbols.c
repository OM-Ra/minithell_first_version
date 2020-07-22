/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_special_symbols.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 14:32:34 by mdelphia          #+#    #+#             */
/*   Updated: 2019/10/24 14:32:36 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		find_ppid(char new_line[920001], char name_var[1024])
{
	char	*buf;

	if (!ft_strcmp(name_var, "PPID"))
	{
		buf = ft_itoa((int)getppid());
		ft_strcat(new_line, buf);
		if (buf)
			free(buf);
		return (1);
	}
	return (0);
}

static int		write_pid(char new_line[920001])
{
	char *buf;

	buf = ft_itoa((int)getpid());
	ft_strcat(new_line, buf);
	if (buf)
		free(buf);
	return (1);
}

static int		find_name(char new_line[920001],
					char name_var[1024], t_args **largs_nuw)
{
	char	*buf;
	t_args	*buf_args;

	buf = NULL;
	buf_args = (*largs_nuw);
	if (!ft_strcmp(name_var, "$"))
		return (write_pid(new_line));
	else if (!ft_strcmp(name_var, "!"))
	{
		while (buf_args && !buf_args->run_cmd)
			buf_args = buf_args->left;
		buf = ft_itoa((int)buf_args->pid);
		ft_strcat(new_line, buf);
		if (buf)
			free(buf);
		return (1);
	}
	else if (find_ppid(new_line, name_var))
		return (1);
	return (0);
}

int				dollar_special_symbols(char new_line[920001],
					char name_var[1024], t_args **largs_nuw)
{
	if (find_name(new_line, name_var, largs_nuw))
		return (1);
	return (0);
}
