# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/07 14:45:49 by mdelphia          #+#    #+#              #
#    Updated: 2019/09/07 14:45:51 by mdelphia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

WAY_LIB = ./libft/

LIB = $(WAY_LIB)libft.a

FILE_SRC = main.c minishell.c get_next_line.c largs_new.c pars_args.c \
			free_largs.c mllc_args.c last_run_largs.c tilda.c cd_function.c \
			exit_function.c setenv_function.c unsetenv_function.c \
			free_ldol.c check_args.c write_shell.c env_funtion.c \
			check_norm_envlist.c env_delet_environ.c env_write_environ.c \
			env_find_executable_file.c replacement_in_line.c dollar.c \
			dollar_change.c dollar_new.c dollar_write_env.c \
			dollar_write_new_dol.c dollar_write_str_value.c dollar_write_value.c \
			dollar_write_value_dol.c dollar_special_symbols.c echo_function.c \
			dollar_find_dollar.c go_exec.c

SRC = ./src/

INC = ./include/

FILE_C = $(addprefix $(SRC), $(FILE_SRC))

FILE_O = $(FILE_SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

HED = -I $(INC) -I $(WAY_LIB)

GCC_O = gcc -o $(NAME) $(FILE_O) $(LIB)

all: $(NAME)

$(NAME): $(LIB) $(FILE_O)
	$(GCC_O)

%.o: $(SRC)%.c
	gcc -o $@ -c $< $(FLAGS) $(HED)

$(LIB):
	make -C $(WAY_LIB)

clean:
	make clean -C $(WAY_LIB)
	rm -f $(FILE_O)

fclean: clean
	make fclean -C $(WAY_LIB)
	rm -f $(NAME)

re: fclean all
