/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 11:28:48 by mdelphia          #+#    #+#             */
/*   Updated: 2019/05/03 11:28:52 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <fcntl.h>
# include "libft.h"
# define BUFF_SIZE 255

typedef struct			s_listgnl
{
	char				buff[BUFF_SIZE + 1];
	size_t				i;
	int					fd_listgnl;
	struct s_listgnl	*next;

}						t_listgnl;

int						get_next_line(const int fd, char **line);

#endif
