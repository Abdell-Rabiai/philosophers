# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/09 14:24:42 by ahmaymou          #+#    #+#              #
#    Updated: 2023/05/22 17:29:36 by arabiai          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

Color_Off=\033[0m
LIGHTRED=\033[1;31m
LightBlue=\033[1;34m
LightPurple=\033[1;35m
Cyan=\033[0;36m
GREEN = \033[92m

BANNER=\
'██████╗  ██╗  ██╗ ██╗ ██╗      ██████╗  ███████╗  ██████╗  ██████╗  ██╗  ██╗ ███████╗ ██████╗  ███████╗'\
'██╔══██╗ ██║  ██║ ██║ ██║     ██╔═══██╗ ██╔════╝ ██╔═══██╗ ██╔══██╗ ██║  ██║ ██╔════╝ ██╔══██╗ ██╔════╝'\
'██████╔╝ ███████║ ██║ ██║     ██║   ██║ ███████╗ ██║   ██║ ██████╔╝ ███████║ █████╗   ██████╔╝ ███████╗'\
'██╔═══╝  ██╔══██║ ██║ ██║     ██║   ██║ ╚════██║ ██║   ██║ ██╔═══╝  ██╔══██║ ██╔══╝   ██╔══██╗ ╚════██║'\
'██║      ██║  ██║ ██║ ███████╗╚██████╔╝ ███████║ ╚██████╔╝ ██║      ██║  ██║ ███████╗ ██║  ██║ ███████║'\
'╚═╝      ╚═╝  ╚═╝ ╚═╝ ╚══════╝ ╚═════╝  ╚══════╝  ╚═════╝  ╚═╝      ╚═╝  ╚═╝ ╚══════╝ ╚═╝  ╚═╝ ╚══════╝'\
'                                                                                             '                                                    

ft_utils = $(addprefix ft_utils/, ft_atoi.c)

sources = $(addprefix sources/,init_and_parse_b.c philo_main_utils_b.c philo_main_b.c helper_b.c)

SRCS = $(sources) $(ft_utils)

MAIN_SRC = sources/philo_main.c

FLAGS = -Wall -Werror -Wextra -fsanitize=address

HEADER = philo_bonus.h

CC = cc

LIBS = ft_printf/libftprintf.a

OBJ = $(SRCS:.c=.o)

all : banner2 libftprintf $(NAME)

banner2:
	@clear
	@echo "\n"
	@echo "$(LightPurple)"
	@for s in $(BANNER) ; do \
		printf "%s\n" "$$s" ; \
		sleep 0.03 ; \
	done ; \
	echo "$(LIGHTRED)                     By : Abdell-rabiai :) \n$(Color_Off)"

%.o: %.c $(HEADER)
	@printf "$(GREEN) Generating minishell objects... %-33.33s\r" $@
	@$(CC) $(FLAGS) $(READLINE_INC) -c $< -o $@

$(NAME) : $(OBJ) $(HEADER)
	@$(CC) $(FLAGS) $(OBJ) $(LIBS) -o $(NAME)
	@echo "\n\n\t$(Cyan) Enjoooy :)\n $(Color_Off)"

libftprintf :
	@make -C ft_printf/

clean :
	@make clean -C ft_printf
	@rm -rf $(OBJ)

fclean : clean
	@make fclean -C ft_printf
	@rm -rf $(LIBS) $(NAME) $(MAIN_SRC:.c=.o)
	@rm -rf *.dSYM .vscode

re : fclean all

.PHONY : all clean fclean re
