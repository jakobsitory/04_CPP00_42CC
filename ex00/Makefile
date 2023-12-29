# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jschott <jschott@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/09 10:31:55 by jschott           #+#    #+#              #
#    Updated: 2023/12/18 15:41:39 by jschott          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone

# SOURCES
SRCS = 	megaphone.cpp

# COMPILATION CMNDS
CC = c++
FT_FLAGS = -Wall -Wextra -Werror -std=c++98 -g -fsanitize=address

# COMPILATION FILES
OBJS = $(SRCS:.c=.o)

all: $(NAME)
	@echo "\n\nCompilation finished successfully\nHave fun breaking things\n"

$(NAME): $(SRCS)
	@echo "\n\nCompiling Executable\n"
	$(CC) $(FT_FLAGS) -o $(NAME) $(SRCS)
	@echo "\nExecutable compiled\n\n"

clean:	@rm -f $(SRCS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
