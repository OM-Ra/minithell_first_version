/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 11:12:48 by mdelphia          #+#    #+#             */
/*   Updated: 2019/09/26 11:12:52 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	t_args		*largs;

	if (!(largs = largs_new(NULL)))
		return (1);
	minishell(largs);
	return (0);
}
