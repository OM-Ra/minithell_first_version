/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_write_str_value.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 15:07:38 by mdelphia          #+#    #+#             */
/*   Updated: 2019/10/21 15:07:40 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	write_in_hooks(char *value, size_t *j, char *line, size_t *i)
{
	int	num_hooks;

	num_hooks = 0;
	while (line[*i])
	{
		if (line[*i] == '(')
		{
			(*i)++;
			num_hooks++;
		}
		else if (line[*i] == ')')
		{
			(*i)++;
			num_hooks--;
		}
		else
			value[(*j)++] = line[(*i)++];
		if (!num_hooks)
			break ;
	}
}

void		dollar_write_str_value(char *value, char *line, size_t *i)
{
	size_t j;

	j = 0;
	if (line[*i] == '=')
		(*i)++;
	while (line[*i] && !((line[*i] >= 9 && line[*i] <= 13) || line[*i] == 32))
	{
		if (line[(*i)] == '(')
			write_in_hooks(value, &j, line, i);
		else
			value[j++] = line[(*i)++];
	}
	value[j] = '\0';
}
