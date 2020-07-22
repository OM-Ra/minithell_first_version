/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_run_largs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 11:23:22 by mdelphia          #+#    #+#             */
/*   Updated: 2019/10/01 11:23:23 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_args	*last_run_largs(t_args *largs)
{
	t_args *largs_last;

	largs_last = largs;
	while (largs_last->right && largs_last->run_cmd)
		largs_last = largs_last->right;
	return (largs_last);
}
