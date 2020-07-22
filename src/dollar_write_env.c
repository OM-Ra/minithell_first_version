/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_write_env.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 14:42:45 by mdelphia          #+#    #+#             */
/*   Updated: 2019/10/21 14:42:46 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		dollar_write_env(char *name_variable, char *line, size_t *i)
{
	char value[320000];

	dollar_write_str_value(value, line, i);
	setenv(name_variable, value, 1);
}
