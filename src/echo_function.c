/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 10:24:50 by mdelphia          #+#    #+#             */
/*   Updated: 2019/10/29 10:24:54 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				echo_function(t_args *largs_nuw)
{
	char	**args;
	size_t	i;

	i = 1;
	args = largs_nuw->args;
	while (args[i])
	{
		ft_putstr(args[i]);
		if (args[i + 1])
			ft_putchar(' ');
		else
			ft_putchar('\n');
		i++;
	}
	return (0);
}
