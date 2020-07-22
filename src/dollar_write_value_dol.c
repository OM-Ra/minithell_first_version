/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_write_value_dol.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 15:05:13 by mdelphia          #+#    #+#             */
/*   Updated: 2019/10/21 15:05:15 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			dollar_write_value_dol(t_dol *buf_dol, char *line, size_t *i)
{
	char value[320000];

	dollar_write_str_value(value, line, i);
	buf_dol->value = ft_strdup(value);
}
