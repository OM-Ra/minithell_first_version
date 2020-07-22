/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 15:28:00 by mdelphia          #+#    #+#             */
/*   Updated: 2019/10/09 15:28:02 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		check_args(t_args *largs, t_args *largs_nuw, t_dol *ldol)
{
	char **args;

	args = largs_nuw->args;
	if (!args)
		return (0);
	if (!ft_strcmp(args[0], "cd"))
		return (largs_nuw->status = cd_function(args));
	if (!ft_strcmp(args[0], "setenv"))
		return (largs_nuw->status = setenv_function(args));
	if (!ft_strcmp(args[0], "unsetenv"))
		return (largs_nuw->status = unsetenv_function(args));
	if (!ft_strcmp(args[0], "env"))
		return (largs_nuw->status = env_funtion(largs_nuw));
	if (!ft_strcmp(args[0], "echo"))
		return (echo_function(largs_nuw));
	if (!ft_strcmp(args[0], "exit"))
		exit_function(largs, ldol);
	if (largs_nuw->flag_dol_variable)
		return (0);
	return (1);
}
