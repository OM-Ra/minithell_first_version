/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_ldol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 11:06:31 by mdelphia          #+#    #+#             */
/*   Updated: 2019/10/29 11:06:33 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_dol		*free_ldol(t_dol *ldol)
{
	t_dol *buf_ldol;

	if (!ldol)
		return (NULL);
	while (ldol)
	{
		buf_ldol = ldol;
		ldol = ldol->next;
		if (buf_ldol->name)
			free(buf_ldol->name);
		if (buf_ldol->value)
			free(buf_ldol->value);
		free(buf_ldol);
	}
	return (NULL);
}
