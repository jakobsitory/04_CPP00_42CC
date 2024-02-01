# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jschott <jschott@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/09 10:31:55 by jschott           #+#    #+#              #
#    Updated: 2024/01/30 10:45:25 by jschott          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = myphonebook

# SOURCES
SRC_PATH =	src/
SRC_FILES = MyPhoneBook.cpp \
			PhoneBook.cpp \
			Contact.cpp
SRCS := $(addprefix $(SRC_PATH), $(SRC_FILES))

# INCLUDES
INCL_PATH =	include/
HDRS = 		Contact.hpp \
			PhoneBook.hpp
INCLDS := $(addprefix $(INCL_PATH), $(HDRS))		

# COMPILATION CMNDS
CC = c++
FT_FLAGS = -Wall -Wextra -Werror -std=c++98 -g -fsanitize=address
INCLUDES = -I $(INCL_PATH)

all: $(NAME)
	@echo "\n\nCompilation finished successfully\nHave fun breaking things\n"

$(NAME): $(SRCS)
	@echo "\n\nCompiling Executable\n"
	$(CC) $(FT_FLAGS) $(INCLUDES) -o $(NAME) $(SRCS)
	@echo "\nExecutable compiled\n\n"

clean:	
	@rm -f $(NAME)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
