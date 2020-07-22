/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_write_new_dol.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 15:55:02 by mdelphia          #+#    #+#             */
/*   Updated: 2019/10/21 15:55:06 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			dollar_write_new_dol(char *name_variable, char *line,
					size_t *i, t_dol **ldol)
{
	char	value[320000];
	t_dol	*buf_dol;

	dollar_write_str_value(value, line, i);
	dollar_new(ldol);
	buf_dol = (*ldol);
	while (buf_dol && buf_dol->next)
		buf_dol = buf_dol->next;
	buf_dol->name = ft_strdup(name_variable);
	buf_dol->value = ft_strdup(value);
}
