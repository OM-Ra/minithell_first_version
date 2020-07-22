/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_find_dollar.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 13:38:20 by mdelphia          #+#    #+#             */
/*   Updated: 2019/10/29 13:38:23 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	find_environ(char *new_line, char name_var[1024])
{
	char	*value_env;

	if ((value_env = getenv(name_var)))
		if (ft_strcat(new_line, value_env))
			return (1);
	return (0);
}

static int	find_dollar_list(char *new_line, t_dol **ldol, char name_var[1024])
{
	t_dol		*buf_dol;

	if (!(*ldol))
		return (0);
	buf_dol = (*ldol);
	while (buf_dol)
	{
		if (!ft_strcmp(buf_dol->name, name_var))
		{
			ft_strcat(new_line, buf_dol->value);
			return (1);
		}
		buf_dol = buf_dol->next;
	}
	return (0);
}

int			dollar_find_dollar(char new_line[920001], char name_var[1024],
				t_dol **ldol, t_args **largs_nuw)
{
	if (find_environ(new_line, name_var))
		return (1);
	else if (find_dollar_list(new_line, ldol, name_var))
		return (1);
	else if (dollar_special_symbols(new_line, name_var, largs_nuw))
		return (1);
	return (0);
}
