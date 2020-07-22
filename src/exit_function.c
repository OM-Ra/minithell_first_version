/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 12:00:40 by mdelphia          #+#    #+#             */
/*   Updated: 2019/10/03 12:00:43 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exit_function(t_args *largs, t_dol *ldol)
{
	free_ldol(ldol);
	free_largs(largs);
	exit(0);
}
