# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ottouti <ottouti@student.42quebec.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/09 18:24:09 by ottouti            #+#    #+#              #
#    Updated: 2023/10/24 16:43:44 by ottouti          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

FILES = ft_memset ft_bzero ft_memcpy ft_memmove ft_memchr \
		ft_memcmp ft_strlen ft_strlcpy ft_strlcat ft_strchr \
		ft_strrchr ft_strnstr ft_strncmp ft_atoi ft_isalpha \
		ft_isdigit ft_isalnum ft_isascii ft_isprint ft_toupper \
		ft_tolower ft_calloc ft_strdup ft_substr ft_strjoin \
		ft_strtrim ft_split ft_itoa ft_strmapi ft_putchar_fd \
		ft_putstr_fd ft_putendl_fd ft_putnbr_fd ft_striteri ft_lstnew \
	  	ft_lstadd_front ft_lstsize ft_lstlast ft_lstadd_back ft_lstdelone \
	  	ft_lstclear ft_lstiter ft_lstmap ft_printf ft_printf_utils \
		get_next_line get_next_line_utils ft_count_words ft_count_file_lines \
		ft_count_file_rows \

SRCS_DIR = ./
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))

OBJS_DIR = ./
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))

.c.o: $(SRCS)
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	$(AR) $@ $^

all: $(NAME)

clean:
	 $(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: all clean fclean re